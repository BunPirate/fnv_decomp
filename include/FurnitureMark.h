#pragma once

#include "NiStream.h"

class NiPoint3;

// pdb: class FurnitureMark, size 0x10, 3 members
class FurnitureMark
{
public:
    float Position;
    float fY;
    float fZ;
    unsigned short sHeading;
    unsigned char cNumber;

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
