#pragma once

#include "BSExtraData.h"
class BGSEncounterZone;

class __declspec(align(8)) ExtraEncounterZone : public BSExtraData
{
public:
    ExtraEncounterZone();

    virtual bool Compare(BSExtraData* extra);

    BGSEncounterZone* pZone; // src: XBOX_RETAIL_PDB +0xc (old: m_pEncounterZone)
};
