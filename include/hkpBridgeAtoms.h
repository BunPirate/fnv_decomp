#pragma once

#include "hkpBridgeConstraintAtom.h"

// pdb: structure hkpBridgeAtoms, size 0xc, 1 members
class hkpBridgeAtoms
{
public:
    hkpBridgeConstraintAtom m_bridgeAtom; // src: XBOX_RETAIL_PDB +0x0 (old: m_kBridgeAtom)

    // src: HAVOK_SRC (hkpBridgeAtoms: default and finish-loading constructors)
    hkpBridgeAtoms() {}
    hkpBridgeAtoms(FinishingFlag flag) : m_bridgeAtom(flag) {}
};
