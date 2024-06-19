#include "../Inc/bgfx.h"
#include "../Inc/bgfx_letters.h"
#include <stddef.h>

/* Public Functions */
// Draw a letter with the top left starting at x,y
// char letter: character to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_letter(char letter, int x, int y)
{
   if (!_bgfx_valid(x, y))
   {
      return -1;
   }

   if (!_bgfx_valid(x + _bgfx_global_props.font->px_width,
      y + _bgfx_global_props.font->px_height))
   {
      return -1;
   }

   _bgfx_draw_letter(letter, 1, x, y);

   return 0;
}

// Draw a letter of larger size with the top left starting at x,y
// char letter: character to draw
// int size_modifier: Size modifier for the character
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_letter_modified(char letter, int size_modifier, int x, int y)
{
   if (!_bgfx_valid(x, y))
   {
      return -1;
   }

   if (!_bgfx_valid((x + _bgfx_global_props.font->px_width) * size_modifier,
      (y + _bgfx_global_props.font->px_height) * size_modifier))
   {
      return -1;
   }

   _bgfx_draw_letter(letter, size_modifier, x, y);

   return 0;
}

// Draw a string horizontally with the top left starting at x,y.
// char * string: string to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string(char * string, int x, int y)
{
   return bgfx_draw_string_modified_padding(string, 1, 1, x, y);
}

// Draw a string horizontally with padding, with the top left starting at x,y.
// char * string: string to draw
// int pad: number of pixels to pad between each letter
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string_padding(char * string, int pad, int x, int y)
{
   return bgfx_draw_string_modified_padding(string, 1, pad, x, y);
}

// Draw a string of larger size horizontally with padding, with the top left
// starting at x,y.
// char * string: string to draw
// int size_modifier: Size modifier for the character.
// int pad: number of pixels to pad between each letter
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string_modified_padding(char * string, int size_modifier,
   int pad, int x, int y)
{
   if (string == NULL)
   {
      return -1;
   }

   if (size_modifier < 1)
   {
      return -1;
   }

   int next_x = x;

   for (int i = 0; string[i] != '\0'; i++)
   {
      _bgfx_draw_letter(string[i], size_modifier, next_x, y);
      next_x += (_bgfx_global_props.font->px_width * size_modifier) + pad;
   }

   return 0;
}

/* Private Functions */
// Check if there is a pixel present at (x,y) for a specific letter's map.
// uint8_t const * letter: letter map to check
// int x: x-coordinate of letter map.
// int y: y-coordinate of letter map.
// Returns true if pixel present, false if not.
bool _bgfx_letter_point(uint8_t const * letter, int x, int y)
{
   int offset = 0, index = 0;
   int bit_pos = bit_pos = (y - 1) * _bgfx_global_props.font->bytes_per_row * 8
      + (x - 1);

   index = bit_pos / 8;
   offset = bit_pos % 8;

   return (letter[index] & (0x80 >> offset));
}

// Draw a letter with the top left starting at x,y
// char letter: character to draw
// int size_modifier: Size modifier for the character (multiples of 2)
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
void _bgfx_draw_letter(char letter, int size_modifier, int x, int y)
{
   int letter_width = _bgfx_global_props.font->px_width;
   int letter_height = _bgfx_global_props.font->px_height;
   uint8_t const * letter_map = _bgfx_global_props.font->map;
   letter_map += _bgfx_get_index_of_char(_bgfx_global_props.font, letter);

   for (int j = 1; j <= (letter_height * size_modifier); j++)
   {
      for (int i = 1; i <= (letter_width * size_modifier); i++)
      {
         if (_bgfx_letter_point(letter_map, i / size_modifier, j / size_modifier))
         {
            for (int k = 0; k < size_modifier; k++)
            {
               _bgfx_add_point(i + x + k, j + y + k);
            }
         }
      }
   }
}
