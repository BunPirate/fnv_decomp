#pragma once

#include "bhkBlendCollisionObject.h"

// pdb: class WeaponObject, size 0x2c, bases: bhkBlendCollisionObject, 0 members
class WeaponObject : public bhkBlendCollisionObject
{
  public:
    void UpdateWeapon(bool abEnable, void* aOwnerFilter, NiAVObject* apRoot3d, bool abDefaultKeyframed);
    void AttachWeapon();
    void* GetTranslation(void* translation);
};
