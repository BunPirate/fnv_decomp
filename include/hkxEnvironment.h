#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkxEnvironmentVariable;

// pdb: class hkxEnvironment, size 0x14, bases: hkReferencedObject, 1 members
class hkxEnvironment : public hkReferencedObject
{
public:
    hkArray<hkxEnvironmentVariable> m_variables; // src: XBOX_RETAIL_PDB +0x8 (old: m_kVariables)
};
