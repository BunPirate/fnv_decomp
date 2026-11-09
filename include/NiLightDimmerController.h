#pragma once

#include "NiFloatInterpController.h"

// pdb: class NiLightDimmerController, size 0x38, bases: NiFloatInterpController, 0 members
class NiLightDimmerController : public NiFloatInterpController
{
public:
    void GetLightDimmer(float& fValue);
};
