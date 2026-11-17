#pragma once

#include "Actor.h"

#if defined(FNV_PACKAGELOCATION_DECLS_H)
#include "BaseProcess.h"
#endif

class BGSLoadFormBuffer;
class NiAVObject;

// pdb: class Creature, size 0x1c0, bases: Actor, 3 members
class Creature : public Actor
{
public:
    bool bRagDoll;
    char _pdbpad_1b5[3];
    float fArmorRating; // src: XBOX_RETAIL_PDB +0x1b8 (old: m_fFirstResetValue)
    float fArmorThreshold; // src: XBOX_RETAIL_PDB +0x1bc (old: m_fSecondValue)

    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual float CalculateRunSpeed();
    virtual float Unk_117(void);

    float GetAnimationSpeedMultiplier(ANIM_GROUP_ENUM group);
    float CalculateRunSpeed_008d4f10();
    float Creature_GetWeaponSkill();
    float TESObjectWEAP_GetShotsPerSecond();
    static void __cdecl SetNodeFlagsRecursive(NiAVObject*, int, bool, bool, bool);
};
