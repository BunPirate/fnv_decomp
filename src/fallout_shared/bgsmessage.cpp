// fallout_shared/bgsmessage.cpp: BGSMessage (16 functions)

#include "layout_support.h"
#include "../../include/BGSMenuIcon.h"
#include "../../include/BGSMessage.h"

#include "bgsmessage_match_decls.h"
#include "PerkButtonEntry.h"

struct BGSMessageInitItemLocals
{
    PerkButtonEntry* button;
    int conditionErrors;
    int warningState;
    BSSimpleList<PerkButtonEntry*>* buttonList;
    unsigned int buttonIndex;
    unsigned int iconFormID;
};

// @fnv 0x00590530
// pdb: BGSMessage::BGSMessage | BGSMessage.obj | retail, upstream name already matches, high
BGSMessage::BGSMessage()
{
    SetFormType(ENUM_FORM_ID_MESG_ID);
    ResetFormData();
}

// @fnv 0x005906a0
void BGSMessage::ResetFormData()
{
    pIcon = 0;
    iFlags = 1;
    iDisplayTime = 2;
}

// @fnv 0x005906d0
// pdb: BGSMessage::ClearData | BGSMessage.obj | debug, upstream name already matches, high
void BGSMessage::ClearData()
{
    SetIcon(0);
    ClearButtonList();
}

// @fnv 0x005906f0
// pdb: BGSMessage::InitItem | BGSMessage.obj | retail, upstream name already matches, high
// pdb locals: plist, iindex, itempInt, pitem, iwarnings, iprevwarnings
void BGSMessage::InitItem()
{
    if (IsFormInitialized())
    {
        return;
    }

    BGSMessageInitItemLocals locals;
    locals.iconFormID = reinterpret_cast<unsigned int>(GetIcon());
    if (locals.iconFormID)
    {
        TESForm::RemapFormIDForFile(locals.iconFormID, GetFile(-1));
        SetIcon(dynamic_cast<BGSMenuIcon*>(TESForm::GetFormByID(locals.iconFormID)));

        if (!reinterpret_cast<unsigned int>(GetIcon()))
        {
            Warning("MASTERFILE: Could not find icon (%08X) on weapon '%s' (%08X).", locals.iconFormID, GetName(),
                    GetFormID());
        }
    }

    locals.buttonList = GetButtonList();
    locals.buttonIndex = 0;
    while (locals.buttonList && !locals.buttonList->IsEmpty())
    {
        locals.button = locals.buttonList->GetItem();
        locals.buttonList = locals.buttonList->GetNext();
        locals.button->Conditions.InitItem(this);
        locals.warningState = Warning();
        SetWarningState(reinterpret_cast<NiTexture*>(1));
        BGSMessageWarningAuxiliary(0);
        SetWarningState(0);
        locals.conditionErrors = Warning();
        BGSMessageWarningAuxiliary(locals.warningState);
        if (locals.conditionErrors)
        {
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for conditions on menu item %d for terminal '%s' (%08X)\n\nSee Warnings file for more information.",
                locals.buttonIndex, GetName(), GetFormID());
        }
        ++locals.buttonIndex;
    }

    SetInitializationState(true);
}

struct BGSMessageLoadLocals
{
    char* buttonText;
    PerkButtonEntry* newButton;
    char* editorIDText;
    unsigned int iconFormID;
    int chunkID;
    PerkButtonEntry* currentButton;
    unsigned int unused;
};

// @fnv 0x00590880
// pdb: BGSMessage::Load | BGSMessage.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: chunkid, plastitem, btn, formid, iid, pMessage, ptext, pbutton
bool BGSMessage::Load(TESFile* apFile)
{
    unsigned char formType = apFile->GetTESForm();
    LoadRecordHeader(apFile);
    SetInitializationState(false);

    BGSMessageLoadLocals locals;
    locals.currentButton = 0;
    locals.unused = 0;
    while ((locals.chunkID = apFile->GetChunkID()) != 0)
    {
        switch (locals.chunkID)
        {
        case 0x44494445: {
            locals.editorIDText = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(locals.editorIDText, 0x200);
            SetEditorID_AtRuntime(locals.editorIDText);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(static_cast<TESDescription*>(this), apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(static_cast<TESFullName*>(this), apFile);
            break;
        case 0x4d414e49: {
            apFile->GetChunkData(&locals.iconFormID);
            SetIcon(reinterpret_cast<BGSMenuIcon*>(locals.iconFormID));
            break;
        }
        case 0x4d414e44:
            apFile->GetChunkData(&iFlags);
            break;
        case 0x4d414e54:
            apFile->GetChunkData(&iDisplayTime);
            break;
        case 0x54585449: {
            locals.buttonText = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(locals.buttonText, 0);
            locals.newButton = new PerkButtonEntry;
            locals.newButton->cButtonText.Set(locals.buttonText, 0);
            AddButton(locals.newButton);
            locals.currentButton = locals.newButton;
            break;
        }
        case 0x41445443:
            if (locals.currentButton)
            {
                locals.currentButton->Conditions.Load(apFile);
            }
            break;
        default:
            break;
        }

        if (!apFile->NextChunk())
        {
            break;
        }
    }

    return true;
}

// Removes every item from the button list, deleting each button until the list is empty.
// @fnv 0x005910d0
// src: XBOX_RETAIL_PDB 0x005910d0
// pdb: BGSMessage::ClearButtonList | BGSMessage.obj | retail, object-file run extension, high
// pdb locals: pitem
void BGSMessage::ClearButtonList()
{
    while (!ButtonList.IsEmpty())
    {
        PerkButtonEntry* button = ButtonList.GetItem();
        ButtonList.RemoveHead();
        delete button;
    }
}

// @fnv 0x00590d00
// src: COMMUNITY 0x00590d00
bool BGSMessage::GetIsMessageBox()
{
    return (iFlags & 1) ? true : false;
}

// @fnv 0x00590ed0
bool BGSMessage::IsFlagSet()
{
    return (iFlags & 2) ? true : false;
}

// If apItem is non-null, appends it to the button list.
// @fnv 0x005911d0
// src: COMMUNITY 0x005911d0
// pdb: BGSMessage::AddButton | BGSMessage.obj | debug, call graph, high
// pdb params: apItem
void BGSMessage::AddButton_005911d0(PerkButtonEntry* apItem)
{
    if (apItem != 0)
    {
        ButtonList.AddTail(apItem);
    }
}

// @fnv 0x00590e80
void BGSMessage::SetEnabled(bool enabled)
{
    enabled ? iFlags |= 1 : iFlags &= ~1;
}

// @fnv 0x00590ef0
// src: COMMUNITY 0x00590ef0
void BGSMessage::SetAutoDisplay_00590ef0(bool enabled)
{
    enabled ? iFlags |= 2 : iFlags &= ~2;
}

// @fnv 0x00590610
// pdb: BGSMessage::~BGSMessage | BGSMessage.obj | retail, upstream name already matches, high
BGSMessage::~BGSMessage()
{
    ClearData();
}

struct ButtonTextAccess
{
    BSStringT<char>& Assign(const BSStringT<char>& arString);
};

struct ConditionCopyAccess
{
    void Copy(PerkEntryConditionSet* apCopy, bool apOwner);
};

// Clears the message data, copies icon, auto-display, message-box flag, quest and button list from form, then copies the base form.
// @fnv 0x00590d20
// pdb: BGSMessage::Copy | BGSMessage.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: plist, pcopy, pcopyitem, pitem
void BGSMessage::CopyFromMessage(TESForm* apCopy)
{
    BSSimpleList<PerkButtonEntry*>* node;
    ClearData();
    BGSMessage* src = (BGSMessage*)apCopy;
    SetIcon(((BGSMessage*)apCopy)->GetIcon());
    SetAutoDisplay(src->GetAutoDisplay());
    SetMessageBoxFlag(src->GetMessageBoxFlag());
    SetQuest(src->GetQuest());
    node = src->GetButtonList();
    while (node && !node->IsEmpty())
    {
        PerkButtonEntry* item = node->GetItem();
        node = node->GetNext();
        PerkButtonEntry* button = new PerkButtonEntry;
        ((ButtonTextAccess*)&button->cButtonText)->Assign(item->cButtonText);
        ((ConditionCopyAccess*)&button->Conditions)->Copy(&item->Conditions, false);
        AddButton(button);
    }
    CopyBase(apCopy);
}

struct String0bc0
{
    int unk00, unk04;
    const char* Modelloader_GetReferencedThis();
};
struct Conditions0bc0
{
    void Save();
};
struct Button0bc0
{
    String0bc0 text;
    Conditions0bc0 conditions;
};
struct List0bc0
{
    bool FUN_008256d0();
    Button0bc0*& FUN_006815c0();
    List0bc0* FUN_00726070();
};
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
int __cdecl BSstrlen(const char*);
void __cdecl TESForm_AddChunkArray(unsigned int, const char*, unsigned int);
// @fnv 0x00590bc0
// pdb: BGSMessage::Save | BGSMessage.obj | retail, vtable slot, high
// pdb locals: plist, iid, pitem
void BGSMessage::WriteToStream()
{
    BeginFormRecord();
    TESDescription::Save_00482cb0();
    TESFullName::Save_00487010();
    unsigned int id = GetIcon() ? GetIcon()->GetHavokWorldObjectCountInSceneGraph_0084e3a0() : 0;
    TESForm_AddChunk_00485910(0x4d414e49, id);
    TESForm_AddChunk_00485910(0x4d414e44, iFlags);
    if (!GetIsMessageBox())
        TESForm_AddChunk_00485910(0x4d414e54, iDisplayTime);
    List0bc0* node = reinterpret_cast<List0bc0*>(GetButtonList());
    while (node && !node->FUN_008256d0())
    {
        Button0bc0* button = node->FUN_006815c0();
        node = node->FUN_00726070();
        if (button->text.Modelloader_GetReferencedThis())
            TESForm_AddChunkArray(0x54585449, button->text.Modelloader_GetReferencedThis(), BSstrlen(button->text.Modelloader_GetReferencedThis()) + 1);
        else
            TESForm_AddChunk_00485910(0x54585449, 0);
        button->conditions.Save();
    }
    FinishFormRecord();
}

struct ButtonConditionView
{
    bool FUN_00680b70(ButtonConditionView*);
};
struct ButtonView
{
    int text00, text04;
    ButtonConditionView conditions;
    bool FUN_00501c30(ButtonView*);
};
struct ButtonListView
{
    int FUN_005ae380();
    bool FUN_008256d0();
    ButtonView** FUN_006815c0();
    ButtonListView* FUN_00726070();
};
// @fnv 0x00590f40
// pdb: BGSMessage::Compare | BGSMessage.obj | retail, vtable slot, high
// pdb params: apCompare
// pdb locals: pcomp, plist, pcomplist, pcompitem, pitem
bool BGSMessage::IsNotEqual(TESForm* apCompare)
{
    BGSMessage* right = static_cast<BGSMessage*>(apCompare);
    if (!right)
        return true;
    if (GetIcon() != right->GetIcon())
        return true;
    if (GetIsMessageBox() != right->GetIsMessageBox())
        return true;
    if (IsFlagSet() != right->IsFlagSet())
        return true;
    if (GetQuest() != right->GetQuest())
        return true;
    ButtonListView* left = reinterpret_cast<ButtonListView*>(GetButtonList());
    ButtonListView* other = reinterpret_cast<ButtonListView*>(right->GetButtonList());
    if (left->FUN_005ae380() != other->FUN_005ae380())
        return true;
    while (other && !other->FUN_008256d0() && left && !left->FUN_008256d0())
    {
        ButtonView* rhs = *other->FUN_006815c0();
        ButtonView* lhs = *left->FUN_006815c0();
        if (lhs->FUN_00501c30(rhs))
            return true;
        if (lhs->conditions.FUN_00680b70(&rhs->conditions))
            return true;
        other = other->FUN_00726070();
        left = left->FUN_00726070();
    }
    if (TESForm::Compare(apCompare))
        return true;
    return false;
}
