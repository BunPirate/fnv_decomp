#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class BGSLoadFormBuffer;
class BSFileEntry;
class InventoryStackRecord;
class SpellItem;
class TESForm;
class TESLevSpell;

// pdb: class TESSpellList, size 0x14, bases: BaseFormComponent, 2 members
class TESSpellList : public BaseFormComponent
{
public:
    TESSpellList();
    ~TESSpellList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual unsigned int GetSaveSizeTES(unsigned int flags);
    virtual void SaveGameTES(unsigned int flags);
    virtual void LoadGameTES(unsigned int flags);

    void InitializeComponent();
    void ClearComponent();
    void FreeSpellList();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    void InitItem(TESForm* apOwner);
    void Save();
    void TESSpellList_AddSpell_0048d210(TESLevSpell* apSpellIn);
    void TESSpellList_AddSpell_0048d290(unsigned int spellID);
    void TESSpellList_Save();
    BSSimpleList<InventoryStackRecord*>* GetOffsetC();
    void LoadGame(BGSLoadFormBuffer* buffer);
    static bool RemoveSpell(BSFileEntry* spell);

    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
};
