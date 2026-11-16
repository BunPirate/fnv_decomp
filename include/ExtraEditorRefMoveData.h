#pragma once

#include "BSExtraData.h"
#include "NiPoint3.h"

class TESObjectREFR;

// pdb: class ExtraEditorRefMoveData, size 0x30, bases: BSExtraData, 3 members
class ExtraEditorRefMoveData : public BSExtraData
{
public:
    NiPoint3 realAngle; // src: XBOX_RETAIL_PDB +0xc (old: kRealLocation)
    NiPoint3 realLocation; // src: XBOX_RETAIL_PDB +0x18 (old: kRealAngle)
    NiPoint3 oldLocation; // src: XBOX_RETAIL_PDB +0x24 (old: kOldLocation)

    ExtraEditorRefMoveData(TESObjectREFR* apRef);
};
