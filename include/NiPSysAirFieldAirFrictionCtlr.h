#pragma once

#include "NiPSysModifierFloatCtlr.h"

// pdb: class NiPSysAirFieldAirFrictionCtlr, size 0x40, bases: NiPSysModifierFloatCtlr, 0 members
class NiPSysAirFieldAirFrictionCtlr : public NiPSysModifierFloatCtlr
{
public:
    void CopyMemberData(NiPSysAirFieldAirFrictionCtlr*, CloningProcess&);
    void GetTargetFloatValue_00c307d0(float& rfValue);
};
