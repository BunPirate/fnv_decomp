#pragma once

// pdb: structure hkpTwistLimitConstraintAtom, size 0x14, bases: hkpConstraintAtom, 6 members
class hkpTwistLimitConstraintAtom
{
public:
    unsigned short m_type;
    unsigned char m_isEnabled; // src: XBOX_RETAIL_PDB +0x2 (old: m_bLimitEnabled)
    unsigned char m_twistAxis; // src: XBOX_RETAIL_PDB +0x3 (old: m_ucTwistAxis)
    unsigned char m_refAxis; // src: XBOX_RETAIL_PDB +0x4 (old: m_ucReferenceAxis)
    unsigned char unk05;
    unsigned short unk06;
    float m_minAngle; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMinAngle)
    float m_maxAngle; // src: XBOX_RETAIL_PDB +0xc (old: m_fMaxAngle)
    float m_angularLimitsTauFactor; // src: XBOX_RETAIL_PDB +0x10 (old: m_fAngularLimitsTauFactor)
};
