#pragma once

#include "bhkUnaryAction.h"
#include "BSSimpleList.h"
#include "NiPointer.h"

class LiquidActionInfo;
struct S1fc;

// pdb: class bhkLiquidAction, size 0x40, bases: bhkUnaryAction, 8 members
class bhkLiquidAction : public bhkUnaryAction
{
public:
    bhkLiquidAction();
    bhkLiquidAction(const LiquidActionInfo& arInfo);
    bhkLiquidAction(S1fc*);
    virtual ~bhkLiquidAction();
    virtual const NiRTTI* GetRTTI() const;

    void ConfigureBody(const LiquidActionInfo& arInfo);
    void* __thiscall Ctor(S1fc* a);
    unsigned int GetInstanceSize();
    static NiObject* __cdecl CreateObject();

    int pTargetObject; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    // +0x14: a BSSimpleList of NiPointer items (8 bytes). The constructor 0x0056d380 builds it with 0x004ee810
    // (NiPointer(0) 0x00633c90, then next = 0) and unwinds it with 0x004ee840 (RemoveAll 0x004ee920, ~NiPointer
    // 0x0045cec0); 0x00c8dac0 tests each item IsKindOf bhkConstraint::ms_RTTI 0x0126818c / bhkFixedConstraint
    // 0x01268628. Same folded instance as bhkRigidBody's m_kSerializableList.
    BSSimpleList<NiPointer<bhkSerializable> > fNeighborDistance; // src: XBOX_RETAIL_PDB +0x14 (old: m_kSerializableList)
    int fInitialStickForce; // src: XBOX_RETAIL_PDB +0x1c (old: unk1c)
    int fStickStrength; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    int StickPoint; // src: XBOX_RETAIL_PDB +0x24 (old: unk24)
    int unk28;
    int unk2c;
    int StickNormal; // src: XBOX_RETAIL_PDB +0x30 (old: unk30)
    int unk34;
    int unk38;
    int bFirstUpdate; // src: XBOX_RETAIL_PDB +0x3c (old: unk3c)
};
