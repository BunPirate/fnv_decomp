#pragma once

#include "bhkCollisionObject.h"

// pdb: class bhkBlendCollisionObject, size 0x2c, bases: bhkCollisionObject, 6 members
class bhkBlendCollisionObject : public bhkCollisionObject
{
  public:
    bhkBlendCollisionObject();

    static NiObject* __cdecl CreateObject();

    unsigned char unk0C[8];
    unsigned char bRagdollUpdated;
    char m_pad15[3];
    float fHeirGain;
    float fVelGain;
    int ePrevType;
    int pStoredWorld;
    int iForceAddCount;
};
