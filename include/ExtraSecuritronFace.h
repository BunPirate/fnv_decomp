#pragma once

#include "BSExtraData.h"
#include "TESFullName.h"

class NiNode;

// pdb: class ExtraSecuritronFace, size 0x1c, bases: BSExtraData, 2 members
class ExtraSecuritronFace : public BSExtraData
{
public:
    virtual ~ExtraSecuritronFace();

    void* __thiscall FUN_0042cd40(unsigned int flags);
    void __thiscall FUN_0042cd70();

    BSStringT<char> GetStr1();
    BSStringT<char> GetStr2();
    void ApplyFace(NiNode* pNode);

    static char* GetPersonality();

    BSStringT<char> msPersonality;
    BSStringT<char> msMood;
};
