#include "../../../../../include/hkStringPtr.h"

// src/havok/common/compat/deprecated/hkserializedeprecated.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/compat/deprecated/hkserializedeprecated.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dba5f0
// src: HAVOK_SRC 0x00dba5f0
// pdb: hkSerializeDeprecated::loadOldPackfileOnHeap | hkSerializeDeprecated.obj | retail, upstream name already matches, high
// pdb params: sr, details, errorOut
int __stdcall hkSerializeDeprecated_loadOldPackfileOnHeap(int sr, int details, int errorOut)
{
    hkStringPtr* p = (hkStringPtr*)errorOut;
    if (p)
    {
        *(int*)p = 7;
        *(hkStringPtr*)((char*)p + 4) =
            "Call hkSerializeDeprecated::initDeprecated() to include loading support for this file";
    }
    return 0;
}

// If c is non-null, writes error code 7 and a deprecation message string into it, then returns 0.
// @fnv 0x00dba5d0
// pdb: hkSerializeDeprecated::loadOldPackfile | hkSerializeDeprecated.obj | retail, vtable slot, high
// pdb params: sr, details, errorOut
int __stdcall ReportDeprecatedSerializeLoad(int sr, int details, int errorOut)
{
    if (errorOut)
    {
        *(int*)errorOut = 7;
        *(hkStringPtr*)(errorOut + 4) =
            "Call hkSerializeDeprecated::initDeprecated() to include loading support for this file";
    }
    return 0;
}

// @fnv 0x00dba5b0
// src: GUESS 0x00dba5b0 (confidence: high)
int __stdcall Hkserializedeprecated_ReturnOne(int a, int b, int c, int d, int e)
{
    return 1;
}

// @fnv 0x00dba5c0
// src: GUESS 0x00dba5c0 (confidence: high)
int __stdcall Object_ReturnZero_00dba5c0(int a)
{
    return 0;
}
