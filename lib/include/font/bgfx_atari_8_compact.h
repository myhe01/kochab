#ifndef BGFX_ATARI_8_COMPACT_H
#define BGFX_ATARI_8_COMPACT_H

#include <stdint.h>

#define BGFX_ATARI_8_COMPACT_WIDTH (int)8       // Font px width
#define BGFX_ATARI_8_COMPACT_HEIGHT (int)8      // Font px height

static const uint8_t BGFX_ATARI_8_COMPACT_FONT[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x00, // !
   0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0xfe, 0x6c, 0x6c, 0xfe, 0x6c, 0x00,
   0x18, 0x3e, 0x60, 0x3c, 0x06, 0x7c, 0x18, 0x00, 0x00, 0x66, 0x6c, 0x18, 0x30, 0x66, 0x46, 0x00,
   0x38, 0x6c, 0x38, 0x70, 0xde, 0xcc, 0x76, 0x00, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x0e, 0x1c, 0x18, 0x18, 0x18, 0x1c, 0x0e, 0x00, 0x70, 0x38, 0x18, 0x18, 0x18, 0x38, 0x70, 0x00,
   0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x02, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x40, 0x00,
   0x3c, 0x66, 0x6e, 0x76, 0x66, 0x66, 0x3c, 0x00, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00,
   0x3c, 0x66, 0x06, 0x0c, 0x18, 0x30, 0x7e, 0x00, 0x7e, 0x0c, 0x18, 0x0c, 0x06, 0x66, 0x3c, 0x00,
   0x0c, 0x1c, 0x3c, 0x6c, 0x7e, 0x0c, 0x0c, 0x00, 0x7e, 0x60, 0x7c, 0x06, 0x06, 0x66, 0x3c, 0x00,
   0x3c, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x3c, 0x00, 0x7e, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x30, 0x00,
   0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00, 0x3c, 0x66, 0x66, 0x3e, 0x06, 0x0c, 0x38, 0x00,
   0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30, 0x00,
   0x06, 0x0c, 0x18, 0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00,
   0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00, 0x3c, 0x66, 0x06, 0x0c, 0x18, 0x00, 0x18, 0x00,
   0x3c, 0x66, 0x6e, 0x6a, 0x6e, 0x60, 0x3e, 0x00, 0x18, 0x3c, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x00,
   0x7c, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x7c, 0x00, 0x3c, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3c, 0x00,
   0x78, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0x78, 0x00, 0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x7e, 0x00,
   0x7e, 0x60, 0x60, 0x7c, 0x60, 0x60, 0x60, 0x00, 0x3e, 0x60, 0x60, 0x6e, 0x66, 0x66, 0x3e, 0x00,
   0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00,
   0x06, 0x06, 0x06, 0x06, 0x06, 0x66, 0x3c, 0x00, 0x66, 0x6c, 0x78, 0x70, 0x78, 0x6c, 0x66, 0x00,
   0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x00, 0xc6, 0xee, 0xfe, 0xd6, 0xc6, 0xc6, 0xc6, 0x00,
   0x66, 0x76, 0x7e, 0x7e, 0x6e, 0x66, 0x66, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00,
   0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x76, 0x6c, 0x36, 0x00,
   0x7c, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0x66, 0x00, 0x3c, 0x66, 0x60, 0x3c, 0x06, 0x66, 0x3c, 0x00,
   0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00,
   0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, 0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00,
   0x66, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x00,
   0x7e, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1e, 0x00,
   0x40, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x00, 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00,
   0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00,
   0x00, 0xc0, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x06, 0x3e, 0x66, 0x3e, 0x00,
   0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x7c, 0x00, 0x00, 0x00, 0x3c, 0x60, 0x60, 0x60, 0x3c, 0x00,
   0x06, 0x06, 0x3e, 0x66, 0x66, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x00,
   0x1c, 0x30, 0x7c, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x7c,
   0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00, 0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00,
   0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x70, 0x60, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0x00,
   0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0xec, 0xfe, 0xd6, 0xc6, 0xc6, 0x00,
   0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x3c, 0x00,
   0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x7c, 0x60, 0x00, 0x00, 0x3e, 0x66, 0x66, 0x66, 0x3e, 0x06,
   0x00, 0x00, 0x7c, 0x66, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x3e, 0x60, 0x3c, 0x06, 0x7c, 0x00,
   0x00, 0x18, 0x7e, 0x18, 0x18, 0x18, 0x0e, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00,
   0x00, 0x00, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xd6, 0x7c, 0x6c, 0x00,
   0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x3e, 0x06, 0x7c,
   0x00, 0x00, 0x7e, 0x0c, 0x18, 0x30, 0x7e, 0x00, 0x0e, 0x18, 0x18, 0x30, 0x18, 0x18, 0x0e, 0x00,
   0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x0c, 0x18, 0x18, 0x70, 0x00,
   0x00, 0x60, 0xf2, 0x9e, 0x0c, 0x00, 0x00, 0x00
};

/*
name: 8x8 system font
spacing: character-cell
cell-size: 8 8
point-size: 9
ascent: 7
descent: 1
encoding: atari-st
converter: monobit v0.32
source-name: system09.fnt
source-format: gdos
source-url: https://github.com/th-otto/gemfedit/tree/master/fonts/tos
gdos: font-id=1 left-offset=1 right-offset=3
shift-up: -1

# [ ] SPACE
u+0020:
0x20:
   ........
   ........
   ........
   ........
   ........
   ........
   ........
   ........


# [!] EXCLAMATION MARK
u+0021:
0x21:
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ........
   ...@@...
   ........


# ["] QUOTATION MARK
u+0022:
0x22:
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ........
   ........
   ........
   ........
   ........


# [#] NUMBER SIGN
u+0023:
0x23:
   ........
   .@@.@@..
   @@@@@@@.
   .@@.@@..
   .@@.@@..
   @@@@@@@.
   .@@.@@..
   ........


# [$] DOLLAR SIGN
u+0024:
0x24:
   ...@@...
   ..@@@@@.
   .@@.....
   ..@@@@..
   .....@@.
   .@@@@@..
   ...@@...
   ........


# [%] PERCENT SIGN
u+0025:
0x25:
   ........
   .@@..@@.
   .@@.@@..
   ...@@...
   ..@@....
   .@@..@@.
   .@...@@.
   ........


# [&] AMPERSAND
u+0026:
0x26:
   ..@@@...
   .@@.@@..
   ..@@@...
   .@@@....
   @@.@@@@.
   @@..@@..
   .@@@.@@.
   ........


# ['] APOSTROPHE
u+0027:
0x27:
   ...@@...
   ...@@...
   ...@@...
   ........
   ........
   ........
   ........
   ........


# [(] LEFT PARENTHESIS
u+0028:
0x28:
   ....@@@.
   ...@@@..
   ...@@...
   ...@@...
   ...@@...
   ...@@@..
   ....@@@.
   ........


# [)] RIGHT PARENTHESIS
u+0029:
0x29:
   .@@@....
   ..@@@...
   ...@@...
   ...@@...
   ...@@...
   ..@@@...
   .@@@....
   ........


# [*] ASTERISK
u+002a:
0x2a:
   ........
   .@@..@@.
   ..@@@@..
   @@@@@@@@
   ..@@@@..
   .@@..@@.
   ........
   ........


# [+] PLUS SIGN
u+002b:
0x2b:
   ........
   ...@@...
   ...@@...
   .@@@@@@.
   ...@@...
   ...@@...
   ........
   ........


# [,] COMMA
u+002c:
0x2c:
   ........
   ........
   ........
   ........
   ........
   ..@@....
   ..@@....
   .@@.....


# [-] HYPHEN-MINUS
u+002d:
0x2d:
   ........
   ........
   ........
   .@@@@@@.
   ........
   ........
   ........
   ........


# [.] FULL STOP
u+002e:
0x2e:
   ........
   ........
   ........
   ........
   ........
   ...@@...
   ...@@...
   ........


# [/] SOLIDUS
u+002f:
0x2f:
   ......@.
   .....@@.
   ....@@..
   ...@@...
   ..@@....
   .@@.....
   .@......
   ........


# [0] DIGIT ZERO
u+0030:
0x30:
   ..@@@@..
   .@@..@@.
   .@@.@@@.
   .@@@.@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ........


# [1] DIGIT ONE
u+0031:
0x31:
   ...@@...
   ..@@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   .@@@@@@.
   ........


# [2] DIGIT TWO
u+0032:
0x32:
   ..@@@@..
   .@@..@@.
   .....@@.
   ....@@..
   ...@@...
   ..@@....
   .@@@@@@.
   ........


# [3] DIGIT THREE
u+0033:
0x33:
   .@@@@@@.
   ....@@..
   ...@@...
   ....@@..
   .....@@.
   .@@..@@.
   ..@@@@..
   ........


# [4] DIGIT FOUR
u+0034:
0x34:
   ....@@..
   ...@@@..
   ..@@@@..
   .@@.@@..
   .@@@@@@.
   ....@@..
   ....@@..
   ........


# [5] DIGIT FIVE
u+0035:
0x35:
   .@@@@@@.
   .@@.....
   .@@@@@..
   .....@@.
   .....@@.
   .@@..@@.
   ..@@@@..
   ........


# [6] DIGIT SIX
u+0036:
0x36:
   ..@@@@..
   .@@.....
   .@@.....
   .@@@@@..
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ........


# [7] DIGIT SEVEN
u+0037:
0x37:
   .@@@@@@.
   .....@@.
   ....@@..
   ...@@...
   ..@@....
   ..@@....
   ..@@....
   ........


# [8] DIGIT EIGHT
u+0038:
0x38:
   ..@@@@..
   .@@..@@.
   .@@..@@.
   ..@@@@..
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ........


# [9] DIGIT NINE
u+0039:
0x39:
   ..@@@@..
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   .....@@.
   ....@@..
   ..@@@...
   ........


# [:] COLON
u+003a:
0x3a:
   ........
   ...@@...
   ...@@...
   ........
   ...@@...
   ...@@...
   ........
   ........


# [;] SEMICOLON
u+003b:
0x3b:
   ........
   ...@@...
   ...@@...
   ........
   ...@@...
   ...@@...
   ..@@....
   ........


# [<] LESS-THAN SIGN
u+003c:
0x3c:
   .....@@.
   ....@@..
   ...@@...
   ..@@....
   ...@@...
   ....@@..
   .....@@.
   ........


# [=] EQUALS SIGN
u+003d:
0x3d:
   ........
   ........
   .@@@@@@.
   ........
   ........
   .@@@@@@.
   ........
   ........


# [>] GREATER-THAN SIGN
u+003e:
0x3e:
   .@@.....
   ..@@....
   ...@@...
   ....@@..
   ...@@...
   ..@@....
   .@@.....
   ........


# [?] QUESTION MARK
u+003f:
0x3f:
   ..@@@@..
   .@@..@@.
   .....@@.
   ....@@..
   ...@@...
   ........
   ...@@...
   ........


# [@] COMMERCIAL AT
u+0040:
0x40:
   ..@@@@..
   .@@..@@.
   .@@.@@@.
   .@@.@.@.
   .@@.@@@.
   .@@.....
   ..@@@@@.
   ........


# [A] LATIN CAPITAL LETTER A
u+0041:
0x41:
   ...@@...
   ..@@@@..
   .@@..@@.
   .@@..@@.
   .@@@@@@.
   .@@..@@.
   .@@..@@.
   ........


# [B] LATIN CAPITAL LETTER B
u+0042:
0x42:
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@@@@..
   ........


# [C] LATIN CAPITAL LETTER C
u+0043:
0x43:
   ..@@@@..
   .@@..@@.
   .@@.....
   .@@.....
   .@@.....
   .@@..@@.
   ..@@@@..
   ........


# [D] LATIN CAPITAL LETTER D
u+0044:
0x44:
   .@@@@...
   .@@.@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@.@@..
   .@@@@...
   ........


# [E] LATIN CAPITAL LETTER E
u+0045:
0x45:
   .@@@@@@.
   .@@.....
   .@@.....
   .@@@@@..
   .@@.....
   .@@.....
   .@@@@@@.
   ........


# [F] LATIN CAPITAL LETTER F
u+0046:
0x46:
   .@@@@@@.
   .@@.....
   .@@.....
   .@@@@@..
   .@@.....
   .@@.....
   .@@.....
   ........


# [G] LATIN CAPITAL LETTER G
u+0047:
0x47:
   ..@@@@@.
   .@@.....
   .@@.....
   .@@.@@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   ........


# [H] LATIN CAPITAL LETTER H
u+0048:
0x48:
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@@@@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ........


# [I] LATIN CAPITAL LETTER I
u+0049:
0x49:
   ..@@@@..
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ..@@@@..
   ........


# [J] LATIN CAPITAL LETTER J
u+004a:
0x4a:
   .....@@.
   .....@@.
   .....@@.
   .....@@.
   .....@@.
   .@@..@@.
   ..@@@@..
   ........


# [K] LATIN CAPITAL LETTER K
u+004b:
0x4b:
   .@@..@@.
   .@@.@@..
   .@@@@...
   .@@@....
   .@@@@...
   .@@.@@..
   .@@..@@.
   ........


# [L] LATIN CAPITAL LETTER L
u+004c:
0x4c:
   .@@.....
   .@@.....
   .@@.....
   .@@.....
   .@@.....
   .@@.....
   .@@@@@@.
   ........


# [M] LATIN CAPITAL LETTER M
u+004d:
0x4d:
   @@...@@.
   @@@.@@@.
   @@@@@@@.
   @@.@.@@.
   @@...@@.
   @@...@@.
   @@...@@.
   ........


# [N] LATIN CAPITAL LETTER N
u+004e:
0x4e:
   .@@..@@.
   .@@@.@@.
   .@@@@@@.
   .@@@@@@.
   .@@.@@@.
   .@@..@@.
   .@@..@@.
   ........


# [O] LATIN CAPITAL LETTER O
u+004f:
0x4f:
   ..@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ........


# [P] LATIN CAPITAL LETTER P
u+0050:
0x50:
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@@@@..
   .@@.....
   .@@.....
   .@@.....
   ........


# [Q] LATIN CAPITAL LETTER Q
u+0051:
0x51:
   ..@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@@.@@.
   .@@.@@..
   ..@@.@@.
   ........


# [R] LATIN CAPITAL LETTER R
u+0052:
0x52:
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@@@@..
   .@@.@@..
   .@@..@@.
   .@@..@@.
   ........


# [S] LATIN CAPITAL LETTER S
u+0053:
0x53:
   ..@@@@..
   .@@..@@.
   .@@.....
   ..@@@@..
   .....@@.
   .@@..@@.
   ..@@@@..
   ........


# [T] LATIN CAPITAL LETTER T
u+0054:
0x54:
   .@@@@@@.
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ........


# [U] LATIN CAPITAL LETTER U
u+0055:
0x55:
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   ........


# [V] LATIN CAPITAL LETTER V
u+0056:
0x56:
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ...@@...
   ........


# [W] LATIN CAPITAL LETTER W
u+0057:
0x57:
   @@...@@.
   @@...@@.
   @@...@@.
   @@.@.@@.
   @@@@@@@.
   @@@.@@@.
   @@...@@.
   ........


# [X] LATIN CAPITAL LETTER X
u+0058:
0x58:
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ...@@...
   ..@@@@..
   .@@..@@.
   .@@..@@.
   ........


# [Y] LATIN CAPITAL LETTER Y
u+0059:
0x59:
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ...@@...
   ...@@...
   ...@@...
   ........


# [Z] LATIN CAPITAL LETTER Z
u+005a:
0x5a:
   .@@@@@@.
   .....@@.
   ....@@..
   ...@@...
   ..@@....
   .@@.....
   .@@@@@@.
   ........


# [[] LEFT SQUARE BRACKET
u+005b:
0x5b:
   ...@@@@.
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@@@.
   ........


# [\] REVERSE SOLIDUS
u+005c:
0x5c:
   .@......
   .@@.....
   ..@@....
   ...@@...
   ....@@..
   .....@@.
   ......@.
   ........


# []] RIGHT SQUARE BRACKET
u+005d:
0x5d:
   .@@@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   .@@@@...
   ........


# [^] CIRCUMFLEX ACCENT
u+005e:
0x5e:
   ...@....
   ..@@@...
   .@@.@@..
   @@...@@.
   ........
   ........
   ........
   ........


# [_] LOW LINE
u+005f:
0x5f:
   ........
   ........
   ........
   ........
   ........
   ........
   @@@@@@@.
   ........


# [`] GRAVE ACCENT
u+0060:
0x60:
   ........
   @@......
   .@@.....
   ..@@....
   ........
   ........
   ........
   ........


# [a] LATIN SMALL LETTER A
u+0061:
0x61:
   ........
   ........
   ..@@@@..
   .....@@.
   ..@@@@@.
   .@@..@@.
   ..@@@@@.
   ........


# [b] LATIN SMALL LETTER B
u+0062:
0x62:
   .@@.....
   .@@.....
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@@@@..
   ........


# [c] LATIN SMALL LETTER C
u+0063:
0x63:
   ........
   ........
   ..@@@@..
   .@@.....
   .@@.....
   .@@.....
   ..@@@@..
   ........


# [d] LATIN SMALL LETTER D
u+0064:
0x64:
   .....@@.
   .....@@.
   ..@@@@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   ........


# [e] LATIN SMALL LETTER E
u+0065:
0x65:
   ........
   ........
   ..@@@@..
   .@@..@@.
   .@@@@@@.
   .@@.....
   ..@@@@..
   ........


# [f] LATIN SMALL LETTER F
u+0066:
0x66:
   ...@@@..
   ..@@....
   .@@@@@..
   ..@@....
   ..@@....
   ..@@....
   ..@@....
   ........


# [g] LATIN SMALL LETTER G
u+0067:
0x67:
   ........
   ........
   ..@@@@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   .....@@.
   .@@@@@..


# [h] LATIN SMALL LETTER H
u+0068:
0x68:
   .@@.....
   .@@.....
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ........


# [i] LATIN SMALL LETTER I
u+0069:
0x69:
   ...@@...
   ........
   ..@@@...
   ...@@...
   ...@@...
   ...@@...
   ..@@@@..
   ........


# [j] LATIN SMALL LETTER J
u+006a:
0x6a:
   ...@@...
   ........
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   .@@@....


# [k] LATIN SMALL LETTER K
u+006b:
0x6b:
   .@@.....
   .@@.....
   .@@..@@.
   .@@.@@..
   .@@@@...
   .@@.@@..
   .@@..@@.
   ........


# [l] LATIN SMALL LETTER L
u+006c:
0x6c:
   ..@@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ..@@@@..
   ........


# [m] LATIN SMALL LETTER M
u+006d:
0x6d:
   ........
   ........
   @@@.@@..
   @@@@@@@.
   @@.@.@@.
   @@...@@.
   @@...@@.
   ........


# [n] LATIN SMALL LETTER N
u+006e:
0x6e:
   ........
   ........
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ........


# [o] LATIN SMALL LETTER O
u+006f:
0x6f:
   ........
   ........
   ..@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ........


# [p] LATIN SMALL LETTER P
u+0070:
0x70:
   ........
   ........
   .@@@@@..
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@@@@..
   .@@.....


# [q] LATIN SMALL LETTER Q
u+0071:
0x71:
   ........
   ........
   ..@@@@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   .....@@.


# [r] LATIN SMALL LETTER R
u+0072:
0x72:
   ........
   ........
   .@@@@@..
   .@@..@@.
   .@@.....
   .@@.....
   .@@.....
   ........


# [s] LATIN SMALL LETTER S
u+0073:
0x73:
   ........
   ........
   ..@@@@@.
   .@@.....
   ..@@@@..
   .....@@.
   .@@@@@..
   ........


# [t] LATIN SMALL LETTER T
u+0074:
0x74:
   ........
   ...@@...
   .@@@@@@.
   ...@@...
   ...@@...
   ...@@...
   ....@@@.
   ........


# [u] LATIN SMALL LETTER U
u+0075:
0x75:
   ........
   ........
   .@@..@@.
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   ........


# [v] LATIN SMALL LETTER V
u+0076:
0x76:
   ........
   ........
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@..
   ...@@...
   ........


# [w] LATIN SMALL LETTER W
u+0077:
0x77:
   ........
   ........
   @@...@@.
   @@...@@.
   @@.@.@@.
   .@@@@@..
   .@@.@@..
   ........


# [x] LATIN SMALL LETTER X
u+0078:
0x78:
   ........
   ........
   .@@..@@.
   ..@@@@..
   ...@@...
   ..@@@@..
   .@@..@@.
   ........


# [y] LATIN SMALL LETTER Y
u+0079:
0x79:
   ........
   ........
   .@@..@@.
   .@@..@@.
   .@@..@@.
   ..@@@@@.
   .....@@.
   .@@@@@..


# [z] LATIN SMALL LETTER Z
u+007a:
0x7a:
   ........
   ........
   .@@@@@@.
   ....@@..
   ...@@...
   ..@@....
   .@@@@@@.
   ........


# [{] LEFT CURLY BRACKET
u+007b:
0x7b:
   ....@@@.
   ...@@...
   ...@@...
   ..@@....
   ...@@...
   ...@@...
   ....@@@.
   ........


# [|] VERTICAL LINE
u+007c:
0x7c:
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...
   ...@@...


# [}] RIGHT CURLY BRACKET
u+007d:
0x7d:
   .@@@....
   ...@@...
   ...@@...
   ....@@..
   ...@@...
   ...@@...
   .@@@....
   ........


# [~] TILDE
u+007e:
0x7e:
   ........
   .@@.....
   @@@@..@.
   @..@@@@.
   ....@@..
   ........
   ........
   ........
*/

#endif // BGFX_ATARI_8_COMPACT_H