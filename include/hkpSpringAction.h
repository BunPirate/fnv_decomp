#pragma once

#include "hkpBinaryAction.h"
#include "hkVector4.h"
#include "hkBool.h"

typedef float hkReal;

// pdb: class hkpSpringAction, size 0x60, bases: hkpBinaryAction, 8 members
class hkpSpringAction : public hkpBinaryAction
{
public:
    hkVector4 m_lastForce; // src: XBOX_RETAIL_PDB +0x20 (old: m_kLastForce)
    hkVector4 m_positionAinA; // src: XBOX_RETAIL_PDB +0x30 (old: m_kPositionA)
    hkVector4 m_positionBinB; // src: XBOX_RETAIL_PDB +0x40 (old: m_kPositionB)
    hkReal m_restLength; // src: XBOX_RETAIL_PDB +0x50 (old: m_fRestLength)
    hkReal m_strength; // src: XBOX_RETAIL_PDB +0x54 (old: m_fSpringStrength)
    hkReal m_damping; // src: XBOX_RETAIL_PDB +0x58 (old: m_fMotorDamping)
    hkBool m_onCompression; // src: XBOX_RETAIL_PDB +0x5c (old: m_bSpringEnabled)
    hkBool m_onExtension; // src: XBOX_RETAIL_PDB +0x5d (old: m_bElastic)
    char pad5E[0x2];
};
