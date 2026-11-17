#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESTexture.h"
#include "TESAttributes.h"
#include "TESClassData.h"

// pdb: class TESClass, size 0x60, bases: TESForm, TESFullName, TESDescription, TESTexture, TESAttributes, 1 members
class TESClass : public TESForm, public TESFullName, public TESDescription, public TESTexture, public TESAttributes
{
public:
    TESClass();
    virtual ~TESClass();

    bool IsGuard();
    bool IsTagSkill(ActorValue::Index aeSkill);
    bool IsTagSkill(ActorValue::Index aeSkill) const;
    unsigned int FUN_006286d0();
    void SetClassSkillAtIndex(int index, ActorValue::Index skill);
    void ResetFormData();
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    bool Load(TESFile* apFile);
    bool CheckData();
    void* DestroyIfFlagged(unsigned int flags);
    int GetTrainingSkill();
    void SetTrainingSkill(ActorValue::Index aeSkill);
    virtual void SaveForm(void);
    virtual void SaveGame(BGSSaveFormBuffer* buffer);
    void CopyFromTESClass(TESForm* other);
    void TESForm_CopyAllComponents(TESForm* other);
    bool CompareClass(TESForm* apCompare);
    bool TESForm_CompareAllComponents(TESForm* apCompare);
    TESClassData* GetClassData() const;

    TESClassData data;
};
