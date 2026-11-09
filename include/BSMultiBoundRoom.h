#pragma once

#include "BSMultiBoundNode.h"

// pdb: class BSMultiBoundRoom, size 0x120 (here 0xb4), bases: BSMultiBoundNode, 5 members
class BSMultiBoundRoom : public BSMultiBoundNode
{
public:
    void* TESCombatStyle_GetAdvancedData();
};
