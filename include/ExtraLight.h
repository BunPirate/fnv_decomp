#pragma once

#include "BSExtraData.h"

class ReferenceLightData;

class __declspec(align(8)) ExtraLight : public BSExtraData
{
public:
    virtual ~ExtraLight();

    ReferenceLightData* pLight; // src: XBOX_RETAIL_PDB +0xc (old: apTargetLight)
};
