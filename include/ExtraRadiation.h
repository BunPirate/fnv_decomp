#pragma once

#include "BSExtraData.h"

// pdb: class ExtraRadiation, size 0x10, bases: BSExtraData, 1 members
class ExtraRadiation : public BSExtraData
{
public:
    virtual ~ExtraRadiation();
    bool Compare(BSExtraData* apCompare) override;

    ExtraRadiation();
    ExtraRadiation(float afRadiation);
    bool Compare_00436c40(BSExtraData* apCompare);

    float fRadiation; // src: XBOX_RETAIL_PDB +0xc (old: m_fRadiation)
};
