#include "../../include/BSStringT.h"
// fallout_shared/tesdescription.cpp: TESDescription, TESDataHandler, TermHack (14 functions)

#include "../../include/PlayerCharacter.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"

#include "../../include/CHUNK_ID.h"
extern TESDataHandler* g_dataHandler;
extern BSStringT<char> g_menuParsedXML;
extern const char g_011c72c0_arg1[];

// @fnv 0x00482f20
bool TESDataHandler::LoadDescriptionForForm()
{
    return bLoadingFiles;
}
// Initializes the description offset from the file when both are non-null.
// @fnv 0x00482d50
// pdb: TESDescription::LoadDescriptionData | TESDescription.obj | debug, call graph, high
// pdb params: apDesc, apFile
void TESDescription::ReadDescriptionFromFile(TESDescription* apDesc, TESFile* apFile)
{
    if (apDesc && apFile)
        apDesc->SetDescriptionFileOffset(apFile->GetOffset());
}
// @fnv 0x00482c50
// pdb: TESDescription::TESDescription | TESDescription.obj | retail, upstream name already matches, high
TESDescription::TESDescription()
{
    InitializeComponent();
}
// @fnv 0x00482e90
// pdb: TESDescription::GetDescription | TESDescription.obj | retail, upstream name already matches, high
// pdb params: apForm, aeChunk
// pdb locals: pform
const char* TESDescription::GetDescription(TESForm* apForm, CHUNK_ID aeChunk)
{
    if (!g_dataHandler->LoadDescriptionForForm())
    {
        TESForm* owner = apForm;
        if (!owner)
            owner = dynamic_cast<TESForm*>(this);
        LoadDescriptionForForm(owner, aeChunk);
    }
    return reinterpret_cast<NiPointer<NiNode>*>(&g_menuParsedXML)->operator->()
               ? reinterpret_cast<const char*>(reinterpret_cast<NiPointer<NiNode>*>(&g_menuParsedXML)->operator->())
               : g_011c72c0_arg1;
}

extern "C" unsigned char DAT_011c54ba;

// @fnv 0x00401500
// src: XBOX_PDB 0x00401500
unsigned char TESForm_QEndianSwapOnSave()
{
    return DAT_011c54ba;
}

extern "C" unsigned char DAT_011c54ba;
unsigned char TESForm_QEndianSwapOnSave();



extern int DAT_011c5490;

// Resets the parsed XML string, clears DAT_011c5490, and zeroes the description offset.
// @fnv 0x00482c80
// pdb: TESDescription::InitializeDataComponent | TESDescription.obj | retail, vtable slot, high
void TESDescription::InitializeComponent()
{
    ((::BSStringT<char>*)&g_menuParsedXML)->Set(0, 0);
    DAT_011c5490 = 0;
    m_uiDescriptionFileOffset = 0;
}

void __cdecl TESDescription_SaveDescriptionData(void*, int);

// @fnv 0x00482cb0
// src: COMMUNITY 0x00482cb0
// pdb: TESDescription::Save | TESDescription.obj | debug, call graph, high
void __thiscall TESDescription::Save_00482cb0()
{
    TESDescription_SaveDescriptionData(this, 0x43534544);
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// @fnv 0x00482cd0
// src: XBOX_DEBUG_PDB 0x00482cd0
// pdb: TESDescription::SaveDescriptionData | TESDescription.obj | debug, call graph, high
// pdb params: apDesc, aiChunk
// pdb locals: empty
void __cdecl TESDescription_SaveDescriptionData(void* apDesc, int aiChunk)
{
    char empty;
    if (apDesc)
    {
        if (((TESDescription*)apDesc)->GetDescriptionLength())
        {
            TESForm_AddChunkArray(aiChunk, const_cast<char*>(((TESDescription*)apDesc)->GetDescription(0, (CHUNK_ID)0x43534544)),
                         ((TESDescription*)apDesc)->GetDescriptionLength() + 1);
        }
        else
        {
            empty = 0;
            TESForm_AddChunkArray(aiChunk, &empty, 1);
        }
    }
}

extern BSStringT<char> g_menuParsedXML;
struct S7010
{
    unsigned int Length();
};
// @fnv 0x00482d30
// pdb: TESDescription::GetDescriptionLength | TESDescription.obj | debug, upstream name already matches, high
unsigned int __thiscall TESDescription::GetDescriptionLength()
{
    return ((S7010*)&g_menuParsedXML)->Length();
}

void __cdecl _Deallocate(void*);
struct ClassFFB70
{
    void __thiscall FUN_004ffba0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_004ffba0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004ffb70
// pdb: BGSTerminal::`scalar deleting destructor' | BGSTerminal.obj | retail, vtable slot, high
void* __thiscall ClassFFB70::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_004ffba0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    const char* operator*() const;
};

struct FUN_005a6e10_shell
{
    unsigned int _pad[5];
    Flt m_str;
    const char* GetStringOrDefault(int a, int b);
};

// Returns the string held by m_str if it is non-null, otherwise returns g_011c72c0_arg1.
// @fnv 0x005a6e10
// pdb: TESLoadScreen::GetDescription | TESLoadScreen.obj | debug, object-file gap fill, medium
// pdb params: apForm, aeChunk
const char* FUN_005a6e10_shell::GetStringOrDefault(int aiUnusedA, int aiUnusedB)
{
    (void)aiUnusedA;
    (void)aiUnusedB;
    return *m_str ? *m_str : g_011c72c0_arg1;
}

struct StrCmpHelper
{
    int StrCmp(char const*, bool) const;
};

// @fnv 0x00482df0
// pdb: TESDescription::CompareComponent | TESDescription.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pCompare
bool __thiscall TESDescription::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apCompareFC);
    if (!pDesc)
        return true;
    if (GetDescriptionLength() || pDesc->GetDescriptionLength())
    {
        if (GetDescriptionLength() != pDesc->GetDescriptionLength())
            return true;
        else if (((StrCmpHelper*)&g_menuParsedXML)->StrCmp((char const*)pDesc->GetDescription(0, (CHUNK_ID)0x43534544), 0))
            return true;
    }
    return false;
}

extern PlayerCharacter* g_thePlayer;


int BSStringT_char_SPrintF(::BSStringT<char>* apStr, const char* apFmt, ...);

struct SettingString
{
    const char* GetString();
};
extern SettingString g_011c8394;

#include "../../include/ActorValue.h"
namespace ActorValue {
const char* __cdecl ActorValue_GetActorValueName(Index aiIndex);
}

float __cdecl FUN_004bd510(float afValue, float afMult);
void __cdecl Interface_QueueMenuCreate(int, TESObjectREFR*, int, int, int, int);
bool __cdecl QueueUIMessage(const char* apMsg, int aeType, const char* apIcon, const char* apSound, float afTime,
                            bool abInstant);
void __cdecl BGSOpenCloseForm_HandleActivate(TESObjectREFR* apItemActivated, PlayerCharacter* apActionRef, int apOpenCloseForm);

struct TermHackBase0
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct TermHackBase70
{
    virtual void BGSTerminal_HandleOpenFinish(TESObjectREFR* apRef, PlayerCharacter* apActor);
};

struct TermHack : TermHackBase0, TermHackBase70
{
    float BGSTerminal_GetMinSkillRequiredToHack(TESObjectREFR* apRef);
    virtual void BGSTerminal_HandleOpenFinish(TESObjectREFR* apItemActivated, PlayerCharacter* apActionRef);
};

// @fnv 0x005015f0
// src: XBOX_PDB 0x005015f0
// pdb: BGSTerminal::HandleOpenFinish | BGSTerminal.obj | retail, upstream name already matches, high
// pdb params: apItemActivated, apActionRef
// pdb locals: strmsg
void TermHack::BGSTerminal_HandleOpenFinish(TESObjectREFR* apItemActivated, PlayerCharacter* apActionRef)
{
    if (apItemActivated && apActionRef == g_thePlayer)
    {
        switch (g_thePlayer->GetTerminalAccessResult(apItemActivated))
        {
        case 0:
        case 1:
            Interface_QueueMenuCreate(3, apItemActivated, 0, 0, 1, 0);
            break;
        case 2:
        case 3:
            Interface_QueueMenuCreate(2, apItemActivated, 0, 0, 1, 0);
            break;
        case 4: {
            ::BSStringT<char> kMsg;
            BSStringT_char_SPrintF(&kMsg, g_011c8394.GetString(), ActorValue::ActorValue_GetActorValueName((ActorValue::Index)0x28),
                         (int)FUN_004bd510(BGSTerminal_GetMinSkillRequiredToHack(apItemActivated), 1.0f));
            QueueUIMessage(kMsg, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0, 2.0f, false);
        }
        break;
        }
        BGSOpenCloseForm_HandleActivate(apItemActivated, apActionRef, 0);
    }
}

class GlobalObject_004037b0
{
  public:
    bool FUN_004037f0(const char* apString, unsigned int aiMaxLen);
};
extern GlobalObject_004037b0 g_011c5498;
// @fnv 0x00482d80
// pdb: TESDescription::CopyComponent | TESDescription.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pCopy
void TESDescription::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apCopyFC);
    if (!pDesc)
        return;
    g_011c5498.FUN_004037f0((const char*)pDesc->GetDescription(0, (CHUNK_ID)'CSED'), 0);
    m_uiDescriptionFileOffset = pDesc->GetDescriptionFileOffset();
}
