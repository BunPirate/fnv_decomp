#pragma once

#include "BSExtraData.h"

// pdb: class ExtraRank, size 0x10, bases: BSExtraData, 1 members
class ExtraRank : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;

    int m_iRank;
};
