#pragma once

#include "PosGen.h"

// pdb: class SymGen, size 0x14, bases: PosGen, 0 members
class SymGen : public PosGen
{
public:
    virtual ~SymGen();
    virtual float Next();
};
