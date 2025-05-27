#!/bin/bash
set -Ceux


KB="rkd/rkd07"
MODEL="picot rpi/nogikesu"
# "rpi/usakey rpi/az1uball rpi/stickpointv"
TARGET="default via"
TYPE="uf2"

QMK="${HOME}/qmk_firmware"

for t in ${TARGET}
do
    for m in ${MODEL}
    do
        kb=${KB}/${m}
        qmk compile -kb ${kb} -km ${t}
        FIRM=${kb//\//_}_${t}.${TYPE}
        rm -f ${FIRM}
        mv ${QMK}/${FIRM} ./
    done
done
