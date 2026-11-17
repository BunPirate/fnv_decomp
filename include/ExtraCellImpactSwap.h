#pragma once

#include "BSExtraData.h"

class CellImpactSwapValue;

// pdb: class ExtraCellImpactSwap, size 0x10, bases: BSExtraData, 1 members
class ExtraCellImpactSwap : public BSExtraData
{
public:
    ExtraCellImpactSwap();
    virtual ~ExtraCellImpactSwap();
    bool Compare(BSExtraData* extra) override;

    void FUN_0040f210();
    void* FUN_0040f1e0(unsigned int flags);
    bool ExtraCellImpactSwap_Compare(BSExtraData* apCompare);

    CellImpactSwapValue* pImpactSwap; // src: XBOX_RETAIL_PDB +0xc (old: m_pCellImpactSwapValue)
};
