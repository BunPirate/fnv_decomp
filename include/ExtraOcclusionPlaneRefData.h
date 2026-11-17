#pragma once

#include "BSExtraData.h"

class PatrolReferenceData;

// pdb: class ExtraOcclusionPlaneRefData, size 0x10, bases: BSExtraData, 1 members
class ExtraOcclusionPlaneRefData : public BSExtraData
{
public:
    ExtraOcclusionPlaneRefData();
    virtual ~ExtraOcclusionPlaneRefData();
    virtual bool Compare(BSExtraData* extra);

    void Reset();
    void SetSelectedMagicItem(PatrolReferenceData*);
    void FUN_00420060();
    void* FUN_00420030(unsigned int flags);

    PatrolReferenceData* pData;
};
