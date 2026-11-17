
// src/havok/common/base/types/color/hkcolor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/color/hkcolor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkColor.h"

int __cdecl hkMath_hkFloatToInt(float f);
unsigned int __cdecl PackBytesBigEndian(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

// Scales RGBA floats to 0-255 via FUN_00cbfef0 and packs them into a big-endian unsigned int via PackBytesBigEndian.
// @fnv 0x00cabb30
// pdb: hkColor::rgbFromFloats | hkColor.obj | retail, call graph, high
// pdb params: red, green, blue, alpha
// pdb locals: assertBuf, ostr
unsigned int __cdecl PackColorBigEndian(float red, float green, float blue, float alpha)
{
    unsigned char ucAlpha = hkMath_hkFloatToInt((float)(alpha * 255.0));
    unsigned char ucRed = hkMath_hkFloatToInt((float)(red * 255.0));
    unsigned char ucGreen = hkMath_hkFloatToInt((float)(green * 255.0));
    return PackBytesBigEndian(ucRed, ucGreen, hkMath_hkFloatToInt((float)(blue * 255.0)), ucAlpha);
}
