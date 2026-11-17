#pragma once

#include <stddef.h>
#include "QuantizedFloat8.h"

struct ClassMemberDescriptor;

// pdb: class hkContactPointMaterial, size 0x8, 5 members
class hkContactPointMaterial
{
public:
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };

    unsigned int m_userData; // src: XBOX_RETAIL_PDB +0x0 (old: m_ulUserData)
    QuantizedFloat8 m_friction; // src: XBOX_RETAIL_PDB +0x4 (old: m_fSlipAngle)
    unsigned char m_restitution; // src: XBOX_RETAIL_PDB +0x5 (old: m_fElasticity)
    QuantizedFloat8 m_maxImpulse; // src: XBOX_RETAIL_PDB +0x6 (old: m_usFlags)
    unsigned char m_flags;

    static const ClassMemberDescriptor Members[];

    hkContactPointMaterial();
    void reset();
    float getFriction() const;
    static void* __cdecl operator new(size_t nbytes);
};
