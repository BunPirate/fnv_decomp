#pragma once

#include "NiBSplineInterpolator.h"
#include "NiColorA.h"

// pdb: class NiBSplineColorInterpolator, size 0x34, bases: NiBSplineInterpolator, 3 members
class NiBSplineColorInterpolator : public NiBSplineInterpolator
{
public:
    unsigned int GetControlHandle(unsigned short usChannel);
    void CopyTo(NiBSplineColorInterpolator* source, CloningProcess& proc);

    NiColorA m_kColorAValue; // src: XBOX_RETAIL_PDB +0x1c (old: m_kDiffuseColor)
    unsigned int m_kColorACPHandle;
    unsigned int m_kBasisHandle; // src: XBOX_RETAIL_PDB +0x30 (old: unk30)
};
