# pico-dev-smart
Showing smart way to development

# 詳細
このプロジェクトは組み込みプログラムの開発の説明のために公開しています。

「開発の説明」に関してはmainブランチの最新コミットを参照してください。

# ターゲットと動作
ターゲット・ボードは[Raspberry Pi Pico](https://www.raspberrypi.com/products/raspberry-pi-pico/)です。プロジェクトを通してWi-Fiは使いません。

このプロジェクトはプログラムをロードするとLEDが点滅するだけの簡単なプログラムです。

# ビルド方法
ビルド環境は以下の通りです:
- Ubuntu 
- Ubuntu on WSL
- Windows

環境の構築方法については[pico-env-easy](https://github.com/suikan4github/pico-env-easy)を参照してください。

コマンドラインから以下のコマンドを実行してください。
```bash
mkdir build
cd build
cmake ..
cd ..
cmake --build build
```
コンフィギュレーション時にSDKをダウンロードするので、少し時間がかかります。ビルドはすぐ終わります。

Visual Studio Codeを使う場合はCtrl-Shift-Pでコマンドパレットを出し、CMake: Configureを実行してください。コンフィギュレーションが終わったのち、ステータスバーのビルド・アイコンをクリックしてビルドします。

buildディレクトリの中にtutrial.u2fファイルができますので、それをRaspberry Pi Picoのストレージにコピーしてください。LEDが点滅を始めます。


# 貢献
現時点ではコメント及び文書の誤字脱字以外に対するプルリクエストは受け付けていません。

なお、受理したプルリクエストはプロジェクトのライセンス条件に従って公開されます。

# ライセンス

このプロジェクトは特記ない限り[MITライセンス](LICENSE)が定める要件に従って配布しています。

[pico_sdk_import.cmake](pico_sdk_import.cmake)ファイルは[RaspberryPiのpico-sdk](https://github.com/raspberrypi/pico-sdk)よりコピーしたものです。このファイルはBSD 3-Clause "New" or "Revised" Licenseが定める要件により、Raspberry Pi (Trading) Ltd.よりライセンスされています。詳しくは当該ファイルのライセンス要件を読んでください。