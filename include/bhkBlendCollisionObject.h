#pragma once

#include "bhkCollisionObject.h"

// pdb: class bhkBlendCollisionObject, size 0x2c, bases: bhkCollisionObject, 6 members
class bhkBlendCollisionObject : public bhkCollisionObject
{
  public:
    bhkBlendCollisionObject();

    static NiObject* __cdecl CreateObject();

    unsigned char unk0C[8];
    unsigned char bRagdollUpdated; // src: XBOX_RETAIL_PDB +0x14 (old: m_flag14)
    char m_pad15[3];
    float fHeirGain; // src: XBOX_RETAIL_PDB +0x18 (old: m_f18)
    float fVelGain; // src: XBOX_RETAIL_PDB +0x1c (old: m_f1c)
    int ePrevType; // src: XBOX_RETAIL_PDB +0x20 (old: m_i20)
    int pStoredWorld; // src: XBOX_RETAIL_PDB +0x24 (old: m_i24)
    int iForceAddCount; // src: XBOX_RETAIL_PDB +0x28 (old: m_i28)
};
