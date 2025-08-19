#!/bin/bash
set -Ceux


KB="rkd/rkd10"
TARGET="default"
TYPE="hex"

QMK="${HOME}/qmk_firmware"

for t in ${TARGET}
do
    qmk compile -kb ${KB} -km ${t}
    FIRM=${KB/\//_}_${t}.${TYPE}
    rm -f ${FIRM}
    mv ${QMK}/${FIRM} ./
done
