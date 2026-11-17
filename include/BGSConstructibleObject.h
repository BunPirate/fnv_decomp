#pragma once

#include "TESObjectMISC.h"

// pdb: class BGSConstructibleObject, size 0xb4, bases: TESObjectMISC, 2 members
class BGSConstructibleObject : public TESObjectMISC
{
public:
    BGSConstructibleObject();
    virtual ~BGSConstructibleObject();

    void InitializeData();
    void* __thiscall FUN_004f94b0();
    void* __thiscall Destroy(unsigned int flags);

    void* pRequiredItems; // src: XBOX_RETAIL_PDB +0xac (old: m_pCreatedObject)
    void* pCreatedItem; // src: XBOX_RETAIL_PDB +0xb0 (old: m_pWorkbenchKeyword)
};
