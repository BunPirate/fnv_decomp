#pragma once

#include "BSExtraData.h"

// pdb: class ExtraSpecialRenderFlags, size 0x14, bases: BSExtraData, 2 members
class ExtraSpecialRenderFlags : public BSExtraData
{
public:
    virtual ~ExtraSpecialRenderFlags();
    virtual bool Compare(BSExtraData* apCompare);
    virtual void vf02();
    virtual void Copy_00438330(BSExtraData* pExtraData);

    bool Compare_004382a0(BSExtraData* apCompare);
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);

    unsigned int m_flags;
    float m_fRenderValue;
};
