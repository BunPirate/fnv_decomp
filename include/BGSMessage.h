#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "MagicTarget.h"

class BGSMenuIcon;
class PerkButtonEntry;

// pdb: class BGSMessage, size 0x40, bases: TESForm, TESFullName, TESDescription, 4 members
class BGSMessage : public TESForm, public TESFullName, public TESDescription
{
public:
    BGSMenuIcon* pIcon;
    BSSimpleList<PerkButtonEntry*> ButtonList;
    unsigned int iFlags;
    unsigned int iDisplayTime;

    BGSMessage();
    virtual ~BGSMessage();
    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();
    void ClearButtonList();
    void SetIcon(BGSMenuIcon* icon);
    bool Load(TESFile* apFile);

    void AddButton(PerkButtonEntry* button);
    void WriteToStream();
    void CopyFromMessage(TESForm* apCopy);
    bool IsNotEqual(TESForm* apCompare);

    BGSMenuIcon* GetIcon();
    bool GetAutoDisplay();
    void SetAutoDisplay(bool value);
    bool GetMessageBoxFlag();
    void SetMessageBoxFlag(bool value);
    TESForm* GetQuest();
    void SetQuest(TESForm* quest);
    BSSimpleList<PerkButtonEntry*>* GetButtonList();
    void CopyBase(TESForm* form);

    bool GetIsMessageBox();
    bool IsFlagSet();
    void SetEnabled(bool enabled);
    void SetAutoDisplay_00590ef0(bool enabled);
    void AddButton_005911d0(PerkButtonEntry* button);
};
