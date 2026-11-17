#pragma once

// CreatureSounds: real name (was CreatureSoundCollection). Names DB / Xbox PDB name 7 of its bound methods CreatureSounds::*; ctor 0x005f0360 is called after a 0x58-byte allocation at 0x005f928c.

#include "BSSimpleList.h"

class SoundListEntry;
class SoundOps;
class TESFile;
class TESCreature;
enum CREATURE_SOUND_TYPE;

// pdb: class CreatureSounds, size 0x58, 1 members
class CreatureSounds
{
public:
    CreatureSounds();
    ~CreatureSounds();

    bool SetSoundName(const char*);
    void ClearSounds();
    void FreeAllCreatureSoundLists();
    void* CreatureSounds_ScalarDtor(unsigned int);
    void AddSoundForType(SoundListEntry*, CREATURE_SOUND_TYPE);
    BSSimpleList<SoundListEntry*>* GetSoundListForType(CREATURE_SOUND_TYPE);
    bool LoadCreatureSound(TESFile*, CREATURE_SOUND_TYPE, TESCreature*);
    SoundOps* PickCreatureSound(int);
    void Copy(CreatureSounds*);
    bool Compare(CreatureSounds* other);

    union
    {
        unsigned char soundLists[0x58];
        BSSimpleList<SoundListEntry*>* m_pSoundListsByType[22];
    };
};
