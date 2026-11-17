#pragma once

#include "BaseFormComponent.h"
#include "MagicTarget.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class ReactionInfo;
class TESForm;

// pdb: class TESReactionForm, size 0x10, bases: BaseFormComponent, 2 members
class TESReactionForm : public BaseFormComponent
{
public:
    TESReactionForm();
    ~TESReactionForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    void InitItem(TESForm* apOwner);
    void FreeReactionList();
    int GetLowestReaction(TESForm**, int*, long);
    int GetHighestReaction(TESForm**, int*, long);
    void SetReactionValue(TESForm*, int);
    int GetReaction(TESForm*);
    void ModReaction(TESForm*, int);
    int GetFactionCombatRelation(TESForm*);
    void SetFightReaction(TESForm*, int);
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(unsigned int, unsigned int);
    void* GetReactionList();
    void RemoveReactionItem(ReactionInfo*);
    void vfn_0();

    BSSimpleList<ReactionInfo*> m_kReactionList;
    unsigned char m_ucReactionFlags;
    unsigned char layoutPaddingD;
    unsigned short layoutPaddingE;
};
