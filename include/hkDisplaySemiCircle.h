#pragma once

#include "hkDisplayGeometry.h"
#include "hkVector4.h"

typedef float hkReal;

// pdb: class hkDisplaySemiCircle, size 0xa0, bases: hkDisplayGeometry, 7 members
class hkDisplaySemiCircle : public hkDisplayGeometry
{
public:
    hkDisplaySemiCircle(const hkVector4& center, const hkVector4& normal, const hkVector4& startPerp,
                        hkReal thetaMin, hkReal thetaMax, hkReal radius, int numSegments);

    void UpdateState_00de4950(hkReal radius, hkReal thetaMin, hkReal thetaMax, int numSegments,
                      const hkVector4& center, const hkVector4& normal, const hkVector4& startPerp);

    hkVector4 m_vHitNormal;
    hkVector4 m_normal; // src: XBOX_RETAIL_PDB +0x60 (old: m_kCenterPosition)
    hkVector4 m_perp; // src: XBOX_RETAIL_PDB +0x70 (old: m_kStartPerpendicular)
    hkReal m_center; // src: XBOX_RETAIL_PDB +0x80 (old: m_fThetaMin)
    hkReal m_fThetaMax;
    hkReal m_fSphereRadius;
    int m_iNumSegments;
    int m_thetaMin; // src: XBOX_RETAIL_PDB +0x90 (old: unk90)
};
