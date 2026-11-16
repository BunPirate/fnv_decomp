#pragma once

#include "NiPSysModifier.h"

class NiAVObject;

// pdb: class NiPSysFieldModifier, size 0x30, bases: NiPSysModifier, 6 members
class NiPSysFieldModifier : public NiPSysModifier
{
public:
    NiAVObject* m_pkFieldObj; // src: XBOX_RETAIL_PDB +0x18 (old: m_spFieldObject)
    float m_fMagnitude; // src: XBOX_RETAIL_PDB +0x1c (old: m_fInfluence)
    float m_fAttenuation; // src: XBOX_RETAIL_PDB +0x20 (old: m_fFieldAttenuation)
    bool m_bUseMaxDistance; // src: XBOX_RETAIL_PDB +0x24 (old: m_bEnableMaxDistance)
    float m_fMaxDistance; // src: XBOX_RETAIL_PDB +0x28 (old: m_fDistanceLimit)
    float m_fMaxDistanceSqr; // src: XBOX_RETAIL_PDB +0x2c (old: m_fFieldStrength)

    NiPSysFieldModifier();
    virtual ~NiPSysFieldModifier();

    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    NiObject* Clone(CloningProcess& process);
    NiPSysFieldModifier* Destroy(unsigned int flags);
    void CopyMemberData(NiPSysFieldModifier* pkDest, CloningProcess& kCloning);
};
