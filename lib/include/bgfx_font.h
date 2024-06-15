#ifndef BGFX_FONT_H
#define BGFX_FONT_H

#include "font/bgfx_atari_8_compact.h"
#include "font/bgfx_atari_8.h"
#include "font/bgfx_atari_16.h"

/* Data Types */
typedef struct bgfx_font
{
   int px_width;             // Font pixel width (1-based)
   int px_height;            // Font pixel height (1-based)
   int bytes_per_row;        // Bytes per row in map
   uint8_t const * map;      // Font map
} bgfx_font;

/* Global Variables */
extern const bgfx_font BGFX_ATARI_8_COMPACT; // Atari 8-pt Compact Font (8x8)
extern const bgfx_font BGFX_ATARI_8;         // Atari 8-pt Font (8x16)
extern const bgfx_font BGFX_ATARI_16;        // Atari 16-pt Font (16x32)

/* Public Functions */
// Set the font in global properties
// bgfx_font * font: Desired font struct.
// Returns 0 on success, -1 on failure.
int bgfx_set_font(bgfx_font const * font);

/* Private Functions */
// For a given character, get the index of that character in font->map.
// bgfx_font * font: Dersired font.
// char character: Character to get the index of.
// Returns the index.
int _bgfx_get_index_of_char(bgfx_font const * font, char character);

#endif // BGFX_FONT_H