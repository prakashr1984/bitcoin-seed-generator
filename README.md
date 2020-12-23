# A Bitcoin Mneumonic generator for MstickC.

A simple dedicated device that can be used to generate a 12/24 word mneumonic offline. It uses the inbuilt hardware (6-axis IMU SH200Q) and to generate entropy.

![MstickC](https://raw.githubusercontent.com/prakashr1984/bitcoin-seed-generator/master/docs/images/m5stick.jpg)

## Hardware

[MstickC](https://m5stack.com/products/stick-c?variant=17203451265114)

## Software

1. [Visual Studio Code](https://code.visualstudio.com/)
2. [PlatformIO extention for VSCode](https://platformio.org/install/ide?install=vscode)
3. Git

## Build

- Checkout code

```javascript
git clone https://github.com/prakashr1984/bitcoin-seed-generator.git
cd bitcoin-seed-generator
```

- Open the `bitcoin-seed-generator` folder in VS Code.
- PlatformIO: Build
  ![Build](https://raw.githubusercontent.com/prakashr1984/bitcoin-seed-generator/master/docs/images/verify.jpg)

## Upload Firmware to MstickC

- Make sure you have the device connected via USB
- PlatformIO: Upload
  ![Build](https://raw.githubusercontent.com/prakashr1984/bitcoin-seed-generator/master/docs/images/Upload.jpg)

## Dependencies

This project uses [M5StickC](https://github.com/m5stack/M5StickC#0.2.0) and [uBitcoin](https://github.com/micro-bitcoin/uBitcoin) library

Dependencies for this project are defined in platform.ini

```
lib_deps =
  https://github.com/m5stack/M5StickC.git#0.2.0
  https://github.com/micro-bitcoin/uBitcoin.git
```

## Developer Guide

Please refer to the [uBitcoin doc](https://micro-bitcoin.github.io/#/tutorial/README) to learn about the API's available in the bitcoin library.

The main source code resides in `src/` folder.

```
.
+-- src
|   +-- main.cpp
|   +-- Mnemonic.cpp
|   +-- Mnemonic.h
```

main.cpp - contains the bare minimum UI and code for seed generation. At present it uses the M5stick IMU library functions `getAccelData` , `getGyroData` to generate a randomness. It also uses `getTempData` to increase this randomness.

Mnemonic.cpp/.h - contains a custom logic for generating a random seed based on a sequence of float values (from any analog input pin of a device).

## ToDo

- Imporve the UI
- Additinal tools
  - Generate Checksum word
  - Generate Recieve addresses based on xpub stored on the device.
  - Generate a series of 24 word Seeds from an existing Seed ?
  - More...
