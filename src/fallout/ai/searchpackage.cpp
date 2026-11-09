#include "../../../include/SearchPackage.h"

// src/fallout/ai/searchpackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/searchpackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void __cdecl _Deallocate(void*);

// Calls the destructor, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x009f6680
// pdb: SearchPackage::`scalar deleting destructor' | SearchPackage.obj | retail, vtable slot, high
void* SearchPackage::DestroyIfFlagged(unsigned int flags)
{
    SearchPackage::~SearchPackage();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Initializes a TESPackage-derived object: sets position from a, b, c, stores d, and zeroes the float fields.
// @fnv 0x009f66b0
// pdb: SearchPackage::SearchPackage | SearchPackage.obj | retail, upstream name already matches, high
SearchPackage::SearchPackage(float afX, float afY, float afZ, int aiValue, int aiUnused) : TESPackage(), LocationCenter(), coverRequest()
{
    fSearchStageTimer = 0.0f;
    iAlertLevel = 1;
    fCommentTimer = 0.0f;
    fIdleTimer = 0.0f;
    LocationCenter.y = afY;
    LocationCenter.x = afX;
    LocationCenter.z = afZ;
    pThreatObject = aiValue;
    bLocationStart = 1;
    iCurrentCover = 0;
}

// Destructor for the package class; the body is empty, leaving member destruction to the compiler-generated code.
// @fnv 0x009f67b0
// pdb: SearchPackage::~SearchPackage | SearchPackage.obj | debug, upstream name already matches, high
SearchPackage::~SearchPackage()
{}
