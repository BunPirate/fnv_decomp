#pragma once

#include "NiPSysEmitterCtlr.h"

// pdb: class BSPSysMultiTargetEmitterCtlr, size 0x64 (here 0x5c), bases: NiPSysEmitterCtlr, 2 members
class BSPSysMultiTargetEmitterCtlr : public NiPSysEmitterCtlr
{
public:
    virtual void LinkObject(NiStream& kStream);
};
