#pragma once

#include "NiBoundingVolume.h"
#include "NiSphere.h"

// pdb: class NiSphereBV, size 0x14, bases: NiBoundingVolume, 1 members
class NiSphereBV : public NiBoundingVolume
{
public:
    NiSphere m_kSphere;

    virtual void LoadBinary(NiStream& kStream) override;
    virtual void __thiscall SaveBinary(NiStream& kStream) override;

    void CopySphereFrom(const NiBoundingVolume&);
};
