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
    hkVector4 m_top; // src: XBOX_RETAIL_PDB +0x60 (old: m_fMaximumV)
    hkReal m_bottom; // src: XBOX_RETAIL_PDB +0x70 (old: m_fSphereRadius)
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int m_radius; // src: XBOX_RETAIL_PDB +0x80 (old: unk80)

    void buildGeometry();
};
