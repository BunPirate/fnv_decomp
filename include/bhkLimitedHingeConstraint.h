#pragma once

#include "bhkConstraint.h"

class bhkLimitedHingeOutput;

// pdb: class bhkLimitedHingeConstraint, size 0x10, bases: bhkConstraint, 0 members
class bhkLimitedHingeConstraint : public bhkConstraint
{
public:
    void PopulateOutput(bhkLimitedHingeOutput*);
    const float* GetFirst() const;
    const float* GetSecond() const;

    static NiObject* __cdecl CreateObject();
};
