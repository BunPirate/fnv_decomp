#pragma once

#include "bhkGenericConstraint.h"

// pdb: class bhkFixedConstraint, size 0x10, bases: bhkGenericConstraint, 0 members
class bhkFixedConstraint : public bhkGenericConstraint
{
public:
    bhkFixedConstraint();
    virtual ~bhkFixedConstraint();

    static NiObject* __cdecl CreateObject();
};
