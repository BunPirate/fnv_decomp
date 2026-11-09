#pragma once

#include "BSExtraData.h"

// pdb: class ExtraLeveledItem, size 0x14, bases: BSExtraData, 2 members
struct ExtraLeveledItem : public BSExtraData
{
public:
    virtual ~ExtraLeveledItem();
    bool Compare(BSExtraData* extra) override;

    ExtraLeveledItem(int aIndex);

    int iIndex;
    bool m_bIsLeveledItem;
    unsigned char layoutPadding11[3];
};
