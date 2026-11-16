#pragma once

#include "TESFullName.h"
#include "TESModel.h"
#include "TESModelPSA.h"
#include "BodyPartInfo.h"

class TESFile;
class TESForm;
class QueuedFile;
class BGSImpactDataSet;
enum IO_TASK_PRIORITY;

// pdb: class BGSBodyPart, size 0xb0, 8 members
class BGSBodyPart
{
public:
    enum LIMB_ENUM  // values: Xbox PDB BGSBodyPart::LIMB_ENUM
    {
        LIMB_NONE = -1,
        LIMB_TORSO = 0,
        LIMB_HEAD_1 = 1,
        LIMB_HEAD_2 = 2,
        LIMB_LEFT_ARM_1 = 3,
        LIMB_LEFT_ARM_2 = 4,
        LIMB_RIGHT_ARM_1 = 5,
        LIMB_RIGHT_ARM_2 = 6,
        LIMB_LEFT_LEG_1 = 7,
        LIMB_LEFT_LEG_2 = 8,
        LIMB_LEFT_LEG_3 = 9,
        LIMB_RIGHT_LEG_1 = 10,
        LIMB_RIGHT_LEG_2 = 11,
        LIMB_RIGHT_LEG_3 = 12,
        LIMB_BRAIN = 13,
        LIMB_WEAPON = 14,
        LIMB_COUNT = 15
    };

    BGSBodyPart();
    ~BGSBodyPart();

    virtual void QueueResourceLoad(IO_TASK_PRIORITY aePriority, QueuedFile* apParent);

    void vfn_00();
    bool Load(TESFile* apFile);
    void InitItem(TESForm* apParentForm);
    int GetLimb();
    const char* GetPartName();
    char GetByte63();
    unsigned int FUN_005e3fc0();
    void FUN_00994ef0(BGSImpactDataSet* impactDataSet);
    void InitializeData_005e3d20();
    NiPoint3* NiAVObject_GetWorldTranslate();
    void NiAVObject_SetWorldTranslate(const NiPoint3& position);

    BSStringT<char> NodeName;
    BSStringT<char> TargetName;
    BSStringT<char> IKStartNodeName; // src: XBOX_RETAIL_PDB +0x14 (old: m_kVATSNodeName)
    BSStringT<char> PartName; // src: XBOX_RETAIL_PDB +0x1c (old: m_kPartName)
    BSStringT<char> GoreObjectName; // src: XBOX_RETAIL_PDB +0x24 (old: m_kGoreName)
    TESModel ExplosionSpecialDebris; // src: XBOX_RETAIL_PDB +0x2c (old: m_kModel)
    TESModelPSA PSAModel; // src: XBOX_RETAIL_PDB +0x44 (old: m_kRagdollModel)
    BodyPartInfo Data;
};
