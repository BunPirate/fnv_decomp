// fallout_shared/magic/effectsettingcollection.cpp: EffectSettingCollection (3 functions)

#include "../../../include/EffectSetting.h"
#include "../../../include/LowProcess.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/TESSaveLoadGame.h"

class Date;

class PlayerQuestData
{
  public:
    void SetLogDate(Date* value);
};

TESForm* GetFormByID(unsigned int formID);
void EffectSettingCollection_AddEffect(EffectSetting* apSetting);

typedef int ActorValueIndex;

// pdb: class EffectSettingCollection, size 0x8 (here 0x3ec), bases: BSSimpleList<EffectSetting *>, 0 members
class EffectSettingCollection
{
  public:
    unsigned char layoutPadding0[0x3E8];
    unsigned int uiFlags;

    void InitializeCollection(bool initialize);
    static void CreateDefaultEffects();
    static EffectSetting* CreateDefaultEffect(unsigned int aiFormID, char* acEditorID, char* apEffectName, ActorValueIndex aiAssociatedSkill,
                                              float afBaseCost, ActorValueIndex aeAssociatedActorVaue, unsigned int aiFlags,
                                              ActorValueIndex aiResistVariable, int aiEffectArchetype);
};

extern "C" EffectSetting* DAT_011c33f4;

// @fnv 0x00471D00
// pdb: NiFile::InvokeReadErrorFunc | NiFile_Xenon.obj | debug, call graph, medium
// pdb params: apFile
void EffectSettingCollection::InitializeCollection(bool initialize)
{
    if (initialize)
        uiFlags |= 4;
    else
    {
        uiFlags &= ~4;
        uiFlags &= ~8;
    }
}

// @fnv 0x00408E40
// src: XBOX_RETAIL_PDB 0x00408e40
// pdb: EffectSettingCollection::CreateDefaultEffect | EffectSettingCollection.obj | retail, call graph, high
// pdb params: aiFormID, acEditorID, apEffectName, aiAssociatedSkill, afBaseCost, aeAssociatedActorVaue, aiFlags, aiResistVariable, aiEffectArchetype
// pdb locals: psettings
EffectSetting* EffectSettingCollection::CreateDefaultEffect(unsigned int aiFormID, char* acEditorID, char* apEffectName,
                                                            ActorValueIndex aiAssociatedSkill, float afBaseCost, ActorValueIndex aeAssociatedActorVaue,
                                                            unsigned int aiFlags, ActorValueIndex aiResistVariable, int aiEffectArchetype)
{
    if (GetFormByID(aiFormID))
        return 0;

    EffectSetting* effect = new EffectSetting();
    effect->SetRefID(aiFormID, true);
    effect->SetEditorID_AtRuntime(acEditorID);
    ((LowProcess*)effect)->LowProcess::SetPackageObjectType(aiFlags);
    effect->UpdateEffectName(apEffectName);
    effect->BSShaderProperty_SetDepthBias(afBaseCost);
    effect->SetAssociatedActorValue(aeAssociatedActorVaue);
    ((MiddleHighProcess*)effect)->MiddleHighProcess::AddDeferredHideLimb((ObjectToAcquire*)aiAssociatedSkill);
    ((PlayerQuestData*)effect)->SetLogDate((Date*)aiResistVariable);
    effect->SetEffectID(aiEffectArchetype);
    EffectSettingCollection_AddEffect(effect);
    return effect;
}

// @fnv 0x00408F60
// src: XBOX_RETAIL_PDB 0x00408f60
// pdb: EffectSettingCollection::CreateDefaultEffects | EffectSettingCollection.obj | retail, string-set bridge, high
void EffectSettingCollection::CreateDefaultEffects()
{
    CreateDefaultEffect(0x14A, "ScriptEffect", "Script Effect", -1, 0.0f, -1, 0x170, -1, 1);
    CreateDefaultEffect(0x14B, "FireDamage", "Fire Damage", -1, 0.0f, 0x10, 0x20000475, 0x34, 0);
    CreateDefaultEffect(0x14C, "FrostDamage", "Frost Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateDefaultEffect(0x14D, "ShockDamage", "Shock Damage", -1, 0.0f, 0x10, 0x20000475, -1, 0);
    CreateDefaultEffect(0x14E, "RestoreHealth", "Restore Health", -1, 0.0f, 0x10, 0x70, -1, 0);
    DAT_011c33f4 = CreateDefaultEffect(0x14F, "UMON", "Usage Monitor Effect", -1, 0.0f, -1, 0x12, -1, 1);
}

struct G2
{
    void AddHead(int**);
};
struct GlobalObject_00680890 : public G2
{
};
extern GlobalObject_00680890 g_011c3400;
// @fnv 0x00409060
// src: XBOX_DEBUG_PDB 0x00409060
// pdb: EffectSettingCollection::AddEffect | EffectSettingCollection.obj | debug, call graph, high
// pdb params: apSetting
void EffectSettingCollection_AddEffect(int* apSetting)
{
    if (apSetting)
        g_011c3400.AddHead(&apSetting);
}

struct FUN_00408b60
{
    void DestroyAllItems(void);
};

// @fnv 0x00408de0
// src: COMMUNITY 0x00408de0
// pdb: EffectSettingCollection::Reset | EffectSettingCollection.obj | debug, call graph (shared callers), medium
void __cdecl EffectSettingCollection_Destroy()
{
    ((FUN_00408b60*)&g_011c3400)->DestroyAllItems();
}

// Save-game header of the form being sized: formID, change type byte, then (packed) change flags.
struct ChangedForm
{
    unsigned int formID;
    unsigned char changeType;
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* TESForm_GetFormByNumericID(unsigned int formID);
void ProgramFlow(const char* format, ...);

// Computes the save size of the effect setting collection, adding 4/2 bytes for save-load state and 4 bytes per flagged EffectSetting, then logs the result.
// @fnv 0x00408c30
// src: COMMUNITY 0x00408c30
// pdb: EffectSettingCollection::GetKnownEffectsSaveSize | EffectSettingCollection.obj | retail, upstream name already matches, high
// pdb locals: isize, itempStartSize, psetting, pnode, pheader, pform
unsigned int EffectSettingCollection_GetKnownEffectsSaveSize()
{
    unsigned int size = 0;
    EffectSetting* mgef;
    unsigned short uiStart = (unsigned short)size;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        size += 4;
        size += 2;
    }
    size += 4;
    for (BSSimpleList<EffectSetting*>* node = (BSSimpleList<EffectSetting*>*)&g_011c3400;
         node && (mgef = node->GetItem()) != 0; node = node->GetNext())
    {
        if (mgef->IsFlagSet(0x200000))
            size += 4;
    }
    if (*g_011de4e8.Bool())
    {
        ChangedForm* changed = (ChangedForm*)g_TESSaveLoadGame->FUN_004fd3e0();
        if (changed)
        {
            TESForm* form = TESForm_GetFormByNumericID(changed->formID);
            ProgramFlow("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         size - uiStart, changed->formID, form->GetName(), *(unsigned int*)(&changed->changeType + 1),
                         0x77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Magic\\EffectSettingCollection.cpp");
        }
        else
        {
            ProgramFlow("GetSaveSize(): %-5i ending at line %i in file %s", size - uiStart, 0x77,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Magic\\EffectSettingCollection.cpp");
        }
    }
    return size;
}
