#pragma once

#include "hkpConstraintData.h"

// pdb: class hkpConstraintChainData, size 0xc, bases: hkpConstraintData, 0 members
class hkpConstraintChainData : public hkpConstraintData
{
public:
    hkpConstraintChainData();
    hkpConstraintChainData(FinishingFlag flag);
};
