#pragma once
#include <stdbool.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// MouseFunctions関係
////////////////////////////////////////////////////////////////////////////////
/** マウス関係デリゲート関数 */
typedef struct MouseFunctions
{
    /** 回転角ThetaをDegreeで取得する */
    unsigned int (*getThetaDegree)(void);
    /** 回転角ThetaをDegreeで取得する */
    unsigned int (*getPhyDegree)(void);

    /** CPIを取得する */
    unsigned int (*getCpi)(void);

    /** スクロール速度調整係数(大きいほどスクロールがゆっくりになる)を取得する */
    unsigned int (*getScrDiv)(void);

    /** X座標反転モードか否かを取得する */
    bool (*isXInvert)(void);

    /** スクロール反転モードかを取得する */
    bool (*isScrInvert)(void);

    // スクロールモードか否かを取得する */
    bool (*isOnScroll)(void);
    /** スクロールを直行モード(x座標とy座標の大きい側のみを使用し、小さい側を0と扱う)とするか否かを取得する。 */
    bool (*isOrthoScroll)(void);
} MouseFunctions;

/**
 * @brief Mouse設定用関数を外部から設定する
 *
 * @param mouseFunc Mouse関数(デフォルトを使用する場合はNULLを渡す。)
 */
void libMouseSetMouseFunctions(const MouseFunctions *mouseFunc);

////////////////////////////////////////////////////////////////////////////////
// 公開関数
////////////////////////////////////////////////////////////////////////////////
/**
 * @brief CPIの更新を要求する
 *
 */
void libMouseUpdateCpi(void);

////////////////////////////////////////////////////////////////////////////////
// ユーティリティ
////////////////////////////////////////////////////////////////////////////////
/**
 * @brief 度数法をラジアンに変換する
 *
 * @param degree 0..360
 * @return double radian.
 */
double libMouseUtilDegreeToRad(int unsigned degree);
