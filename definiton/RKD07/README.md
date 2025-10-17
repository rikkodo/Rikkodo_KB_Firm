# KEYBOARD

RKD07 [pcb](https://github.com/rikkodo/Rikkodo_PCB/tree/main/RKD_07)

デフォルト

```sh
cd <path_to_qmk_firmware>/keyboard
ln -s <path_to_repo>/src rkd
qmk compile -kb rkd07/picot -km default
qmk compile -kb rkd07/rpi/nogikesu -km default
```

BOOTSELを押しながらRaspberry pi picoをPCに接続。uf2ファイルをストレージデバイスにコピー。

split
```sh
qmk flash -kb  rkd/rkd07sp/rpi/pmw3610/left -km default  -bl uf2-split-left
qmk flash -kb  rkd/rkd07sp/rpi/pmw3610/right -km default  -bl uf2-split-right
```

