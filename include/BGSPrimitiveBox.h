#pragma once

#include "BGSPrimitive.h"
#include "NiPoint3.h"

// pdb: class BGSPrimitiveBox, size 0x4c, bases: BGSPrimitive, 1 members
class BGSPrimitiveBox : public BGSPrimitive
{
public:
    BGSPrimitiveBox();
    virtual ~BGSPrimitiveBox();
    virtual void vf06();

    void NormalizeRadii(NiPoint3& radii);
    void SetColor(NiColorA& aColor);
    void Build();
    void SetSize(int value);
    void SetPosition(NiPoint3& position);

    void* pFacePlanes[6];
};
