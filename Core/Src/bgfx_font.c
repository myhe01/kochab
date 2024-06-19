#include "../Inc/bgfx.h"
#include "../Inc/bgfx_font.h"

/* Global Variables */
// Atari 8-pt Compact Font (8x8)
const bgfx_font BGFX_ATARI_8_COMPACT =
{
   .px_width = BGFX_ATARI_8_COMPACT_WIDTH,
   .px_height = BGFX_ATARI_8_COMPACT_HEIGHT,
   .bytes_per_row = BGFX_ATARI_8_COMPACT_WIDTH / (sizeof(uint8_t) * 8),
   .map = BGFX_ATARI_8_COMPACT_FONT
};

// Atari 8-pt Font (8x16)
const bgfx_font BGFX_ATARI_8 =
{
   .px_width = BGFX_ATARI_8_WIDTH,
   .px_height = BGFX_ATARI_8_HEIGHT,
   .bytes_per_row = BGFX_ATARI_8_WIDTH / (sizeof(uint8_t) * 8),
   .map = BGFX_ATARI_8_FONT
};

// Atari 16-pt Font (16x32)
const bgfx_font BGFX_ATARI_16 =
{
   .px_width = BGFX_ATARI_16_WIDTH,
   .px_height = BGFX_ATARI_16_HEIGHT,
   .bytes_per_row = BGFX_ATARI_16_WIDTH / (sizeof(uint8_t) * 8),
   .map = BGFX_ATARI_16_FONT
};

/* Public Functions */
// Set the font in global properties
// bgfx_font * font: Desired font struct.
// Returns 0 on success, -1 on failure.
int bgfx_set_font(bgfx_font const * font)
{
   // Check if library initialized
   if (!_bgfx_global_props.initialized)
   {
      return -1;
   }

   _bgfx_global_props.font = font;

   return 0;
}

/* Private Functions */
// For a given character, get the index of that character in font->map.
// bgfx_font * font: Dersired font.
// char character: Character to get the index of.
// Returns the index.
int _bgfx_get_index_of_char(bgfx_font const * font, char character)
{
   // If invalid char passed, return the index of ' '
   if (character < ' ' || character > '~')
   {
      return 0;
   }

   // Get the character's offset, then multiply by height and bytes per row
   return ((character - ' ') * font->bytes_per_row * font->px_height);
}
