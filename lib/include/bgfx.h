#ifndef BGFX_H
#define BGFX_H

#include <stdbool.h>
#include "bgfx_font.h"

/* Data Types */
typedef struct bgfx_properties
{
   int px_width;             // Screen pixel width (1-based)
   int px_height;            // Screen pixel height (1-based)
   uint8_t * map;            // Screen map (1,1 is the top-leftmost pixel)
} bgfx_properties;

typedef struct bgfx_global_properties
{
   bgfx_properties user;      // User-set properties
   bgfx_font const * font;    // User-set font
   bool initialized;          // Global properties initialized?
   int bytes_per_row;         // Bytes per row in props.map
} bgfx_global_properties;

/* Global Variables */
extern bgfx_global_properties _bgfx_global_props;     // Global properties

/* Public Functions */
// Set up Brendan's Graphics Library
// bgfx_properties * bgfx_properties: Properties to initialize with.
// Returns 0 on success, -1 on failure.
int bgfx_setup(bgfx_properties * bgfx_properties);

// Add a point at (x,y) on the user map.
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_add_point(int x, int y);

// Draw a line along the x-axis from (start_x,y) to (start_x,y)
// int start_x: starting x-coordinate of user map.
// int finish_x: finishing x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_line_x(int start_x, int finish_x, int y);

// Draw a line along the y-axis from (x,start_y) to (x,finish_y)
// int x: x-coordinate of user map.
// int start_y: starting y-coordinate of user map.
// int finish_y: finishing y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_line_y(int x, int start_y, int finish_y);

// Draw a letter with the top left starting at x,y
// char letter: character to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_letter(char letter, int x, int y);

// Draw a letter of larger size with the top left starting at x,y
// char letter: character to draw
// int size_modifier: Size modifier for the character
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_letter_modified(char letter, int size_modifier, int x, int y);

// Draw a string horizontally with the top left starting at x,y.
// char * string: string to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string(char * string, int x, int y);

// Draw a string horizontally with padding, with the top left starting at x,y.
// char * string: string to draw
// int pad: number of pixels to pad between each letter
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string_padding(char * string, int pad, int x, int y);

/* Private Functions */
// Perform error checking on a set of coordinates to see if they're valid
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns true if valid, false if invalid.
bool _bgfx_valid(int x, int y);

// Add a point at (x,y) on the user map without error-checking.
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
void _bgfx_add_point(int x, int y);

// Check if there is a pixel present at (x,y) for a specific letter's map
// int x: x-coordinate of letter map
// int y: y-coordinate of letter map
// Returns true if pixel present, false if not
bool _bgfx_letter_point(uint8_t const * letter, int x, int y);

// Draw a letter with the top left starting at x,y
// char letter: character to draw
// int size_modifier: Size modifier for the character
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
void _bgfx_draw_letter(char letter, int size_modifier, int x, int y);

#endif // BGFX_H