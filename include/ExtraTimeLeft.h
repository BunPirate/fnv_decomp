#pragma once

#include "BSExtraData.h"

// pdb: class ExtraTimeLeft, size 0x10, bases: BSExtraData, 1 members
class ExtraTimeLeft : public BSExtraData
{
public:
    ExtraTimeLeft(float time);

    bool Compare(BSExtraData* extra) override;
    bool Compare_00431ef0(BSExtraData* extra);

    float fTime;
};
