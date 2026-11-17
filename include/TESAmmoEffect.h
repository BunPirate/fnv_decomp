#pragma once

#include "TESForm.h"
#include "TESFullName.h"

enum AMMO_EFFECT_TYPE;
template <class T> class BSSimpleList;

// pdb: class TESAmmoEffect, size 0x30, bases: TESForm, TESFullName, 1 members
class TESAmmoEffect : public TESForm, public TESFullName
{
public:
    TESAmmoEffect();

    virtual bool LoadForm(TESFile* file);

    void UnknownForm();
    void UnknownMap();
    bool Load(TESFile* file);
    void FUN_00599d00();
    void* DestroyIfFlagged(unsigned int flags);
    void SaveAmmoEffect();
    void CopyFromAmmoEffect(TESForm* form);
    bool CompareAmmoEffect(TESForm* apCompare);
    static float ApplyAmmoEffects(AMMO_EFFECT_TYPE type,
                                 BSSimpleList<TESAmmoEffect*>* effects,
                                 float value);

    unsigned char data[12]; // src: XBOX_RETAIL_PDB +0x24 (old: effectData)
};
