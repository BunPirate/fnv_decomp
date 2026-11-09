#pragma once

#include "BSExtraData.h"
#include "NiPoint3.h"

class TESObjectREFR;

// pdb: class ExtraEditorRefMoveData, size 0x30, bases: BSExtraData, 3 members
class ExtraEditorRefMoveData : public BSExtraData
{
public:
    NiPoint3 realAngle;
    NiPoint3 realLocation;
    NiPoint3 oldLocation;

    ExtraEditorRefMoveData(TESObjectREFR* apRef);
};
