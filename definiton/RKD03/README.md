# KEYBOARD

RKD03 [pcb](https://github.com/rikkodo/Rikkodo_PCB/tree/main/RKD_03)

## REFS

Atsushi Morimoto [Zenn QMK Firmware、REMAP(VIA)の対応手順](https://zenn.dev/74th/articles/7efc788a31d06f)

NANANA [Zenn オリジナルDIYキーボードでQMK firmwareを使ってロータリーエンコーダとNeoPixelを制御する方法](https://zenn.dev/nananauno/articles/bc258f7375604a)

NANANA [Zenn オリジナルDIYキーボードでQMK firmwareを使ってロータリーエンコーダとNeoPixelを制御する方法](https://zenn.dev/nananauno/articles/bc258f7375604a#rules.mk-1)

五月雨 [note ファームウェアをvial化した話](https://note.com/sam1dare/n/n816ce95fb2f2)

五月雨 [note ロータリーエンコーダーを搭載してみた話](https://note.com/sam1dare/n/n24d04427d4c3)

74th [github stickpoint-firmware](https://github.com/74th/stickpoint-firmware): az1uballの使用方法

swanmatch [github qmk_firmware](https://github.com/swanmatch/qmk_firmware) OLEDへのLED状態プリントを参考にさせていただきました。

## usage

デフォルト

```sh
cd <path_to_qmk_firmware>/keyboard
ln -s <path_to_repo>/src rkd
qmk compile -kb rkd03 -km default
```

BOOTSELを押しながらRaspberry pi picoをPCに接続。uf2ファイルをストレージデバイスにコピー。

## az1uball

74thさんの stickpoint-firmwareの使い方にしたがって設定することで動作した。

## qmkでソースコード分割

1. <keybaords/folder>より下にヘッダ(\*.h)とソース(\*.c)を用意する。
2. rules.mkに `LIB += <keyboards/folderを起点とした、ソースファイルまでの相対パス>` を追記する。
3. keymap.cに `#include "<keyboards/folderを起点とした、ヘッダまでの相対パス>"`を追記する。
