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
    hkVector4 m_rotationAxis;
    hkVector4 m_upAxis;
    hkReal m_strength;
    hkReal m_damping;
    char pad48[0x8];
};
