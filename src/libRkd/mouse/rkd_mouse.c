#include QMK_KEYBOARD_H
#include "rkd_mouse.h"
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// MouseFunctions関係
////////////////////////////////////////////////////////////////////////////////
#define MOUSE_DEFAULT_THETA (90)
#define MOUSE_DEFAULT_PHY (180)

#define MOUSE_DEFAULT_CPI (1500)
#define MOUSE_DEFAULT_MIN_CPI (800)
#define MOUSE_DEFAULT_MAX_CPI (2200)

#define MOUSE_DEFAULT_SCRDIV (60)
#define MOUSE_DEFAULT_MIN_SCRDIV (1)
#define MOUSE_DEFAULT_MAX_SCRDIV (120)

#define MOUSE_DEFAULT_X_INVERT (false)
#define MOUSE_DEFAULT_SCRINV (false)

#define MOUSE_DEFAULT_SCROLL (false)
#define MOUSE_DEFAULT_ORTHO_SCROLL (false)

/** ローカルマウス関数 */
static MouseFunctions _mouseFunctions = {0};

void libMouseSetMouseFunctions(const MouseFunctions *mouseFunc)
{
    if (mouseFunc == NULL)
    {
        memset(&_mouseFunctions, 0x00, sizeof(_mouseFunctions));
    }
    else
    {
        memcpy(&_mouseFunctions, mouseFunc, sizeof(_mouseFunctions));
    }
}

/* 回転角Theta(rad)を取得する */
static double _mouseFuncGetTheta(void)
{
    return libMouseUtilDegreeToRad(
#ifndef MOUSE_FIXED_THETA
        _mouseFunctions.getThetaDegree ? _mouseFunctions.getThetaDegree() : (MOUSE_DEFAULT_THETA)
#else
        MOUSE_FIXED_THETA
#endif
    );
}

/** 回転角Phy(rad)を取得する */
static double _mouseFuncGetPhy(void)
{
    return libMouseUtilDegreeToRad(
#ifndef MOUSE_FIXED_PHY
        _mouseFunctions.getPhyDegree ? _mouseFunctions.getPhyDegree() : (MOUSE_DEFAULT_PHY)
#else
        MOUSE_FIXED_PHY
#endif
    );
}

/** CPIを取得する */
static unsigned int _mouseFuncGetCpi(void)
{
    unsigned int cpi = _mouseFunctions.getCpi ? _mouseFunctions.getCpi() : MOUSE_DEFAULT_CPI;
    if (cpi < MOUSE_DEFAULT_MIN_CPI)
    {
        cpi = MOUSE_DEFAULT_MIN_CPI;
    }
    if (MOUSE_DEFAULT_MAX_CPI < cpi)
    {
        cpi = MOUSE_DEFAULT_MAX_CPI;
    }
    return cpi;
}

/** スクロール速度調整係数を取得する */
static int _mouseFuncGetScrDvi(void)
{
#ifndef MOUSE_FIXED_SCRDIV
    unsigned int scrdiv = _mouseFunctions.getScrDiv ? _mouseFunctions.getScrDiv() : MOUSE_DEFAULT_SCRDIV;
    if (scrdiv < MOUSE_DEFAULT_MIN_SCRDIV)
    {
        scrdiv = MOUSE_DEFAULT_MIN_SCRDIV;
    }
    if (MOUSE_DEFAULT_MAX_SCRDIV < scrdiv)
    {
        scrdiv = MOUSE_DEFAULT_MAX_SCRDIV;
    }
    return scrdiv;
#else
    return MOUSE_FIXED_SCRDIV;
#endif
}

/** X方向反転有無を取得する */
static bool _mouseFuncIsXInvert(void)
{
    return
#ifndef MOUSE_FIXED_INVERT_X
        _mouseFunctions.isXInvert ? _mouseFunctions.isXInvert() : MOUSE_DEFAULT_X_INVERT
#else
        MOUSE_FIXED_INVERT_X
#endif
        ;
}

/** スクロール反転モードか否かを取得する */
static bool _mouseFUncIsScrInvert(void)
{
    return
#ifndef MOUSE_FIXED_INVERT_SCROLL
        _mouseFunctions.isScrInvert ? _mouseFunctions.isScrInvert() : MOUSE_DEFAULT_SCRINV
#else
        MOUSE_FIXED_INVERT_SCROLL
#endif
        ;
}

/** スクロールモードか否かを取得する */
static bool _mouseFuncIsOnScroll(void)
{
    return
#ifdef MOUSE_FIXED_SCROLL_LAYER
        IS_LAYER_ON(MOUSE_FIXED_SCROLL_LAYER)
#else
        _mouseFunctions.isOnScroll ? _mouseFunctions.isOnScroll() : MOUSE_DEFAULT_SCROLL
#endif
            ;
}

/** 直行スクロールか否かを判定する */
static bool _mouseFuncIsOrthScroll(void)
{
    return
#ifndef MOUSE_FIXED_ORTH_SCROLL
        _mouseFunctions.isOrthoScroll ? _mouseFunctions.isOrthoScroll() : MOUSE_DEFAULT_ORTHO_SCROLL
#else
        MOUSE_FIXED_ORTH_SCROLL
#endif
        ;
}

////////////////////////////////////////////////////////////////////////////////
// 公開関数
////////////////////////////////////////////////////////////////////////////////
void libMouseUpdateCpi(void)
{
    pointing_device_set_cpi(_mouseFuncGetCpi());
}

////////////////////////////////////////////////////////////////////////////////
// ユーティリティ
////////////////////////////////////////////////////////////////////////////////
double libMouseUtilDegreeToRad(unsigned int degree)
{
    return (degree % 360) * (M_PI / 180);
}

////////////////////////////////////////////////////////////////////////////////
// マウスイベントHook
////////////////////////////////////////////////////////////////////////////////
report_mouse_t rkd_pointing_device_task_user(report_mouse_t mouse_report)
{
    static int16_t _scr_accm_h = 0;
    static int16_t _scr_accm_v = 0;
    double theta = _mouseFuncGetTheta();
    double phi = _mouseFuncGetPhy();
    int8_t x_rev = +mouse_report.x * cos(theta) + mouse_report.y * cos(phi);
    int8_t y_rev = +mouse_report.x * sin(theta) + mouse_report.y * sin(phi);

    if (_mouseFuncIsXInvert())
    {
        x_rev = -1 * x_rev;
    }
    if (_mouseFuncIsOnScroll())
    {
        int scr_div = _mouseFuncGetScrDvi();
        if (_mouseFuncIsOrthScroll())
        {
            if (abs(x_rev) > abs(y_rev))
            {
                y_rev = 0;
            }
            else
            {
                x_rev = 0;
            }
        }

        _scr_accm_h += x_rev;
        _scr_accm_v += y_rev;
        mouse_report.h = _scr_accm_h / scr_div;
        mouse_report.v = _scr_accm_v / scr_div;
        _scr_accm_h %= scr_div;
        _scr_accm_v %= scr_div;

        if (_mouseFUncIsScrInvert())
        {
            mouse_report.h = -1 * mouse_report.h;
            mouse_report.v = -1 * mouse_report.v;
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    else
    {
        _scr_accm_h = 0;
        _scr_accm_v = 0;
        mouse_report.x = -1 * x_rev;
        mouse_report.y = y_rev;
    }
    return mouse_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
{
    return rkd_pointing_device_task_user(mouse_report);
}