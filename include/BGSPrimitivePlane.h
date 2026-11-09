#pragma once

#include "BGSPrimitive.h"

// pdb: class BGSPrimitivePlane, size 0x34, bases: BGSPrimitive, 0 members
class BGSPrimitivePlane : public BGSPrimitive
{
public:
    BGSPrimitivePlane();
    virtual ~BGSPrimitivePlane();
    virtual void vf06();
    virtual void vf07();

    void SetColor(NiColorA& aColor);
    void Build();
    void NormalizeRadii(NiPoint3& radii);
};
