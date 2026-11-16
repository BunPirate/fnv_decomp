#pragma once

#include "hkpAction.h"

class hkpEntity;

// pdb: class hkpBinaryAction, size 0x20, bases: hkpAction, 2 members
class hkpBinaryAction : public hkpAction
{
public:
    void FUN_00cf4d80(int entityA, int entityB, int userData);

    hkpEntity* m_entityA; // src: XBOX_RETAIL_PDB +0x18 (old: m_pEntityA)
    hkpEntity* m_entityB; // src: XBOX_RETAIL_PDB +0x1c (old: m_pEntityB)
};
