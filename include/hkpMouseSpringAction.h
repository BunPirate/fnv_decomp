#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"
#include "hkaAnimation.h"

typedef unsigned int hkUint32;

// pdb: class hkpMouseSpringAction, size 0x60, bases: hkpUnaryAction, 8 members
class hkpMouseSpringAction : public hkpUnaryAction
{
public:
    void ApplySpringForce(void*);

    char pad1C[0x4];
    hkVector4 m_positionInRbLocal; // src: XBOX_RETAIL_PDB +0x20 (old: m_kMousePositionInWorld)
    hkVector4 m_mousePositionInWorld; // src: XBOX_RETAIL_PDB +0x30 (old: m_kGrabPointInBodySpace)
    hkReal m_springDamping; // src: XBOX_RETAIL_PDB +0x40 (old: m_fSpringDamping)
    hkReal m_springElasticity; // src: XBOX_RETAIL_PDB +0x44 (old: m_fSpringElasticity)
    hkReal m_maxRelativeForce; // src: XBOX_RETAIL_PDB +0x48 (old: m_fMaxRelativeForce)
    hkReal m_objectDamping; // src: XBOX_RETAIL_PDB +0x4c (old: m_fTau)
    hkUint32 m_shapeKey; // src: XBOX_RETAIL_PDB +0x50 (old: m_uiCollisionShapeKey)
    hkArray<char> m_applyCallbacks; // src: XBOX_RETAIL_PDB +0x54 (old: m_kAppliedCallbacks)
};
