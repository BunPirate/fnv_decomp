#pragma once

#include "BSExtraData.h"

// pdb: class ExtraUses, size 0x10, bases: BSExtraData, 1 members
class ExtraUses : public BSExtraData
{
public:
    virtual ~ExtraUses();
    virtual bool Compare(BSExtraData* apCompare);

    unsigned char m_ucUses;
    unsigned char unk0D[3];
};
