#!/bin/bash
set -Ceux


KB="rkd/rkd07"
MODEL="picot rpi/nogikesu_paw3222 rpi/az1uball rpi/stickpoint"
TARGET="via"
# "default"
TYPE="uf2"

QMK="${HOME}/qmk_firmware"

pushd $(dirname $0)

function step()
{
    local kb=$1
    local t=$2

    qmk compile -kb ${kb} -km ${t}
    FIRM=${kb//\//_}_${t}.${TYPE}
    rm -f ${FIRM}
    mv ${QMK}/${FIRM} ./
}

for t in ${TARGET}
do
    for m in ${MODEL}
    do
        kb=${KB}/${m}
        step ${kb} ${t} &
    done
done

wait

popd
