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
