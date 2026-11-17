#pragma once

#include "BSExtraData.h"

// pdb: class ExtraLevCreaModifier, size 0x10, bases: BSExtraData, 1 members
class ExtraLevCreaModifier : public BSExtraData
{
public:
    virtual ~ExtraLevCreaModifier();
    virtual bool Compare(BSExtraData* apCompare) override;

    ExtraLevCreaModifier();

    float GetMultiplier();
    int GetAllBelowForce();

    int m_iModifier;
};
