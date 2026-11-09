#pragma once

#include "hkpFirstPersonGun.h"
#include "hkVector4.h"

// pdb: class hkpBallGun, size 0x60, bases: hkpFirstPersonGun, 7 members
class hkpBallGun : public hkpFirstPersonGun
{
public:
    hkReal m_bulletRadius;
    hkReal m_bulletVelocity;
    hkReal m_bulletMass;
    hkReal m_damageMultiplier;
    hkInt32 m_maxBulletsInWorld;
    char pad34[0xC];
    hkVector4 m_bulletOffsetFromCenter;
    void* m_addedBodies;
    char pad54[0xC];
};
