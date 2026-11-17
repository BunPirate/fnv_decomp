#pragma once

#include "NiFloatInterpController.h"

// pdb: class NiAlphaController, size 0x38, bases: NiFloatInterpController, 0 members
class NiAlphaController : public NiFloatInterpController
{
public:
    void CopyMemberData(NiAlphaController* clone, CloningProcess& process);
};
