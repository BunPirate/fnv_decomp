// src/havok/physics/collide/filter/defaultconvexlist/hkpdefaultconvexlistfilter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/filter/defaultconvexlist/hkpdefaultconvexlistfilter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpDefaultConvexListFilter.h"

// @fnv 0x00cf6dc0
// src: HAVOK_LIB 0x00cf6dc0
// pdb: hkpDefaultConvexListFilter::getConvexListCollisionType | hkpDefaultConvexListFilter.obj | debug, upstream name already matches, high
// pdb params: convexListBody, otherBody, input
int __stdcall hkpDefaultConvexListFilter_getConvexListCollisionType(void* convexListBody, void* otherBody, void* input)
{
    int* p1 = *(int**)otherBody;
    int* p2 = *(int**)input;
    int idx = p1[3];
    unsigned int v = (unsigned int)p2[idx + 0x44];
    return (v >> 8) & 1;
}
