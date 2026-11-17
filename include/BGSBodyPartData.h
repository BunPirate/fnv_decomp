#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "BGSPreloadable.h"

class BGSBodyPart;
class BGSRagdoll;
class TESFile;
class QueuedFile;
enum IO_TASK_PRIORITY;

// pdb: class BGSBodyPartData, size 0x74, bases: TESForm, TESModel, BGSPreloadable, 2 members
class BGSBodyPartData : public TESForm, public TESModel, public BGSPreloadable
{
public:
    BGSBodyPart* pPartArray[15]; // src: XBOX_RETAIL_PDB +0x34 (old: m_apBodyParts)
    BGSRagdoll* pRagdollData; // src: XBOX_RETAIL_PDB +0x70 (old: m_pRagdoll)

    BGSBodyPartData();
    virtual ~BGSBodyPartData();

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem(void);
    virtual void QueueResourceLoad(IO_TASK_PRIORITY aePriority, QueuedFile* apParent);

    void FUN_005e4bc0();
    void ResetFormData();
    void ClearBodyParts();
    bool Load(TESFile* apFile);
    void AddBodyPart(BGSBodyPart* apPart);
    BGSBodyPart* GetPart(unsigned int limbIndex);
    BGSBodyPart* GetValueByIndex(int aeIndex);

    static void GenerateDefaultBodyPartData();
    static BGSBodyPartData* ms_pBodyPartData;
    static BGSBodyPartData* ms_pBodyPartDataInstance;
};
