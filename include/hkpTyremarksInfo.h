#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpTyremarksWheel;

// pdb: class hkpTyremarksInfo, size 0x1c, bases: hkReferencedObject, 3 members
class hkpTyremarksInfo : public hkReferencedObject
{
public:
    virtual ~hkpTyremarksInfo() throw();
    virtual void vf03();
    virtual void vf04();

    void updateTyremarksInfo(float timestep, void* vehicle); // exe: 0x00e39fd0

    hkReal m_minTyremarkEnergy; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMinTyremarkPointDistance)
    hkReal m_maxTyremarkEnergy; // src: XBOX_RETAIL_PDB +0xc (old: m_fMaxTyremarkPointDistance)
    hkArray<hkpTyremarksWheel*> m_tyremarksWheel; // src: XBOX_RETAIL_PDB +0x10 (old: m_kTyremarksWheels)
};
