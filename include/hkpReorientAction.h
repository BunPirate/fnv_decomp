#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"

class hkpPhantom;

typedef float hkReal;

// pdb: class hkpReorientAction, size 0x50, bases: hkpUnaryAction, 4 members
class hkpReorientAction : public hkpUnaryAction
{
public:
    hkpReorientAction(hkpEntity* entity, const hkVector4& rotationAxis, const hkVector4& upAxis,
                      float strength, float damping) throw();
    virtual ~hkpReorientAction() throw();
    hkpReorientAction* Clone(const hkArray<hkpEntity*>& newEntities,
                            const hkArray<hkpPhantom*>& newPhantoms) const;

    char pad1C[0x4];
    hkVector4 m_rotationAxis; // src: XBOX_RETAIL_PDB +0x20 (old: m_vRotationAxis)
    hkVector4 m_upAxis; // src: XBOX_RETAIL_PDB +0x30 (old: m_vUpAxis)
    hkReal m_strength; // src: XBOX_RETAIL_PDB +0x40 (old: m_fSpringStrength)
    hkReal m_damping; // src: XBOX_RETAIL_PDB +0x44 (old: m_fMotorDamping)
    char pad48[0x8];
};
