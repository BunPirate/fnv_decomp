#pragma once

#include "hkpFirstPersonGun.h"
#include "hkVector4.h"

// pdb: class hkpBallGun, size 0x60, bases: hkpFirstPersonGun, 7 members
class hkpBallGun : public hkpFirstPersonGun
{
public:
    hkReal m_bulletRadius; // src: XBOX_RETAIL_PDB +0x20 (old: m_fBulletRadius)
    hkReal m_bulletVelocity; // src: XBOX_RETAIL_PDB +0x24 (old: m_fBulletVelocity)
    hkReal m_bulletMass; // src: XBOX_RETAIL_PDB +0x28 (old: m_fBulletMass)
    hkReal m_damageMultiplier; // src: XBOX_RETAIL_PDB +0x2c (old: m_fBulletSpread)
    hkInt32 m_maxBulletsInWorld; // src: XBOX_RETAIL_PDB +0x30 (old: m_iBulletBatchCount)
    char pad34[0xC];
    hkVector4 m_bulletOffsetFromCenter; // src: XBOX_RETAIL_PDB +0x40 (old: m_kBulletDirection)
    void* m_addedBodies; // src: XBOX_RETAIL_PDB +0x50 (old: m_pBulletQueue)
    char pad54[0xC];
};
