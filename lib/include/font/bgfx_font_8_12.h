#ifndef BGFX_FONT_8_12_H
#define BGFX_FONT_8_12_H

#include <stdint.h>

#define BGFX_FONT_8_12_WIDTH (int)8
#define BGFX_FONT_8_12_HEIGHT (int)12

/**
 * ...##...
 * ..####..
 * ..####..
 * ..####..
 * .##..##.
 * .##..##.
 * .######.
 * ########
 * ###..###
 * ##....##
 * ##....##
 * ##....##
 */
uint8_t letter_a[] = {0x18, 0x3c, 0x3c, 0x3c, 0x66, 0x66, 0x7e, 0xff, 0xe7,
                      0xc3, 0xc3, 0xc3};

#endif // BGFX_FONT_8_12_H