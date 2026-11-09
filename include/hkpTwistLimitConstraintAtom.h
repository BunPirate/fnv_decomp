#pragma once

// pdb: structure hkpTwistLimitConstraintAtom, size 0x14, bases: hkpConstraintAtom, 6 members
class hkpTwistLimitConstraintAtom
{
public:
    unsigned short m_type;
    unsigned char m_isEnabled;
    unsigned char m_twistAxis;
    unsigned char m_refAxis;
    unsigned char unk05;
    unsigned short unk06;
    float m_minAngle;
    float m_maxAngle;
    float m_angularLimitsTauFactor;
};
