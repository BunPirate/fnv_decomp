#pragma once

#include "NiPSysModifier.h"

class NiAVObject;

// pdb: class NiPSysFieldModifier, size 0x30, bases: NiPSysModifier, 6 members
class NiPSysFieldModifier : public NiPSysModifier
{
public:
    NiAVObject* m_pkFieldObj;
    float m_fMagnitude;
    float m_fAttenuation;
    bool m_bUseMaxDistance;
    float m_fMaxDistance;
    float m_fMaxDistanceSqr;

    NiPSysFieldModifier();
    virtual ~NiPSysFieldModifier();

    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;

    NiObject* Clone(CloningProcess& process);
    NiPSysFieldModifier* Destroy(unsigned int flags);
    void CopyMemberData(NiPSysFieldModifier* pkDest, CloningProcess& kCloning);
};
