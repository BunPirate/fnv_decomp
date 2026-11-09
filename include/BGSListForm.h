#pragma once

#include "TESForm.h"
#include "BSSimpleList.h"

class BGSSaveFormBuffer;

// pdb: class BGSListForm, size 0x24, bases: TESForm, 2 members
class BGSListForm : public TESForm
{
public:
    BSSimpleList<TESForm*> m_kFormList;
    unsigned int m_uiFormCount;

    BGSListForm();
    virtual ~BGSListForm();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* apFile);
    void RemoveAllScriptAddedForms();
    void AddScriptAddedForm(TESForm* apAddedForm);
    BSSimpleList<TESForm*>* GetList();
    BSSimpleList<TESForm*>* Items();
    bool IsInList(BGSListForm*& form);
    void CopyConditionsFromListForm(TESForm* form);
    bool IsNotEqual(TESForm* form);
    void Save_0058fcc0();
    int GetConditionIndex(TESForm* form);
    void SaveFormList(BGSSaveFormBuffer* buffer);
};
