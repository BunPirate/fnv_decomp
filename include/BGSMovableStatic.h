#pragma once

#include "TESFullName.h"
#include "BGSDestructibleObjectForm.h"
#include "TESObjectSTAT.h"

class TESSound;

// pdb: class BGSMovableStatic, size 0x74, bases: TESFullName, BGSDestructibleObjectForm, TESObjectSTAT, 2 members
class BGSMovableStatic : public TESFullName, public BGSDestructibleObjectForm, public TESObjectSTAT
{
public:
    BGSMovableStatic();

    // TESForm vftable slot 5 (0x01024cec[5] = 0x004fbb50): clears soundLoop; called directly by the ctor
    virtual void InitializeComponent();

    TESSound* pSoundLoop; // src: XBOX_RETAIL_PDB +0x6c (old: soundLoop)
    unsigned char data;
    unsigned char unk71[3];
};
