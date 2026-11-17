#pragma once

#include "SymGen.h"
#include "NiPoint3.h"

// pdb: class Normal, size 0x14, bases: SymGen, 0 members
class Normal : public SymGen
{
public:
    Normal();
    Normal(const NiPoint3& value);
    virtual ~Normal();
    virtual float Next() override;
    virtual char* Name() override;
    virtual float Density(float x) const override;
    virtual FloatIntPair* vf04(FloatIntPair* value) override;
    virtual FloatIntPair* vf05(FloatIntPair* value) override;

    Normal& operator=(const Normal& value);
};
