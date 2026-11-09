#pragma once

#include "NiPSysCollider.h"
#include "NiPlane.h"
#include "NiPoint3.h"
#include "NiMatrix3.h"
#include "NiTransform.h"

// pdb: class NiPSysPlanarCollider, size 0x130, bases: NiPSysCollider, 12 members
class NiPSysPlanarCollider : public NiPSysCollider
{
public:
    virtual void LoadBinary(NiStream& kStream);

    void CopyMemberData(NiPSysPlanarCollider* destination, CloningProcess& cloning);

    NiAVObject* m_pkColliderObj;
    float m_fWidth;
    float m_fHeight;
    NiPoint3 m_kXAxis;
    NiPoint3 m_kYAxis;
    float m_fHalfSqScaledWidth;
    float m_fHalfSqScaledHeight;
    NiPlane m_kPlane;
    NiPoint3 m_kPosition;
    unsigned char layoutPadding74[12];
    NiMatrix3 m_kRotation;
    unsigned char unkA4[12];
    NiTransform m_kLastColliderTransform;
    unsigned char unkE4[12];
    NiTransform m_kLastPSysTransform;
    unsigned char unk124[12];
};
