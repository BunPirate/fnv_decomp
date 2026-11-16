#pragma once

#include "hkTransform.h"

// pdb: structure hkpSetLocalTransformsConstraintAtom, size 0x90, bases: hkpConstraintAtom, 2 members
class hkpSetLocalTransformsConstraintAtom
{
public:
    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkTransform m_transformA; // src: XBOX_RETAIL_PDB +0x10 (old: m_kBodyALocalFrame)
    hkTransform m_kBodyBLocalFrame;
};
