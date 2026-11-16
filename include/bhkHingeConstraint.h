#pragma once

#include "bhkConstraint.h"

// pdb: class bhkHingeConstraint, size 0x10, bases: bhkConstraint, 0 members
class bhkHingeConstraint : public bhkConstraint
{
public:
    virtual const NiRTTI* GetRTTI() const;

    static NiObject* __cdecl CreateObject();
    unsigned int GetInstanceSize();
    void* FUN_009ba520(unsigned int);

    static const NiRTTI bhkHingeConstraint_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01268438 (old: g_01268438/ms_kRTTI)
};
