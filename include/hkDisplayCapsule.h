#pragma once

#include "hkDisplayGeometry.h"
#include "hkVector4.h"

typedef float hkReal;

// pdb: class hkDisplayCapsule, size 0x90, bases: hkDisplayGeometry, 5 members
class hkDisplayCapsule : public hkDisplayGeometry
{
public:
    hkDisplayCapsule(const hkVector4& top, const hkVector4& bottom, hkReal radius, int numSides,
                     int numHeightSegments);

    virtual ~hkDisplayCapsule() throw();
    virtual void vf03();
    virtual void vf04();

    hkVector4 m_fMinimumV;
    hkVector4 m_top;
    hkReal m_bottom;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int m_radius;

    void buildGeometry();
};
