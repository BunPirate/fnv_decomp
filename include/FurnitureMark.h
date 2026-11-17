#pragma once

#include "NiStream.h"

class NiPoint3;

// pdb: class FurnitureMark, size 0x10, 3 members
class FurnitureMark
{
public:
    float Position; // src: XBOX_RETAIL_PDB +0x0 (old: fX)
    float fY;
    float fZ;
    unsigned short sHeading; // src: XBOX_RETAIL_PDB +0xc (old: usHeading)
    unsigned char cNumber; // src: XBOX_RETAIL_PDB +0xe (old: cMarkerType)

    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    NiPoint3* FUN_006815c0();   // 0x006815c0 (returns the position)
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
};
