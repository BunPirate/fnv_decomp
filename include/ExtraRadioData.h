#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

// pdb: class ExtraRadioData, size 0x1c, bases: BSExtraData, 1 members
class ExtraRadioData : public BSExtraData
{
public:
    struct RadioData
    {
        void RADIO_DATA_Copy(RadioData* other);

        char unk00[0x10];
    };

    ExtraRadioData();
    virtual ~ExtraRadioData();

    bool CompareRadioData(BSExtraData* extra);
    TESObjectCELL* DoorTeleportData_GetTeleportCell();

    union
    {
        unsigned char unk0C[0x10];
        RadioData data;
    };
};
