#pragma once

#include "BSExtraData.h"

// pdb: class ExtraHotKey, size 0x10, bases: BSExtraData, 1 members
class ExtraHotKey : public BSExtraData
{
public:
    ExtraHotKey();
    ExtraHotKey(char key);
    bool Compare(BSExtraData* apCompare);
    bool Compare_00432540(BSExtraData* apCompare);

    char cKey;
};
