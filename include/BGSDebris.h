#pragma once

#include "TESForm.h"
#include "BGSPreloadable.h"
#include "MagicTarget.h"

class DebrisModelEntry;
struct NiPoint3;

// pdb: class BGSDebris, size 0x24, bases: TESForm, BGSPreloadable, 1 members
class BGSDebris : public TESForm, public BGSPreloadable
{
public:
    BSSimpleList<DebrisModelEntry*> DataList;

    BGSDebris();
    virtual ~BGSDebris();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* apFile);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY aePriority, QueuedFile* apParent);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* apCompare);

    BSSimpleList<DebrisModelEntry*>* GetDataList();
    BSSimpleList<DebrisModelEntry*>* GetData();
    bool Load(TESFile* apFile);
    void Preload(int priority, void* file);
    DebrisModelEntry* AddDebrisData(char acPercentage, const char* apFileName, char acFlags);
    void InsertDebrisIfValid(DebrisModelEntry* entry);
    void WriteDebrisEntries();
    void SpawnDebris(void* apCell, NiPoint3* arLocation, unsigned int aiNumParticles, float afScale);
};
