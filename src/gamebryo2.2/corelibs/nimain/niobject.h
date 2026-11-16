#ifndef FNV_NIOBJECT_UNIT_H
#define FNV_NIOBJECT_UNIT_H

#include "../../../../include/NiObject.h"

class GlobalObject_00869db0
{
  public:
    unsigned int GetSize();
};
// 0x0045a120 returns the size of the array at +0x1ec (tes.cpp's recipe binds it as TESDataHandler::GetAddonNodeCount);
// it was declared as a BSFaceGenMorphData method before.
class FUN_0045a120_Owner
{
  public:
    unsigned int GetArraySize();

  private:
    char unknown_000[0x1ec];
    GlobalObject_00869db0 array_1ec;
};

// @fnv 0x0045a120
// pdb: D3DArrayTexture::GetArraySize | d3dx9tex.obj | debug, upstream name already matches, high, not renamed: the link is the existing name itself, so its spelling stays
unsigned int FUN_0045a120_Owner::GetArraySize()
{
    return array_1ec.GetSize();
}

// @fnv 0x00653290
// pdb: bhkBlendCollisionObject::GetbhkBlendCollisionObject | ActorLook.obj | debug, call graph, medium
// pdb params: apObject
// pdb locals: po
NiObject* NiObject::DynamicCast(const NiRTTI* rtti)
{
    return IsKindOfType(rtti) ? this : 0;
}

#endif
