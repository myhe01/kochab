# Kochab
A low-power handheld GNSS receiver.

![alt text](https://lh3.googleusercontent.com/pw/AP1GczNg5R7oE9L-cLJt5moOIUcd2UNi1GkHYADrezUg5DCfUuyrJEU1JfahVnCeTQ79EBQgSAQgFBYa9Vtu0GnK-DV5vDjo6p4h5UGknXF5A2vPybUTW07hw6iNfhumD8KIumZOiVAhjReOPQVDElIxBFlqghPFcr-8r3z0jdCs7gSM-UsJuzneggoT-NigB3psQ37DIoyHVXlhUb5pROxO2df7H-EVNTjjX9AfgYcYZ_9bpvLk58c9OOKeJ9-MxOqFS7WV65x0a0ApGzIsTBVk-Ea1fX2whU-wMM4pGCuLM6WKMIhSeXonWR1gh0HqqlY0frJuPcCOG8WpUfB901kYlXj9LcLwlEWKSMbRHRZUrVM6QVXjL3_hMgqpY8LoMWlNT8axTYm1_i8vq77qIdmruSpEOSbrf9pBHR2Se0O5HthNAFIzVT5GXyKCNr3Ef3bcsAwAemLzUdGisuaxUN_cj8VnlZC2QXhqOnKBarNCP880PJd6g0C8B94Qejqm0w9TpGi6aabYhwjukroRJojCYWmf-0KTO3hR7fkPf9XLDV_Qnq_KtYSJBiwwwdO8apfeQoqZsFAdr729x9kwGjdARi0u846xblDzRgxDr3Fuo_JcmuFguLpW7WrJlWE_IlSV2pnpikH3Dnlo6RKF3QjkBLecbWiguCbxmpFP_sox9qx7OIHFTaL5xvYCZKYYMcuEkRWrBxhptrS9OZAORHsdKjV1yms_9daNg5_xxP4bV59pgvmbaEipTec7rCV-9A02CZ3Pl1LuQK88Eh44q43oprkbxbAC3wxeeWDII6PD1cWKPgZxzukPcxkqMqbTsHddq4W-RgT9a8U3jfAbYaNd8InWnYe0ENYfrkRlthK-N6yUhmSA8hHNqRRunQ29NkWo4GlwPD3mddZN9u81fnAJ9XrYzM_6jxOZRIhQHNHAahQHTSAxvND1MxN7BiexHjdQwQf9NHjbt37c0PDz74OKxzE0YfUeAWc=w400-h300-s-no-gm?authuser=0)

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