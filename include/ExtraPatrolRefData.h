#pragma once

#include "BSExtraData.h"

class PatrolRefData;

// pdb: class ExtraPatrolRefData, size 0x10, bases: BSExtraData, 1 members
class ExtraPatrolRefData : public BSExtraData
{
public:
    virtual ~ExtraPatrolRefData();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraPatrolRefData();
    void SetSelectedMagicItem(PatrolRefData*);
    bool vf01(ExtraPatrolRefData* apCompare);
    bool Compare_0041fd20(ExtraPatrolRefData* apCompare);
    void* __thiscall FUN_0041fd80(unsigned int flags);
    void __thiscall FUN_0041fdb0();
    void ReleaseStorage_0041fe10();

    PatrolRefData* pPatrolData; // src: XBOX_RETAIL_PDB +0xc (old: pData)
};
