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

    NiAVObject* m_pkColliderObj; // src: XBOX_RETAIL_PDB +0x2c (old: m_pkColliderObject)
    float m_fWidth; // src: XBOX_RETAIL_PDB +0x30 (old: m_fOriginX)
    float m_fHeight; // src: XBOX_RETAIL_PDB +0x34 (old: m_fOriginZ)
    NiPoint3 m_kXAxis; // src: XBOX_RETAIL_PDB +0x38 (old: m_kFirstVector)
    NiPoint3 m_kYAxis; // src: XBOX_RETAIL_PDB +0x44 (old: m_kSecondPlaneVector)
    float m_fHalfSqScaledWidth; // src: XBOX_RETAIL_PDB +0x50 (old: m_fWidthSquared)
    float m_fHalfSqScaledHeight; // src: XBOX_RETAIL_PDB +0x54 (old: m_fHeightSquared)
    NiPlane m_kPlane; // src: XBOX_RETAIL_PDB +0x58 (old: m_kHalfSpacePlane)
    NiPoint3 m_kPosition; // src: XBOX_RETAIL_PDB +0x68 (old: m_kPathOffset)
    unsigned char layoutPadding74[12];
    NiMatrix3 m_kRotation; // src: XBOX_RETAIL_PDB +0x80 (old: m_kRotationMatrix)
    unsigned char unkA4[12];
    NiTransform m_kLastColliderTransform; // src: XBOX_RETAIL_PDB +0xb0 (old: m_kFirstTransform)
    unsigned char unkE4[12];
    NiTransform m_kLastPSysTransform; // src: XBOX_RETAIL_PDB +0xf0 (old: m_kSecondTransform)
    unsigned char unk124[12];
};
