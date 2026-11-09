#pragma once

#include "TESForm.h"
#include "BGSPreloadable.h"

class BGSImpactData;
class ImpactSwap;
class QueuedFile;
class TESFile;

// pdb: class BGSImpactDataSet, size 0x4c, bases: TESForm, BGSPreloadable, 1 members
struct BGSImpactDataSet : public TESForm, public BGSPreloadable
{
public:
    BGSImpactDataSet();
    virtual ~BGSImpactDataSet();

    void ResetFormData();
    bool Load(TESFile* apFile);
    virtual void InitItem();
    static void CreateDefaultImpactDataSet();
    static void RefreshImpactData(ImpactSwap* apSwap);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY aePriority, QueuedFile* apParent);
    BGSImpactData* GetImpactDataForMaterial(int aeType);
    void Save();
    void Copy(TESForm* form);
    virtual bool Compare(TESForm* form);

    static BGSImpactDataSet* ms_pImpactDataSet;

    BGSImpactData* ppImpactData[12];
};
