#pragma once

#include "TESPackage.h"
#include "BSSimpleList.h"

class Actor;
class CrimeList;
typedef CrimeList CrimeNode;

// pdb: class AlarmPackage, size 0x88, bases: TESPackage, 1 members
class AlarmPackage : public TESPackage
{
public:
    BSSimpleList<Actor*> Crimes;  // 0x80 // src: XBOX_RETAIL_PDB +0x80 (old: list)

    AlarmPackage();
    AlarmPackage(Actor* actor);
    virtual ~AlarmPackage();

    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void CopyFrom(const TESForm* form);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();

    AlarmPackage* Destroy(unsigned int flags);
    void CopyFromPackage(TESForm* source);
    CrimeNode* GetCrimeList();
};
