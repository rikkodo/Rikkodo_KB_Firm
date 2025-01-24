# KEYBOARD

RKD01 [pcb](https://github.com/rikkodo/Rikkodo_PCB/tree/main/RKD_01)

## REFS

サリチル酸 [Zenn GL516 デザインガイド QMKファームウェアを作成する](https://zenn.dev/salicylic_acid3/books/gl516_design_guide/viewer/make_firmware)

サリチル酸 [booth 自作キーボード設計ガイド](https://booth.pm/ja/items/4410329)

ymkn [Zenn QMK Firmwareで自作キーボードのファームウェアをイチから書く](https://zenn.dev/ymkn/articles/8f46a3d190fb13)

五月雨 [note ロータリーエンコーダーを搭載してみた話](https://note.com/sam1dare/n/n24d04427d4c3)

## usage

デフォルト

```sh
cd <path_to_qmk_firmware>/keyboard
ln -s <path_to_repo>/RKD01/src/rkd01
qmk compile -kb rkd01 -km default
qmk flash -kb rkd01 -km default
```
