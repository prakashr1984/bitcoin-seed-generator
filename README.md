# A Bitcoin Mneumonic generator for MstickC.

A simple device that can generate a 12/24 word mneumonic offline.

## Hardware

1. [MstickC](https://m5stack.com/products/stick-c?variant=17203451265114)

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

## Upload Firmware to MstickC

- Make sure you have the device connected via USB
- PlatformIO: Upload

## Dependencies

This project uses [M5StickC](https://github.com/m5stack/M5StickC#0.2.0) and [uBitcoin](https://github.com/micro-bitcoin/uBitcoin) library

Dependencies for this project are defined in platform.ini

```
lib_deps =
  https://github.com/m5stack/M5StickC.git#0.2.0
  https://github.com/micro-bitcoin/uBitcoin.git
```
