#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class ContainerItemExtra;
class LeveledObject;
class TESContainer;
class TESForm;
class TESGlobal;
class TESObjectREFR;

// pdb: class TESLeveledList, size 0x1c, bases: BaseFormComponent, 5 members
class TESLeveledList : public BaseFormComponent
{
public:
    ~TESLeveledList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned char vfn_10();
    virtual bool vfn_14();
    virtual int vfn_18();

    unsigned char GetChanceNone();
    bool UsesAllEntries();
    int GetMaxLevelDifference();

    void ErrorCheckList();
    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    void SetChanceNone(unsigned char chance);
    void ExtraWeaponModFlags_SetWeaponModFlags(unsigned char chance);
    bool GetCalcAllBelow();
    bool GetAllBelow();
    bool FUN_004877e0();
    void SetCalcAllBelow(bool value);
    void SetMultCalc(bool value);
    bool GetUseAll();
    bool FUN_004878a0();
    void SetUseAll(bool value);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal* global);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* AddLeveledObject(unsigned short asLevel, unsigned short asCount, TESForm* apForm, ContainerItemExtra* apExtra);
    void DeleteLeveledObject(LeveledObject* object);
    void SelectLeveledObject(unsigned short level, TESForm** form, unsigned short* count, ContainerItemExtra** extra, bool recurse, int mode);
    void CalculateCurrentForm(unsigned short asLevel, TESForm*& apOutForm, unsigned short& asOutCount, ContainerItemExtra*& apOutExtra, bool abRecurse, int aiAllBelowForce);
    void CalculateCurrentFormList(unsigned short asLevel, unsigned short asCount, TESContainer* apOutCont, int aiAllBelowForce);
    void CalculateCurrentFormListForRef(TESObjectREFR* reference, TESContainer* container);
    void CalculateCurrentFormListForRef(void* reference, TESContainer* container);
    void RemoveAllScriptAddedLeveledObjects();
    void AddScriptAddedLeveledObject(TESForm* form, unsigned short level, unsigned short count, TESForm* owner, ContainerItemExtra* extra);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    void Save();
    void InitItem(TESForm* apOwner);
    static TESLeveledList* GetFormAsLeveledList(TESForm* form);
    void* GetLeveledList();
    // The compiler supplies __vecDelDtor(unsigned int).

    BSSimpleList<LeveledObject*> leveledList;
    unsigned char cChanceNone; // src: XBOX_RETAIL_PDB +0xc (old: m_pChanceGlobal)
    unsigned char cLLFlags; // src: XBOX_RETAIL_PDB +0xd (old: m_ucChanceNone)
    unsigned char layoutPaddingE[2];
    TESGlobal* pChanceGlobal; // src: XBOX_RETAIL_PDB +0x10 (old: m_pLevelGlobal)
    BSSimpleList<LeveledObject*> ScriptAddedList; // src: XBOX_RETAIL_PDB +0x14 (old: m_kLeveledObjects)
};
