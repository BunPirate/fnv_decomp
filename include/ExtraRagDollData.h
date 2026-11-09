#pragma once

#include "BSExtraData.h"

class RagDollData;

// pdb: class ExtraRagDollData, size 0x10, bases: BSExtraData, 1 members
class ExtraRagDollData : public BSExtraData
{
public:
    virtual ~ExtraRagDollData();

    ExtraRagDollData();
    bool CompareRagDollData(BSExtraData* apCompare);

    RagDollData* m_pRagDollData;
};
