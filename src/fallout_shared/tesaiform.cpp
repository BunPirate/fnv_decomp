#include "../../include/SettingT.h"
#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/tesaiform.cpp: TESAIForm, ActorValue, MyInner, AIFormFlags and more (42 functions)

#include "../../include/PackageList.h"
#include "../../include/BGSEquipType.h"
#include "../../include/ActiveEffect.h"
#include "../../include/Actor.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BSAudio.h"
#include "../../include/TESAIForm.h"
#include "../../include/PatrolActorPackageData.h"

class PerkEntryConditionSet;
struct PackedRecordData
{
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned char pad[3];
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
// Retained locally: the shared TESAIForm destructor invokes PackageList::~PackageList
// bound to 0x0046ffb0, whereas this unit requires the destructor at 0x0067e3a0.
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESSaveLoadGameGlobals.h"
class GameSettingCollection;
using ::SettingT;
class GlobalObject_0040e0b0
{
  public:
    char opaque[16];
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting26, originalRuntimeFloatSetting27,
    originalRuntimeFloatSetting28;
extern GlobalObject_0040e0b0 g_011c52e4, g_011c52fc;
extern float DAT_011c52a8, DAT_011c52ac, DAT_011c52b0, DAT_011c52b4, DAT_011c52b8;
extern bool DAT_011c52c0;
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
namespace ActorValue {
enum Index;
bool IsSkill(Index);
}

// @fnv 0x0047ede0
// pdb: TESAIForm::ClearDataComponent | TESAIForm.obj | debug, vtable slot, medium
void TESAIForm::FreeDataComponent()
{
    packages.FreePackageList();
}

// @fnv 0x0047f190
// pdb: TESAIForm::CopyComponent | TESAIForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pCopy
void TESAIForm::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESAIForm* source = dynamic_cast<TESAIForm*>(apCopyFC);
    if (!source)
        return;
    CopyAIData(source);
    CopyAIPackageList(source);
}

// Returns the actor's current package by looking up the package list on the actor base's AI form, or null if actor or base is missing.
// @fnv 0x0047f520
// pdb: TESAIForm::GetCurrentPackage | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: apActor
// pdb locals: ppack, pactorbase, paiform
TESPackage* TESAIForm::GetCurrentPackage(Actor* apActor)
{
    TESPackage* result = 0;
    TESAIForm* ai;
    if (apActor)
    {
        TESActorBase* base = apActor->GetActorBase();
        ai = base ? reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(base) + 0x90) : 0;
        if (ai)
            result = reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(ai)->GetConditions())
                         ->FindCurrentPackage(apActor);
    }
    return result;
}

// @fnv 0x0047f590
// pdb: TESAIForm::GetMissedPackages | TESAIForm.obj | debug, call graph, medium
// pdb params: apActor, apPacks, afStartdate, afhour
// pdb locals: pactorbase, paiform
void TESAIForm::FindAvailablePackages(Actor* actor, BSSimpleList<TESPackage*>* missed, float start, float hour)
{
    TESAIForm* ai;
    if (actor)
    {
        TESActorBase* base = actor->GetActorBase();
        ai = base ? reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(base) + 0x90) : 0;
        if (ai)
            reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(ai)->GetConditions())
                ->CollectEligiblePackages(actor, missed, start, hour);
    }
}

// Resets all AI form fields to defaults and, on first call, caches five game-setting floats into globals.
// @fnv 0x0047ed10
// pdb: TESAIForm::InitializeDataComponent | TESAIForm.obj | debug, vtable slot, medium
void TESAIForm::InitializeComponent()
{
    aggression = 0;
    confidence = 4;
    energy = 0;
    responsibility = 0;
    mood = 0;
    services = 0;
    skill = 0;
    level = 0;
    assistance = 0;
    radius = false;
    distance = 0;
    if (!DAT_011c52c0)
    {
        DAT_011c52a8 = reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting28)->Float()->f;
        DAT_011c52ac = reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting27)->Float()->f;
        DAT_011c52b0 = reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011c52fc)->Float()->f;
        DAT_011c52b4 = reinterpret_cast<SettingT_GameSettingCollection_*>(&originalRuntimeFloatSetting26)->Float()->f;
        DAT_011c52b8 = reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011c52e4)->Float()->f;
        DAT_011c52c0 = true;
    }
}

// Copies aggression, assistance, confidence, energy, responsibility, service flags, aggro radius and training data from source into this form.
// @fnv 0x0047f1e0
// src: XBOX_RETAIL_PDB 0x0047f1e0
// pdb: TESAIForm::CopyAIData | TESAIForm.obj | retail, call graph (shared callers), high
// pdb params: apAIForm
void TESAIForm::CopyAIData(TESAIForm* apAIForm)
{
    SetAggression(reinterpret_cast<PatrolActorPackageData*>(apAIForm)->IsPatrolling(), true);
    SetAssistance(apAIForm->GetAssistance());
    SetConfidence(apAIForm->_GetByte05(), true);
    SetEnergy(reinterpret_cast<BSAudio*>(apAIForm)->TESRegionData_GetPriority(), true);
    SetResponsibility(apAIForm->GetResponsibility(), true);
    SetAIMood(apAIForm->MenuTopic_GetTopicIsChoice());
    SetHasAggroRadius(reinterpret_cast<ActiveEffect*>(apAIForm)->FUN_00705cf0());
    SetAggroRadius(reinterpret_cast<TimeGlobal*>(apAIForm)->GetTimeStamp());
    SetServiceFlags(reinterpret_cast<TESForm*>(apAIForm)->GetFormID(), true);
    SetTrainingSkill(apAIForm->GetTrainingSkill());
    SetTrainingSkillLevel(reinterpret_cast<ActiveEffect*>(apAIForm)->GetByteAtOffset17());
}

// @fnv 0x0047ee00
// pdb: TESAIForm::SetAggression | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acAggression, abAddChange
void TESAIForm::SetAggression(unsigned char acAggression, bool abAddChange)
{
    aggression = acAggression;
    if (abAddChange)
    {
        DispatchToOuter(8);
    }
}

// @fnv 0x0047ee30
unsigned char TESAIForm::GetAssistance()
{
    return assistance;
}

// Stores value into assistance and calls DispatchToOuter with 8.
// @fnv 0x0047ee50
// pdb: TESAIForm::SetAssistance | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acAssistance
void TESAIForm::SetAssistance(unsigned char acAssistance)
{
    assistance = acAssistance;
    DispatchToOuter(8);
}

// Stores value into radius and calls DispatchToOuter with 8.
// @fnv 0x0047ee70
// pdb: TESAIForm::SetHasAggroRadius | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: abAggro
void TESAIForm::SetHasAggroRadius(bool abAggro)
{
    radius = abAggro;
    DispatchToOuter(8);
}

// Stores value into distance and calls DispatchToOuter with 8.
// @fnv 0x0047ee90
// pdb: TESAIForm::SetAggroRadius | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: auiRadius
void TESAIForm::SetAggroRadius(unsigned int auiRadius)
{
    distance = auiRadius;
    DispatchToOuter(8);
}

// @fnv 0x0047eed0
// pdb: TESAIForm::SetConfidence | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acConfidence, abAddChange
void TESAIForm::SetConfidence(unsigned char acConfidence, bool abAddChange)
{
    confidence = acConfidence;
    if (abAddChange)
    {
        DispatchToOuter(8);
    }
}

// @fnv 0x0047ef00
// pdb: TESAIForm::SetEnergy | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acEnergy, abAddChange
void TESAIForm::SetEnergy(unsigned char acEnergy, bool abAddChange)
{
    energy = acEnergy;
    if (abAddChange)
    {
        DispatchToOuter(8);
    }
}

// @fnv 0x0047ef30
unsigned char TESAIForm::GetResponsibility()
{
    return responsibility;
}

// @fnv 0x0047ef50
// pdb: TESAIForm::SetResponsibility | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acResponsibility, abAddChange
void TESAIForm::SetResponsibility(unsigned char acResponsibility, bool abAddChange)
{
    responsibility = acResponsibility;
    if (abAddChange)
    {
        DispatchToOuter(8);
    }
}

// @fnv 0x0047ef80
// pdb: TESAIForm::SetMood | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acMood
void TESAIForm::SetAIMood(unsigned char acMood)
{
    if (acMood < 8)
    {
        mood = acMood;
        DispatchToOuter(8);
    }
}

// @fnv 0x0047efb0
// pdb: TESAIForm::SetServiceFlags | TESAIForm.obj | debug, call graph (shared callers), high
// pdb params: aiServeFlags, abAddChange
void TESAIForm::SetServiceFlags(unsigned int aiServeFlags, bool abAddChange)
{
    services = aiServeFlags;
    if (abAddChange)
    {
        DispatchToOuter(8);
    }
}

// @fnv 0x0047f000
// pdb: TESAIForm::GetTrainingSkill | TESAIForm.obj | debug, upstream name already matches, high
// pdb locals: eskill
int TESAIForm::GetTrainingSkill()
{
    int result;
    result = skill + 0x20;
    return result;
}

// @fnv 0x0047f020
void TESAIForm::SetTrainingSkill(int value)
{
    if (IsSkill(static_cast<ActorValue::Index>(value)))
    {
        skill = static_cast<unsigned char>(value - 0x20);
    }
    DispatchToOuter(8);
}

// Stores the given value into level and calls DispatchToOuter with 8.
// @fnv 0x0047f090
// pdb: TESAIForm::SetTrainingSkillLevel | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: aiVal
void TESAIForm::SetTrainingSkillLevel(unsigned char aiVal)
{
    level = aiVal;
    DispatchToOuter(8);
}

// @fnv 0x0047f0b0
// pdb: TESAIForm::SetAIData | TESAIForm.obj | debug, object-file gap fill, medium
// pdb params: pAIData
void TESAIForm::CopyAIDataFromAIDATA(PackedRecordData* source)
{
    if (source)
    {
        SetAggression(source->m_ucField00, true);
        SetAssistance(source->m_ucField0E);
        SetConfidence(source->m_ucField01, true);
        SetEnergy(source->m_ucField02, true);
        SetResponsibility(source->m_ucField03, true);
        SetServiceFlags(source->m_uiField08, true);
        SetAIMood(source->m_ucField04);
        SetHasAggroRadius(source->m_bField0F);
        SetAggroRadius(source->m_uiField10);
        skill = source->m_ucField0C;
        level = source->m_ucField0D;
        if (confidence >= 5)
        {
            confidence = 0;
        }
    }
}

struct FUN_0047ee00_class
{
    void DispatchToOuter(int);
    void TESAIForm_SetAggression(unsigned char acAggression, bool abAddChange);
};

// Stores value at offset 4 of this object and, when flag is set, calls DispatchToOuter with 8.
// @fnv 0x0047ee00
// src: COMMUNITY 0x0047ee00
// pdb: TESAIForm::SetAggression | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acAggression, abAddChange
void FUN_0047ee00_class::TESAIForm_SetAggression(unsigned char acAggression, bool abAddChange)
{
    *(unsigned char*)((char*)this + 4) = acAggression;
    if (abAddChange)
        DispatchToOuter(8);
}

struct FUN_0047eed0_shell : public TESAIForm
{
    void TESAIForm_SetConfidence(unsigned char, bool);
};

// Sets confidence to acConfidence and, when abAddChange is true, calls DispatchToOuter with 8.
// @fnv 0x0047eed0
// src: COMMUNITY 0x0047eed0
// pdb: TESAIForm::SetConfidence | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acConfidence, abAddChange
void FUN_0047eed0_shell::TESAIForm_SetConfidence(unsigned char acConfidence, bool abAddChange)
{
    confidence = acConfidence;
    if (abAddChange)
        DispatchToOuter(8);
}

struct FUN_0047ef00_shell : public TESAIForm
{
    void TESAIForm_SetEnergy(unsigned char, bool);
};

// Sets the energy field to acEnergy and, when abAddChange is set, calls DispatchToOuter with 8.
// @fnv 0x0047ef00
// src: COMMUNITY 0x0047ef00
// pdb: TESAIForm::SetEnergy | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acEnergy, abAddChange
void FUN_0047ef00_shell::TESAIForm_SetEnergy(unsigned char acEnergy, bool abAddChange)
{
    energy = acEnergy;
    if (abAddChange)
        DispatchToOuter(8);
}

struct FUN_0047ef50_shell : public TESAIForm
{
    void TESAIForm_SetResponsibility(unsigned char, bool);
};

// Sets the responsibility field to acResponsibility and, when abAddChange is true, calls DispatchToOuter with 8.
// @fnv 0x0047ef50
// src: COMMUNITY 0x0047ef50
// pdb: TESAIForm::SetResponsibility | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acResponsibility, abAddChange
void FUN_0047ef50_shell::TESAIForm_SetResponsibility(unsigned char acResponsibility, bool abAddChange)
{
    responsibility = acResponsibility;
    if (abAddChange)
        DispatchToOuter(8);
}

struct FUN_0047ef80_shell : public TESAIForm
{
    void TESAIForm_SetMood(unsigned char);
};

// If acMood is below 8, stores it in mood and calls DispatchToOuter with 8.
// @fnv 0x0047ef80
// src: XBOX_PDB 0x0047ef80
// pdb: TESAIForm::SetMood | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: acMood
void FUN_0047ef80_shell::TESAIForm_SetMood(unsigned char acMood)
{
    if (acMood < 8)
    {
        mood = acMood;
        DispatchToOuter(8);
    }
}

struct FUN_0047efb0_shell : public TESAIForm
{
    void SetServices(unsigned int, bool);
};

// Stores aiServeFlags into services and, when abAddChange is set, calls DispatchToOuter(8).
// @fnv 0x0047efb0
// pdb: TESAIForm::SetServiceFlags | TESAIForm.obj | debug, call graph (shared callers), high
// pdb params: aiServeFlags, abAddChange
void FUN_0047efb0_shell::SetServices(unsigned int aiServeFlags, bool abAddChange)
{
    services = aiServeFlags;
    if (abAddChange)
        DispatchToOuter(8);
}

struct FUN_0047f020_shell : public TESAIForm
{
    void SetSkill(int);
};

// If aeSkill is a skill actor value, stores it minus 0x20 in skill, then calls DispatchToOuter(8).
// @fnv 0x0047f020
void FUN_0047f020_shell::SetSkill(int aeSkill)
{
    if (ActorValue::IsSkill((ActorValue::Index)aeSkill))
    {
        skill = aeSkill - 0x20;
    }
    DispatchToOuter(8);
}

// Returns true when index is between 0x20 and 0x2d inclusive.
// @fnv 0x0047f060
// src: XBOX_PDB 0x0047f060
bool __cdecl ActorValue_IsSkill(int index)
{
    return index >= 0x20 && index < 0x2e;
}

struct FUN_0047f4c0_shell : public TESAIForm
{
    void TESAIForm_InitItem(TESForm*);
};


extern Setting g_011c5348;

// If the Setting byte is zero, calls InitItem on the conditions object obtained from this, passing apOwner.
// @fnv 0x0047f4c0
// src: XBOX_PDB 0x0047f4c0
// pdb: TESAIForm::InitItem | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: apOwner
void FUN_0047f4c0_shell::TESAIForm_InitItem(TESForm* apOwner)
{
    if (!*g_011c5348.FUN_00408d60())
    {
        ((PackageList*)((BGSCameraPath*)this)->GetConditions())->InitItem(apOwner);
    }
}

namespace fnv_0047f500 {
struct FUN_0047f500_shell : public TESAIForm
{
    void TESAIForm_AddPackage(TESPackage*);
};

// Adds the given package to the package list obtained from the form's conditions.
// @fnv 0x0047f500
// src: XBOX_PDB 0x0047f500
// pdb: TESAIForm::AddPackage | TESAIForm.obj | debug, upstream name already matches, high
// pdb params: apPack
void FUN_0047f500_shell::TESAIForm_AddPackage(TESPackage* apPack)
{
    ((PackageList*)((BGSCameraPath*)this)->GetConditions())->AddPackage(apPack);
}
}  // namespace fnv_0047f500

struct FUN_0062f2f0_shell : public TESAIForm
{
    unsigned char MenuTopic_GetTopicIsChoice();
};

// @fnv 0x0062f2f0
// src: COMMUNITY 0x0062f2f0
unsigned char FUN_0062f2f0_shell::MenuTopic_GetTopicIsChoice()
{
    return *((unsigned char*)this + 8);
}

extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
    BFC_s();
};
struct CondS
{
    char p[8];
    CondS();
    ~CondS();
};
struct FUN_0047ec40 : public BFC_s
{
    char pad[0x14];
    CondS m_kCondition;
    void InitializeComponent();
    FUN_0047ec40();
    virtual void v();
};
// @fnv 0x0047ec40
// pdb: TESAIForm::TESAIForm | TESAIForm.obj | debug, call graph, high
FUN_0047ec40::FUN_0047ec40()
{
    InitializeComponent();
}

namespace fnv_0047ecb0 {
extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
};
struct CondS
{
    char p[8];
    CondS();
    ~CondS();
};
struct FUN_0047ecb0 : public BFC_s
{
    char pad[0x14];
    CondS m_kCondition;
    void FreeDataComponent();
    virtual ~FUN_0047ecb0();
};
// Destructor that calls FreeDataComponent to release the object's data component.
// @fnv 0x0047ecb0
// pdb: TESAIForm::~TESAIForm | TESAIForm.obj | debug, call graph, medium
FUN_0047ecb0::~FUN_0047ecb0()
{
    FreeDataComponent();
}
}  // namespace fnv_0047ecb0

extern float DAT_011c52a8;

// @fnv 0x0047eeb0
// src: XBOX_PDB 0x0047eeb0
float __cdecl TESAIForm_GetConfidenceLevel(unsigned char a)
{
    if (a >= 5)
        return 0.0f;
    return *(float*)(&DAT_011c52a8 + a);
}

struct FUN_0047f7e0_shell
{
    unsigned short __thiscall TESAIForm_GetSaveSize(unsigned int aiFlags);
};

// @fnv 0x0047f7e0
// src: XBOX_PDB 0x0047f7e0
unsigned short __thiscall FUN_0047f7e0_shell::TESAIForm_GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 8)
    {
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 1;
        isize += 1;
    }
    return isize;
}

struct FUN_0047efe0_shell
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_flags;
    bool HasFlags(int arg);
};

// @fnv 0x0047efe0
// pdb: TESAIForm::SetOffersService | TESAIForm.obj | debug, object-file gap fill, medium
// pdb params: aiServeFlags, abOffersService
bool FUN_0047efe0_shell::HasFlags(int aiFlags)
{
    if (m_flags & aiFlags)
    {
        return true;
    }
    else
    {
        return false;
    }
}




struct FUN_0047f8c0_shell
{
    void __thiscall TESAIForm_LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// @fnv 0x0047f8c0
// src: XBOX_PDB 0x0047f8c0
// pdb: TESAIForm::LoadGame | TESAIForm.obj | retail, vtable slot, high
// pdb params: aiFlags, aiCurrentFlags
void __thiscall FUN_0047f8c0_shell::TESAIForm_LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    if (aiFlags & 8)
    {
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 4), 1);
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 5), 1);
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 6), 1);
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 7), 1);
        g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 8), 1);
    }
}

struct FakeOuter
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void v18(int);
};
struct MyInner
{
    void DispatchToOuter(int);
};
// Computes the enclosing FakeOuter from this (offset 0x90) and, if non-null, calls its v18 with arg.
// @fnv 0x0047f790
// pdb: TESAIForm::AddFormChange | TESAIForm.obj | debug, call graph (shared callers), medium
// pdb params: aiChangeFlags
// pdb locals: pactbase, pform
void MyInner::DispatchToOuter(int arg)
{
    FakeOuter* b = this ? (FakeOuter*)((char*)this - 0x90) : (FakeOuter*)0;
    FakeOuter* a = b;
    if (a != 0)
        a->v18(arg);
}

namespace fnv_0047f840 {
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0047f840_shell
{
    void TESAIForm_SaveGame(unsigned int aiFlags);
};

// When the flags include 8, passes five consecutive bytes starting at this+4 to TESSaveLoadGame's save routine.
// @fnv 0x0047f840
// src: XBOX_PDB 0x0047f840
// pdb: TESAIForm::SaveGame | TESAIForm.obj | retail, vtable slot, high
// pdb params: aiFlags
void FUN_0047f840_shell::TESAIForm_SaveGame(unsigned int aiFlags)
{
    if (aiFlags & 8)
    {
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 4, 1);
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 5, 1);
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 6, 1);
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 7, 1);
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD((char*)this + 8, 1);
    }
}
}  // namespace fnv_0047f840

struct FUN_0047f300_shell
{
    bool TESAIForm_CompareComponent(BaseFormComponent* apCompareFC);
};

// Compares this object with apCompareFC via a TESAIForm cast and many field getters, returning true if any differ or the cast fails.
// @fnv 0x0047f300
// src: XBOX_PDB 0x0047f300
// pdb: TESAIForm::CompareComponent | TESAIForm.obj | retail, upstream name already matches, high
// pdb params: apCompareFC
// pdb locals: pCompare
bool FUN_0047f300_shell::TESAIForm_CompareComponent(BaseFormComponent* apCompareFC)
{
    TESAIForm* pCompare = dynamic_cast<TESAIForm*>(apCompareFC);
    if (!pCompare)
        return true;

    if (reinterpret_cast<PatrolActorPackageData*>(this)->IsPatrolling() !=
        reinterpret_cast<PatrolActorPackageData*>(pCompare)->IsPatrolling())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetAssistance() != pCompare->GetAssistance())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->_GetByte05() != pCompare->_GetByte05())
        return true;

    if (reinterpret_cast<BSAudio*>(this)->TESRegionData_GetPriority() != reinterpret_cast<BSAudio*>(pCompare)->TESRegionData_GetPriority())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetResponsibility() != pCompare->GetResponsibility())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->MenuTopic_GetTopicIsChoice() != pCompare->MenuTopic_GetTopicIsChoice())
        return true;

    if (reinterpret_cast<TimeGlobal*>(this)->GetTimeStamp() != reinterpret_cast<TimeGlobal*>(pCompare)->GetTimeStamp())
        return true;

    if (reinterpret_cast<ActiveEffect*>(this)->FUN_00705cf0() !=
        reinterpret_cast<ActiveEffect*>(pCompare)->FUN_00705cf0())
        return true;

    if (reinterpret_cast<TESForm*>(this)->GetFormID() != reinterpret_cast<TESForm*>(pCompare)->GetFormID())
        return true;

    if (reinterpret_cast<TESAIForm*>(this)->GetTrainingSkill() != pCompare->GetTrainingSkill())
        return true;

    if (reinterpret_cast<ActiveEffect*>(this)->GetByteAtOffset17() !=
        reinterpret_cast<ActiveEffect*>(pCompare)->GetByteAtOffset17())
        return true;

    if (reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())
            ->DiffersFrom(reinterpret_cast<PackageList*>(reinterpret_cast<BGSCameraPath*>(pCompare)->GetConditions())))
        return true;

    return false;
}

struct AIFormFlags
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_flags;
    bool HasFlags(int arg);
    bool TESAIForm_SellBuysItem(TESForm* apObject);
};

struct FormTypeStub
{
    int GetFormType();
};

// Maps the form's type (and equip type for type 0x2f) to a flag bit and returns the result of HasFlags for that bit.
// @fnv 0x0047f600
// src: COMMUNITY 0x0047f600
// pdb: TESAIForm::SellBuysItem | TESAIForm.obj | retail, upstream name already matches, high
// pdb params: apObject
// pdb locals: abflag, aeItemType, palcitem
bool AIFormFlags::TESAIForm_SellBuysItem(TESForm* apObject)
{
    bool bResult2 = false;
    int iType8 = ((FormTypeStub*)apObject)->GetFormType();
    switch (iType8)
    {
    case 0x28:
        bResult2 = HasFlags(1);
        break;
    case 0x29:
        bResult2 = HasFlags(1);
        break;
    case 0x18:
        bResult2 = HasFlags(2);
        break;
    case 0x2f: {
        TESForm* pForm = apObject;
        switch (BGSEquipType::GetEquipType(pForm))
        {
        case 10:
            bResult2 = HasFlags(0x20);
            break;
        case 11:
            bResult2 = HasFlags(0x40);
            break;
        case 12:
            bResult2 = HasFlags(0x10);
            break;
        case 13:
            bResult2 = HasFlags(4);
            break;
        }
        break;
    }
    case 0x19:
        bResult2 = HasFlags(8);
        break;
    case 0x1f:
    case 0x32:
    case 0x67:
        bResult2 = HasFlags(0x400);
        break;
    }
    return bResult2;
}
