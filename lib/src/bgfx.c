#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/bgfx.h"
#include "../include/font/bgfx_helvetica_12.h"

/* Global Variables */
// Global properties
bgfx_global_properties _bgfx_global_props =
{
   .initialized = 0,
   .bytes_per_row = 0,
   .font = &BGFX_ATARI_8,
   .user =
   {
      .px_width = 0,
      .px_height = 0,
      .map = NULL
   }
};

/* Public Functions */
// Set up Brendan's Graphics Library
// bgfx_properties * bgfx_properties: Properties to initialize with.
// Returns 0 on success, -1 on failure.
int bgfx_setup(bgfx_properties * bgfx_properties)
{
   if (bgfx_properties == NULL || bgfx_properties->map == NULL)
   {
      return -1;
   }

   _bgfx_global_props.user.px_width = bgfx_properties->px_width;
   _bgfx_global_props.user.px_height = bgfx_properties->px_height;
   _bgfx_global_props.user.map = bgfx_properties->map;

   _bgfx_global_props.bytes_per_row =
      (_bgfx_global_props.user.px_width / (sizeof(uint8_t) * 8));

   _bgfx_global_props.initialized = true;
   return 0;
}

// Add a point at (x,y) on the user map.
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_add_point(int x, int y)
{
   // Check if library initialized
   if (!_bgfx_valid(x, y))
   {
      return -1;
   }

   _bgfx_add_point(x, y);
   return 0;
}

// Draw a line along the x-axis from (start_x,y) to (start_x,y)
// int start_x: starting x-coordinate of user map.
// int finish_x: finishing x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_line_x(int start_x, int finish_x, int y)
{
   if (!(_bgfx_valid(start_x, y) && _bgfx_valid(finish_x, y)))
   {
      return -1;
   }

   int s_x = ((start_x < finish_x) ? start_x : finish_x);
   int f_x = ((start_x < finish_x) ? finish_x : start_x);

   for (int i = s_x; i <= f_x; i++)
   {
      _bgfx_add_point(i, y);
   }

   return 0;
}

// Draw a line along the y-axis from (x,start_y) to (x,finish_y)
// int x: x-coordinate of user map.
// int start_y: starting y-coordinate of user map.
// int finish_y: finishing y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_line_y(int x, int start_y, int finish_y)
{
   if (!(_bgfx_valid(x, start_y) && _bgfx_valid(x, finish_y)))
   {
      return -1;
   }

   int s_y = ((start_y < finish_y) ? start_y : finish_y);
   int f_y = ((start_y < finish_y) ? finish_y : start_y);

   for (int i = s_y; i <= f_y; i++)
   {
      _bgfx_add_point(x, i);
   }

   return 0;
}

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

   int letter_width = _bgfx_global_props.font->px_width;
   int letter_height = _bgfx_global_props.font->px_height;
   uint8_t const * letter_map = _bgfx_global_props.font->map;
   letter_map += _bgfx_get_index_of_char(_bgfx_global_props.font, letter);

   for (int j = 1; j <= letter_height; j++)
   {
      for (int i = 1; i <= letter_width; i++)
      {
         if (_bgfx_letter_point(letter_map, i, j))
         {
            _bgfx_add_point(i + x, j + y);
         }
      }
   }

   return 0;
}

// Draw a string horizontally with the top left starting at x,y.
// char * string: string to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string(char * string, int x, int y)
{
   return bgfx_draw_string_padding(string, 1, x, y);
}

// Draw a string horizontally with padding, with the top left starting at x,y.
// char * string: string to draw
// int pad: number of pixels to pad between each letter
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string_padding(char * string, int pad, int x, int y)
{
   if (string == NULL)
   {
      return -1;
   }

   int next_x = x;

   for (int i = 0; string[i] != '\0'; i++)
   {
      bgfx_draw_letter(string[i], next_x, y);
      next_x += _bgfx_global_props.font->px_width + pad;   // Padding + 1
   }
}

/* Private Functions */
// Perform error checking on a set of coordinates to see if they're valid
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns true if valid, false if invalid.
bool _bgfx_valid(int x, int y)
{
   // Check if library initialized
   if (!_bgfx_global_props.initialized)
   {
      return false;
   }

   // Error checking x-coordinate
   if (x < 1 || x > _bgfx_global_props.user.px_width)
   {
      return false;
   }

   // Error checking y-coordinate
   if (y < 1 || y > _bgfx_global_props.user.px_height)
   {
      return false;
   }

   return true;
}

// Add a point at (x,y) on the user map without error-checking.
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
void _bgfx_add_point(int x, int y)
{
   int offset = 0, index = 0;
   int bit_pos = (y - 1) * (_bgfx_global_props.bytes_per_row * 8) + (x - 1);

   index = bit_pos / 8;
   offset = bit_pos % 8;

   _bgfx_global_props.user.map[index] |= (0x80 >> offset);
}

// Check if there is a pixel present at (x,y) for a specific letter's map.
// int x: x-coordinate of letter map.
// int y: y-coordinate of letter map.
// Returns true if pixel present, false if not.
bool _bgfx_letter_point(uint8_t const * letter, int x, int y)
{
   int offset = 0, index = 0;
   int bit_pos = bit_pos = (y - 1) * 8 + (x - 1);

   index = bit_pos / 8;
   offset = bit_pos % 8;

   return (letter[index] & (0x80 >> offset));
}