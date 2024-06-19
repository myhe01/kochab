# Kochab
A low-power handheld GNSS receiver.

![alt text](https://raw.githubusercontent.com/myhe01/kochab/feature/documentation-0/Docs/Misc/Concepts/screen.png)

# Features
## Overview
* GNSS capability (GPS, GLONASS, Galileo, and BeiDou)
* Lower-power 400x240 monochrome LCD display and MCU
* Projected one month runtime on two AA batteries
* Support for multiple coordinate systems
   * Lat/long: DMS, DMM, DD
   * MGRS
   * UTM
   * Maidenhead
* Configurable display parameters:
   * Altitude MSL: ft, m
   * Time: local, UTC
   * Speed: mph, kph, kts, ft/s, m/s
   * Tripmeter: mi, km, NM, ft, m
   * Projected battery life remaining
* Configurable update periods for time and position to save battery life
   * Automatic update mode: 1 second
   * Periodic update mode: configurable up to 4 hours (updates manually triggerable)
   * Manual update mode: manually triggered
* Record up to 10 markpoints

## Parts
* MCU: [STM32L010RB](https://www.st.com/en/microcontrollers-microprocessors/stm32l010rb.html)
* GPS: [u-blox SAM-M10Q](https://www.u-blox.com/en/product/sam-m10q-module)
* LCD: [Sharp LS027B7DH01A](https://www.sharpsde.com/products/displays/model/ls027b7dh01a/)

# Building
## Prerequisites
* Windows 10 (x64)
* [STM32CubeMX 6.8.0](https://www.st.com/en/development-tools/stm32cubemx.html)
* [STM32CubeIDE 1.15.1](https://www.st.com/en/development-tools/stm32cubeide.html)

## Setup
1. Clone the repo into a workspace accessible by STM32CubeIDE.
2. Open STM32CubeMX load the project `Kochab.ioc`.
3. Generate the project code, downloading any dependencies if prompted.
4. Open and build with STM32CubeIDE.