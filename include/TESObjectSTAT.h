#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"

class TESFile;
class TESSound;

// pdb: class TESObjectSTAT, size 0x58, bases: TESBoundObject, TESModelTextureSwap, 2 members
class TESObjectSTAT : public TESBoundObject, public TESModelTextureSwap
{
public:
    TESObjectSTAT();
    virtual ~TESObjectSTAT();
    virtual bool LoadForm(TESFile* file);

    bool Load(TESFile* apFile);
    void BGSMovableStatic_InitItem();

    char cPassThroughSoundIndex; // src: XBOX_RETAIL_PDB +0x50 (old: m_cType)
    unsigned char layoutPadding51[3];
    TESSound* pRandomSound; // src: XBOX_RETAIL_PDB +0x54 (old: m_pSoundForm)
};
