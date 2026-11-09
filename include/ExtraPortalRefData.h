#pragma once

#include "BSExtraData.h"

class LinkedReferencePair;

// pdb: class ExtraPortalRefData, size 0x10, bases: BSExtraData, 1 members
class ExtraPortalRefData : public BSExtraData
{
public:
    LinkedReferencePair* pData;

    ExtraPortalRefData();
    virtual ~ExtraPortalRefData();
    virtual bool Compare(BSExtraData* apCompare);

    void ExtraOcclusionPlaneRefData_Clear();
    bool Compare_00420300(BSExtraData* apCompare);
    void* __thiscall FUN_00420380(unsigned int flags);
    void __thiscall FUN_004203b0();
};
