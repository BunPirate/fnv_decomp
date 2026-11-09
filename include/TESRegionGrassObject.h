#pragma once

#include "TESRegionObjectBase.h"

class TESGrass;
class TESLandTexture;

// pdb: class TESRegionGrassObject, size 0xc, bases: TESRegionObjectBase, 2 members
class TESRegionGrassObject : public TESRegionObjectBase
{
public:
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();

    TESGrass* pObject;
    TESLandTexture* pParent;

    void AssignLandTexture(TESLandTexture* texture);
};
