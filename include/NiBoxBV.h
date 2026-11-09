#pragma once

#include "NiBoundingVolume.h"

// pdb: class NiBoxBV, size 0x40 (here 0x4), bases: NiBoundingVolume, 1 members
class NiBoxBV : public NiBoundingVolume
{
public:
    NiBoxBV();

    void __thiscall SaveBinary(NiStream& kStream);
    void Copy(const NiBoundingVolume& kABV);
};
