#ifndef BGFX_H
#define BGFX_H

#include <stdbool.h>
#include "bgfx_font.h"
#include "bgfx_letters.h"

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

// Draw a line along the x-axis from (start_x,y) to (finish_x,y)
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

// Draw an empty box from start (start_x,start_y) to (finish_x,finish_y)
// int start_x: starting x-coordinate of user map.
// int finish_x: finishing x-coordinate of user map.
// int start_y: starting y-coordinate of user map.
// int finish_y: finishing y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_box(int start_x, int finish_x, int start_y, int finish_y);

// Clear the display.
// Returns 0 on success, -1 on failure.
int bgfx_erase_all();

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

#endif // BGFX_H
