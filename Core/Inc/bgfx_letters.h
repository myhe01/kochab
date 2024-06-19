#ifndef BGFX_LETTERS_H
#define BGFX_LETTERS_H

#include "bgfx.h"

/* Public Functions */
// Draw a letter with the top left starting at x,y
// char letter: character to draw
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_letter(char letter, int x, int y);

// Draw a letter of larger size with the top left starting at x,y
// char letter: character to draw
// int size_modifier: Size modifier for the character.
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

// Draw a string of larger size horizontally with padding, with the top left
// starting at x,y.
// char * string: string to draw
// int size_modifier: Size modifier for the character.
// int pad: number of pixels to pad between each letter
// int x: x-coordinate of user map.
// int y: y-coordinate of user map.
// Returns 0 on success, -1 on failure.
int bgfx_draw_string_modified_padding(char * string, int size_modifier,
   int pad, int x, int y);

/* Private Functions */
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

#endif // BGFX_LETTERS_H
