# Questions

## What's `stdint.h`?

TODO: is a header file in the C standard library to allow programmers to write more portable code
by providing a set of typedefs that specify exact-width integer types,
together with the defined minimum and maximum allowable values for each type, using macros .

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

TODO:

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

TODO: BYTE: 1 byte, DWORD: 4 bytes, LONG: 4 bytes, WORD: 2 bytes


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

TODO:

## What's the difference between `bfSize` and `biSize`?

TODO: 'bfSize': The size, in bytes, of the bitmap file. 'biSize': The number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

TODO: If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

TODO: biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

TODO

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

TODO

## What is `SEEK_CUR`?

TODO
# PSet4
