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

    hkReal m_minTyremarkEnergy;
    hkReal m_maxTyremarkEnergy;
    hkArray<hkpTyremarksWheel*> m_tyremarksWheel;
};
