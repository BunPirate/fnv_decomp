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
    hkVector4 m_normal;
    hkVector4 m_perp;
    hkReal m_center;
    hkReal m_fThetaMax;
    hkReal m_fSphereRadius;
    int m_iNumSegments;
    int m_thetaMin;
};
