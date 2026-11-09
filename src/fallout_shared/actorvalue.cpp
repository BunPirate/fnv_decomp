// fallout_shared/actorvalue.cpp: ActorValue, ActorValueInfo, ActorValueOwner, TESObjectWEAP and more (38 functions)

#include "actorvalue_decls.h"

// Registers all built-in actor values with their flags and callbacks, sets enumerated names for AI attributes, then marks DAT_011d6154 as initialized.
// @fnv 0x0066f260
// src: XBOX_RETAIL_PDB 0x0066f260
// pdb: ActorValue::RegisterActorValues | ActorValue.obj | retail, unique string literal, high
// pdb locals: pinfo, i
void ActorValue::ActorValue_RegisterActorValues()
{
    if (DAT_011d6154)
        return;
    ActorValueInfo* info;
    ActorValue_RegisterActorValue(ActorValue__Index_AGGRESSION, "Aggression", AI_ATTRIBUTE, 0x101, 0x0, 0x0, AV_Aggression_HandleChange, 0x0);
    info = GetActorValueInfo(ActorValue__Index_AGGRESSION);
    if (info)
        info->SetEnumerated(4, "Unaggressive", "Aggressive", "Very Aggressive", "Frenzied");
    ActorValue_RegisterActorValue(ActorValue__Index_ASSISTANCE, "Assistance", AI_ATTRIBUTE, 0x101, 0x0, 0x0,
                       SetProcessFlagIfActive, 0x0);
    info = GetActorValueInfo(ActorValue__Index_ASSISTANCE);
    if (info)
        info->SetEnumerated(3, "Helps Nobody", "Helps Allies", "Helps Friends and Allies");
    ActorValue_RegisterActorValue(ActorValue__Index_CONFIDENCE, "Confidence", AI_ATTRIBUTE, 0x101, 0x0, 0x0, 0x0, 0x0);
    info = GetActorValueInfo(ActorValue__Index_CONFIDENCE);
    if (info)
        info->SetEnumerated(5, "Cowardly", "Cautious", "Average", "Brave", "Foolhardy");
    ActorValue_RegisterActorValue(ActorValue__Index_ENERGY, "Energy", AI_ATTRIBUTE, 0x1, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_RESPONSIBILITY, "Responsibility", AI_ATTRIBUTE, 0x1, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_MOOD, "Mood", AI_ATTRIBUTE, 0x101, 0x0, 0x0, 0x0, 0x0);
    info = GetActorValueInfo(ActorValue__Index_MOOD);
    if (info)
        info->SetEnumerated(9, "Neutral", "Afraid", "Annoyed", "Cocky", "Drugged", "Pleasant", "Angry", "Sad",
                            "UNDEFINED");
    ActorValue_RegisterActorValue(ActorValue__Index_STRENGTH, "Strength", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0xd, 0x26, 0x11);
    ActorValue_RegisterActorValue(ActorValue__Index_PERCEPTION, "Perception", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0x22, 0x24,
                       0x23);
    ActorValue_RegisterActorValue(ActorValue__Index_ENDURANCE, "Endurance", ATTRIBUTE, 0x8009, 0x0, 0x0, Actor_EnduranceModifiedCallback, 0x7, 0x10,
                       0xf, 0x13, 0x14, 0x21, 0x2d, 0x2c);
    ActorValue_RegisterActorValue(ActorValue__Index_CHARISMA, "Charisma", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x2, 0x20, 0x2b);
    ActorValue_RegisterActorValue(ActorValue__Index_INTELLIGENCE, "Intelligence", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0x28,
                       0x27, 0x25);
    ActorValue_RegisterActorValue(ActorValue__Index_AGILITY, "Agility", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0x3, 0xc, 0x29, 0x2a);
    ActorValue_RegisterActorValue(ActorValue__Index_LUCK, "Luck", ATTRIBUTE, 0x8009, 0x0, 0x0, 0x0, 0xf, 0xe, 0x20, 0x21, 0x22,
                       0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2d, 0x2c);
    ActorValue_RegisterActorValue(ActorValue__Index_ACTION_POINTS, "ActionPoints", DERIVED_ATTRIBUTE, 0x0, AiFormulas_AVDeriveActionPoints, 0x0, 0x0,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_CARRY_WEIGHT, "CarryWeight", DERIVED_ATTRIBUTE, 0x801, AiFormulas_AVDeriveCarryWeight, 0x0, 0x0,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_CRITICAL_CHANCE, "CritChance", DERIVED_ATTRIBUTE, 0x800, AiFormulas_AVDeriveCriticalChance, 0x0,
                       0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_HEALING_RATE, "HealRate", DERIVED_ATTRIBUTE, 0x801, AiFormulas_AVDeriveHealingRate, 0x0,
                       AV_HealRate_HandleChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_HEALTH, "Health", DERIVED_ATTRIBUTE, 0x10c1, AiFormulas_AVDeriveHealth, 0x0,
                       UpdateActorValueFlag, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_MELEE_DAMAGE, "MeleeDamage", DERIVED_ATTRIBUTE, 0x800, AiFormulas_AVDeriveFromPrimary, 0x0, 0x0,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_DAMAGE_RESISTANCE, "DamageResist", RESISTANCE, 0x800, AV_DamageResist_CalculateDefault, 0x0,
                       Actor_ResetActorDTDR, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_POISON_RESISTANCE, "PoisonResist", RESISTANCE, 0x800, AiFormulas_AVDeriveResistance, 0x0, 0x0,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_RADIATION_RESISTANCE, "RadResist", RESISTANCE, 0x800, AiFormulas_AVDeriveResistance, 0x0,
                       AV_RadResist_HandleChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_FIRE_RESISTANCE, "FireResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_ELECTRICAL_RESISTANCE, "ElectricResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_FROST_RESISTANCE, "FrostResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_ENERGY_RESISTANCE, "EnergyResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_EMP_RESISTANCE, "EmpResist", RESISTANCE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SPEED_MULT, "SpeedMult", DERIVED_ATTRIBUTE, 0x801, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_FATIGUE, "Fatigue", DERIVED_ATTRIBUTE, 0x1841, AiFormulas_AVDeriveFatigue, 0x0,
                       UpdateActorValueFlag, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_PERCEPTION_CONDITION, "PerceptionCondition", CONDITION, 0x821, AiFormulas_AVDeriveBodyPartCondition, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_ENDURANCE_CONDITION, "EnduranceCondition", CONDITION, 0x821, AiFormulas_AVDeriveBodyPartCondition, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_LEFT_ATTACK_CONDITION, "LeftAttackCondition", CONDITION, 0x821, AiFormulas_AVDeriveBodyPartCondition,
                       0x0, Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_RIGHT_ATTACK_CONDITION, "RightAttackCondition", CONDITION, 0x821, AiFormulas_AVDeriveBodyPartCondition,
                       0x0, Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_LEFT_MOBILITY_CONDITION, "LeftMobilityCondition", CONDITION, 0x821, AiFormulas_AVDeriveBodyPartCondition,
                       0x0, Actor::UpdateMobilityConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_RIGHT_MOBILITY_CONDITION, "RightMobilityCondition", CONDITION, 0x821,
                       AiFormulas_AVDeriveBodyPartCondition, 0x0, Actor::UpdateMobilityConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_BRAIN_CONDITION, "BrainCondition", CONDITION, 0x820, AiFormulas_AVDeriveBodyPartCondition, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_KARMA, "Karma", DERIVED_ATTRIBUTE, 0x4000, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_EXPERIENCE_POINTS, "XP", DERIVED_ATTRIBUTE, 0x4000, 0x0, 0x0, AV_XP_HandleChange,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_UNARMED_DAMAGE, "UnarmedDamage", DERIVED_ATTRIBUTE, 0x800, AiFormulas_AVDeriveUnarmedDamage, 0x0,
                       0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_BARTER, "Barter", SKILL, 0x10, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_BIG_GUNS, "BigGuns", SKILL, 0x2000, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_ENERGY_WEAPONS, "EnergyWeapons", SKILL, 0x410, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_EXPLOSIVES, "Explosives", SKILL, 0x410, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_LOCKPICK, "Lockpick", SKILL, 0x10, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_MEDICINE, "Medicine", SKILL, 0x10, callback4C, 0x0, AV_Medicine_HandleChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_MELEE_WEAPONS, "MeleeWeapons", SKILL, 0x410, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_REPAIR, "Repair", SKILL, 0x10, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SCIENCE, "Science", SKILL, 0x10, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SMALL_GUNS, "Guns", SKILL, 0x410, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SNEAK, "Sneak", SKILL, 0x11, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SPEECH, "Speech", SKILL, 0x10, callback4C, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SURVIVAL, "Survival", SKILL, 0x10, callback4C, 0x0, AV_Survival_HandleChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_UNARMED, "Unarmed", SKILL, 0x410, callback4C, 0x0, 0x0, 0x1, 0x38);
    ActorValue_RegisterActorValue(ActorValue__Index_INVENTORY_WEIGHT, "InventoryWeight", DERIVED_ATTRIBUTE, 0x1, Actor_GetInventoryWeight, 0x0,
                       Actor::HandleActorValueUpdate, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_PARALYSIS, "Paralysis", INT_VALUE, 0x1, 0x0, 0x0, AV_Paralysis_HandleChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_INVISIBILITY, "Invisibility", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_CHAMELEON, "Chameleon", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_NIGHT_EYE_BONUS, "NightEye", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_TURBO, "Turbo", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_WATER_BREATHING, "WaterBreathing", INT_VALUE, 0x1, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_RADIATION_RADS, "RadiationRads", INT_VALUE, 0x220, 0x0, 0x0,
                       Actor::HandleRadiationValueChange, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_BLOODY_MESS, "BloodyMess", INT_VALUE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_01, "Variable01", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_02, "Variable02", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_03, "Variable03", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_04, "Variable04", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_05, "Variable05", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_06, "Variable06", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_07, "Variable07", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_08, "Variable08", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_09, "Variable09", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_VARIABLE_10, "Variable10", VARIABLE, 0x0, 0x0, 0x0, 0x0, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_IGNORE_CRIPPLED_LIMBS, "IgnoreCrippledLimbs", VARIABLE, 0x1, 0x0, 0x0,
                       Actor::UpdateActorConditionValue, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_DEHYDRATION, "Dehydration", INT_VALUE, 0x221, 0x0, 0x0, UpdateStageChange,
                       0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_HUNGER, "Hunger", INT_VALUE, 0x221, 0x0, 0x0, UpdateStageTransition, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_SLEEPDEPREVATION, "SleepDeprevation", INT_VALUE, 0x221, 0x0, 0x0,
                       OnSleepDeprivationStageChanged, 0x0);
    ActorValue_RegisterActorValue(ActorValue__Index_DAMAGE_THRESHOLD, "DamageThreshold", RESISTANCE, 0x800, ActorValueOwner_GetTotalArmorDT, 0x0,
                       Actor_ResetActorDTDR, 0x0);
    for (int index = 0; index < ActorValue__Index_ACTOR_VALUE_COUNT; ++index)
    {
    }
    DAT_011d6154 = true;
}

// @fnv 0x006701a0
// pdb: ActorValueInfo::Load | ActorValue.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: chunkid, formid, pMessage, pmessage
bool ActorValueInfo::Load(TESFile* apFile)
{
    unsigned char formType = apFile->GetTESForm();
    if (formType != 89)
        return false;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    int uiChunkID;
    while ((uiChunkID = apFile->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case 0x43534544:
            TESDescription::ReadDescriptionFromFile(this, apFile);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, apFile);
            break;
        case 0x4d414e41:
            if (apFile->GetChunkSize())
            {
                char* abbreviation = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(abbreviation, 0);
                m_cAbbreviation = abbreviation;
            }
            else
            {
                m_cAbbreviation = "";
            }
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// Clamps value to [0,100] when flag 0x10 is set, or to [0 or 1,10] when flag 8 is set, otherwise returns it unchanged.
// @fnv 0x0066f190
// pdb: ActorValue::ClampActorValue | ActorValue.obj | debug, call graph, medium
// pdb params: aiWhich, afValue
// pdb locals: fresult, fmin
float ActorValue::ClampValue(Index index, float value)
{
    float result = value;
    if (GetFlag(index, 0x10))
    {
        result = BSMAX_00404010(0.0f, BSMIN(result, 100.0f));
    }
    else if (GetFlag(index, 8))
    {
        float minimum = GetFlag(index, 0x8000) ? 1.0f : 0.0f;
        result = BSMAX_00404010(minimum, BSMIN(result, 10.0f));
    }
    return result;
}

// Maps a section and index to an ActorValue::Index by adding a per-section offset, returning 0 for unknown sections.
// @fnv 0x0066ec10
ActorValue::Index ActorValue::GetActorValueForSectionIndex(Section section, char index)
{
    switch (section)
    {
    case ATTRIBUTE:
        return (Index)(index + 5);
    case DERIVED_ATTRIBUTE:
        return (Index)(index + 12);
    case SKILL:
        return (Index)(index + 32);
    case AI_ATTRIBUTE:
        return (Index)index;
    case CONDITION:
        return (Index)(index + 25);
    case INT_VALUE:
        return (Index)(index + 46);
    default:
        return (Index)0;
    }
}

// Returns the number of entries in the given ActorValue section, or 0 for an unknown section.
// @fnv 0x0066ecf0
// pdb: ActorValue::GetActorValueIndex | ActorValue.obj | retail, object-file run extension, low
// pdb params: acScriptName
// pdb locals: eresult, i
unsigned int ActorValue::GetCountForSection(Section section)
{
    switch (section)
    {
    case ATTRIBUTE:
        return 7;
    case DERIVED_ATTRIBUTE:
        return 20;
    case SKILL:
        return 14;
    case AI_ATTRIBUTE:
        return 5;
    case CONDITION:
        return 7;
    case INT_VALUE:
        return 16;
    default:
        return 0;
    }
}

// @fnv 0x0066e950
// src: XBOX_DEBUG_PDB 0x0066e950
// pdb: ActorValue::GetActorValueName | ActorValue.obj | debug, upstream name already matches, high
// pdb params: aiIndex
// pdb locals: pinfo
const char* ActorValue::ActorValue_GetActorValueName(Index aiIndex)
{
    ActorValueInfo* info = GetActorValueInfo(aiIndex);
    if (info)
    {
        if (info->GetFullName() && BSStringLength(info->GetFullName()))
        {
            return info->GetFullName();
        }
        else
        {
            return info->m_pName;
        }
    }
    return 0;
}

// Zeroes value, looks up the ActorValueInfo for index, and if it has a getter, stores the getter's result in value and returns true.
// @fnv 0x0066ed60
// src: XBOX_RETAIL_PDB 0x0066ed60
// pdb: ActorValue::GetDerivedActorValue | ActorValue.obj | retail, call graph (shared callers), high
// pdb params: apActor, aiWhich, afValue
// pdb locals: pinfo, bresult
bool ActorValue::ActorValue_GetDerivedActorValue(ActorValueOwner* apActor, Index aiWhich, float& afValue)
{
    ActorValueInfo* info;
    bool result = false;
    afValue = 0.0f;
    info = GetActorValueInfo(aiWhich);
    if (info && info->m_pDerivedValueFunction)
    {
        afValue = info->m_pDerivedValueFunction(apActor, aiWhich);
        result = true;
    }
    return result;
}

// Looks up the ActorValueInfo for index and, if it has a change handler, invokes it with owner, index, oldValue, newValue and source.
// @fnv 0x0066ee50
// pdb: ActorValue::CheckCallModifiedCallback | ActorValue.obj | debug, call graph, medium
// pdb params: apActor, aiWhich, afOriginalValue, afDelta, apActorSource
// pdb locals: pinfo
void ActorValue::NotifyActorValueChanged(ActorValueOwner* owner, Index index, float oldValue, float newValue,
                                         ActorValueOwner* source)
{
    ActorValueInfo* info = GetActorValueInfo(index);
    if (info && info->pModifiedCallback)
    {
        info->pModifiedCallback(owner, index, oldValue, newValue, source);
    }
}

// Stores item into modItem1, modItem2 or modItem3 depending on slot (1, 2 or 4).
// @fnv 0x00521480
// pdb: TESObjectWEAP::GetMinSpreadDegrees | TESObjectWEAP.obj | retail, object-file run extension, low
// pdb params: bModValue
void TESObjectWEAP::SetModItem(unsigned int slot, TESObjectIMOD* item)
{
    if (slot == 1)
    {
        pModObjectOne = item;
    }
    else if (slot == 2)
    {
        pModObjectTwo = item;
    }
    else if (slot == 4)
    {
        pModObjectThree = item;
    }
}

// Looks up the ActorValueInfo for index and returns its array pointer and count via count; returns null and zero count if no info exists.
// @fnv 0x0066edc0
ActorValue::Index* ActorValue::GetDependentActorValueIndices(Index index, int& count)
{
    ActorValueInfo* info;
    Index* result = 0;
    count = 0;
    info = GetActorValueInfo(index);
    if (info)
    {
        result = info->DependentActorValues;
        count = info->iNumDependentActorValues;
    }
    return result;
}

// @fnv 0x0066ef50
// pdb: ActorValueOwner::GetClampedActorFloatValue | ActorValue.obj | retail, call graph, high
// pdb params: aiWhich
// pdb locals: fresult
float ActorValueOwner::GetActorValueFloatByIndex(ActorValue::Index aiWhich)
{
    float result = GetCurrentActorValue(aiWhich);
    result = ActorValue::ClampValue(aiWhich, result);
    return result;
}

// @fnv 0x0066ee10
// pdb: ActorValue::HasModifiedCallback | ActorValue.obj | debug, call graph, medium
// pdb params: aiWhich
// pdb locals: pinfo
bool ActorValue::HasActorValueChangedCallback(Index index)
{
    ActorValueInfo* info = GetActorValueInfo(index);
    return info && info->pModifiedCallback;
}

// @fnv 0x0066ef20
// pdb: ActorValueOwner::GetClampedActorValue | ActorValue.obj | retail, call graph, high
// pdb params: aiWhich
int ActorValueOwner::GetActorValueAsInteger(ActorValue::Index aiWhich)
{
    return (int)floorf(GetActorValueFloatByIndex(aiWhich));
}

// @fnv 0x0066fe40
// pdb: ActorValueInfo::ActorValueInfo | ActorValue.obj | retail, string-set bridge, high
// pdb params: aiWhich, apScriptName
// pdb locals: cformID, i
ActorValueInfo::ActorValueInfo(int aiWhich, const char* apScriptName)
{
    SetFormType((ENUM_FORM_ID)0x59);
    if (aiWhich != -1)
        SetFormID(GetActorValueFormID((ActorValue::Index)aiWhich), false);
    m_pName = (char*)apScriptName;
    if (apScriptName)
    {
        char buffer[100];
        sprintf_s(buffer, 100, "AV%s", apScriptName);
        SetScriptName(buffer);
    }
    m_cAbbreviation = "";
    uFlags = 0;
    m_pDerivedValueFunction = 0;
    pMappingFunction = 0;
    pModifiedCallback = 0;
    iNumDependentActorValues = 0;
    for (int i = 0; i < 15; ++i)
        DependentActorValues[i] = ActorValue::ActorValue__Index_ACTOR_VALUE_COUNT;
    iEnumCount = 0;
    for (int jIndex = 0; jIndex < 10; ++jIndex)
        sEnumNames[jIndex] = 0;
}

// @fnv 0x0066efe0
// src: XBOX_RETAIL_PDB 0x0066efe0
// pdb: ActorValue::RegisterActorValue | ActorValue.obj | retail, upstream name already matches, high
// pdb params: aiWhich, asScriptName, aeAVType, auFlags, apDerivationFunction, apMappingFunction, apModifiedCallback, aiNumDependentActorValues, ap
void ActorValue::ActorValue_RegisterActorValue(Index index, char* name, Section section, unsigned int flags,
                                    ActorValueDeriveCallback derive, ActorValueMappingCallback mapping,
                                    ActorValueModifiedCallback modified, int count, ...)
{
    if (!g_011d61c8.values[index])
    {
        ActorValueInfo* info = new ActorValueInfo(index, name);
        info->eAVType = section;
        info->uFlags = flags;
        info->m_pDerivedValueFunction = derive;
        info->pMappingFunction = mapping;
        info->pModifiedCallback = modified;
        info->iNumDependentActorValues = MinInt(count, 15);
        if (count > 0)
        {
            va_list args;
            va_start(args, count);
            for (int i = 0; i < info->iNumDependentActorValues; ++i)
            {
                Index dependent = va_arg(args, Index);
                info->DependentActorValues[i] = dependent;
            }
            va_end(args);
        }
        g_011d61c8.values[index] = info;
    }
}

// @fnv 0x00670120
// pdb: ActorValueInfo::SetEnumerated | ActorValue.obj | retail, upstream name already matches, high
// pdb params: aiEnumCount, ap
// pdb locals: i, pname
void ActorValueInfo::SetEnumerated(int count, ...)
{
    iEnumCount = MinInt(count, 10);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < iEnumCount; ++i)
    {
        const char* name = va_arg(args, const char*);
        sEnumNames[i] = name;
    }
    va_end(args);
}

// Returns true when index is one of the actor value indices 18-20, 52, or 58-61, otherwise false.
// @fnv 0x0066eba0
// src: XBOX_PDB 0x0066eba0
bool ActorValue_IsResistance(ActorValue::Index aeActorValue)
{
    bool result = false;
    switch (aeActorValue)
    {
    case 18:
    case 19:
    case 20:
    case 52:
    case 58:
    case 59:
    case 60:
    case 61:
        result = true;
        break;
    }
    return result;
}

// @fnv 0x0066fd20
// src: XBOX_DEBUG_PDB 0x0066fd20
// pdb: ActorValue::GetSection | ActorValue.obj | debug, upstream name already matches, high
// pdb params: aiWhich
ActorValue::Section ActorValue::ActorValue_GetSection(Index aiWhich)
{
    if (ActorValue_IsAttribute(aiWhich))
        return ATTRIBUTE;
    if (IsDerivedAttribute(aiWhich))
        return DERIVED_ATTRIBUTE;
    if (IsSkill(aiWhich))
        return SKILL;
    if (IsAIAttribute(aiWhich))
        return AI_ATTRIBUTE;
    return INT_VALUE;
}

// @fnv 0x0066ec80
unsigned char ActorValue::ToArrayIndex(int section, Index index)
{
    switch (section)
    {
    case 0:
        return index - 5;
    case 1:
        return index - 12;
    case 2:
        return index - 32;
    case 3:
        return (unsigned char)index;
    case 4:
        return index - 25;
    case 5:
        return index - 46;
    default:
        return 0;
    }
}

// @fnv 0x0066fdf0
// pdb: ActorValueInfo::GetActorValueFormID | ActorValue.obj | retail, upstream name already matches, high
// pdb params: aiWhich
// pdb locals: iresult, esection
unsigned int ActorValueInfo::GetActorValueFormID(ActorValue::Index aiWhich)
{
    unsigned int auiFormId;
    int m_iSectionIndex = ActorValue::ActorValue_GetSection(aiWhich);
    auiFormId = m_iSectionIndex * 100 + 1000;
    auiFormId += (char)ActorValue::ToArrayIndex(m_iSectionIndex, aiWhich);
    return auiFormId;
}

// Initializes all 77 entries of the values array to zero.
// @fnv 0x0066ef90
// pdb: ActorValue::~ActorValue | ActorValue.obj | debug, object-file run extension, low
GlobalObject_0066ef90::GlobalObject_0066ef90()
{
    for (int i = 0; i < 77; ++i)
        values[i] = 0;
}

// Returns true when the actor value index falls in the derived-attribute range [12, 32).
// @fnv 0x0066fd90
bool ActorValue::IsDerivedAttribute(Index index)
{
    return index >= 12 && index < 32;
}

// Returns true when the actor value index is in the range 0 to 4, i.e. an AI attribute.
// @fnv 0x0066fdc0
bool ActorValue::IsAIAttribute(Index index)
{
    return index >= 0 && index < 5;
}

// Returns the pointer stored at index aiIndex in the g_011d61c8 array if aiIndex is in [0, 0x4d), otherwise returns null.
// @fnv 0x0066e920
// src: XBOX_PDB 0x0066e920
void* __cdecl ActorValue_GetActorValueInfo(int aiIndex)
{
    void* pinfo = 0;
    if (aiIndex >= 0 && aiIndex < 0x4d)
    {
        pinfo = ((void**)&g_011d61c8)[aiIndex];
    }
    return pinfo;
}

// Returns the full name of the ActorValueInfo for the given actor value index, or null if no info exists.
// @fnv 0x0066e9f0
// src: XBOX_PDB 0x0066e9f0
// pdb: ActorValue::GetActorValueIcon | ActorValue.obj | debug, upstream name already matches, high
// pdb params: aiIndex
// pdb locals: pinfo
const char* __cdecl ActorValue_GetActorValueIcon(ActorValue::Index aiIndex)
{
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        return reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(pinfo) +
            offsetof(ActorValueInfo, FullNameComponent) - offsetof(TESTexture, FullNameComponent))->GetFullName();
    return 0;
}

// @fnv 0x0066eac0
// src: XBOX_PDB 0x0066eac0
// pdb: ActorValue::GetActorValueScriptName | ActorValue.obj | debug, upstream name already matches, high
// pdb params: aiIndex
// pdb locals: pinfo, presult
const char* __cdecl ActorValue_GetActorValueScriptName(ActorValue::Index aiIndex)
{
    char* presult = 0;
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        presult = pinfo->m_pName;
    return presult;
}

// @fnv 0x0066eb00
// src: XBOX_PDB 0x0066eb00
// pdb: ActorValue::GetActorValueAbbreviation | ActorValue.obj | debug, upstream name already matches, high
// pdb params: aiIndex
// pdb locals: pinfo, presult
const char* __cdecl ActorValue_GetActorValueAbbreviation(ActorValue::Index aiIndex)
{
    const char* presult = 0;
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        presult = pinfo->m_cAbbreviation.operator const char*();
    return presult;
}

extern "C" void __cdecl ClearActorValueSlots();

// @fnv 0x0066efd0
// src: GUESS 0x0066efd0 (confidence: medium)
void __fastcall ActorValue_ClearActorValueSlots_Thunk(int)
{
    ClearActorValueSlots();
}

int _stricmp(const char* a, const char* b);
// Scans up to 0x4D entries in g_011d61c8, comparing each entry's name case-insensitively to str, and returns the matching index or 0x4D if none match.
// @fnv 0x0066eb40
int FindEntryIndexByName(const char* apName)
{
    int result = 0x4D;
    for (int i = 0; i < 0x4D && result == 0x4D; ++i)
    {
        if (!_stricmp(g_011d61c8.values[i]->m_pName, apName))
            result = i;
    }
    return result;
}

// Returns the icon texture path for the given weapon skill index, or null if the index has no mapped icon.
// @fnv 0x0066ea20
const char* __cdecl GetWeaponSkillIconPath(int aiSkillIndex)
{
    const char* path = 0;
    switch (aiSkillIndex)
    {
    case 33:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_big_guns.dds";
        break;
    case 34:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_energy.dds";
        break;
    case 35:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_explosives.dds";
        break;
    case 38:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_melee.dds";
        break;
    case 41:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_sm_arms.dds";
        break;
    case 45:
        path = "Interface\\Icons\\TypeIcons\\weap_skill_icon_unarmed.dds";
        break;
    }
    return path;
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// @fnv 0x006703b0
// pdb: ActorValueInfo::Save | ActorValue.obj | retail, upstream name already matches, high
void ActorValueInfo::Save()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESDescription::Save_00482cb0();
    TESTexture::Save(0x4e4f4349);
    if (m_cAbbreviation.Length())
        TESForm_AddChunkArray(0x4d414e41, (void*)m_cAbbreviation.operator const char*(), m_cAbbreviation.Length() + 1);
    TESForm::FinishFormRecord();
}

// Looks up the ActorValueInfo for aiIndex and returns its description via GetDesc, or null if the info is missing.
// @fnv 0x0066e9b0
// pdb: ActorValue::GetActorValueDesc | ActorValue.obj | debug, call graph, high
// pdb params: aiIndex
// pdb locals: pinfo
const char* GetActorValueDescription(ActorValue::Index aiIndex)
{
    ActorValueInfo* pinfo = ActorValue::GetActorValueInfo(aiIndex);
    if (pinfo)
        return reinterpret_cast<TESDescription*>(reinterpret_cast<char*>(pinfo) +
            offsetof(ActorValueInfo, m_uiDescriptionFileOffset) - offsetof(TESDescription, m_uiDescriptionFileOffset))
            ->GetDescription((TESForm*)0, (CHUNK_ID)0x43534544);
    return 0;
}

extern double DAT_01012060;
bool __cdecl ActorValue_IsFlagSet(int, unsigned int);

// @fnv 0x0066eea0
// src: XBOX_DEBUG_PDB 0x0066eea0
// pdb: ActorValue::CheckClampDamageModifier | ActorValue.obj | debug, call graph (shared callers), high
// pdb params: apActor, aiWhich, afDelta
// pdb locals: fresult, fold
float __cdecl ActorValue_CheckClampDamageModifier(ActorValueOwner* apActor, int aiWhich, float afDelta)
{
    float result = afDelta;

    if (afDelta < DAT_01012060)
    {
        if (ActorValue_IsFlagSet(aiWhich, 0x20))
        {
            float total = static_cast<float>((double)apActor->GetBaseActorValueFloat((ActorValue::Index)aiWhich) + (double)apActor->GetTemporaryActorValue((ActorValue::Index)aiWhich));
            if (total < -afDelta)
            {
                result = -total;
            }
        }
    }

    return result;
}

extern ActorValueInfo* DAT_011d61c8[0x4d];

// Deletes each non-null actor value, nulls the entries, and clears the initialization flag.
// @fnv 0x0066f110
// pdb: ActorValue::FreeActorValues | ActorValue.obj | debug, object-file gap fill, medium
// pdb locals: i
void ClearActorValueSlots()
{
    for (int i = 0; i < 0x4d; i++)
    {
        if (DAT_011d61c8[i] != 0)
        {
            delete DAT_011d61c8[i];
            DAT_011d61c8[i] = 0;
        }
    }
    DAT_011d6154 = 0;
}

// Clears data, copies fields and up to 15 array entries from a dynamic-cast ActorValueInfo source, pads the rest, then copies the base form.
// @fnv 0x00670430
// pdb: ActorValueInfo::Copy | ActorValue.obj | retail, upstream name already matches, high
// pdb params: apCopy
// pdb locals: pinfo, i
void ActorValueInfo::Copy(TESForm* apCopy)
{
    ClearData();
    ActorValueInfo* pSource = dynamic_cast<ActorValueInfo*>(apCopy);
    if (!pSource)
        return;
    m_pName = pSource->m_pName;
    m_cAbbreviation = pSource->m_cAbbreviation;
    uFlags = pSource->uFlags;
    m_pDerivedValueFunction = pSource->m_pDerivedValueFunction;
    pMappingFunction = pSource->pMappingFunction;
    pModifiedCallback = pSource->pModifiedCallback;
    iNumDependentActorValues = pSource->iNumDependentActorValues;
    int i;
    for (i = 0; i < iNumDependentActorValues && i < 15; i++)
        DependentActorValues[i] = pSource->DependentActorValues[i];
    for (; i < 15; i++)
        DependentActorValues[i] = (ActorValue::Index)0x4d;
    TESForm::CopyFrom(apCopy);
}

// The shared string has no declaration for this original non-virtual comparison entry.
class ActorValueStringCompare : public BSStringT<char>
{
public:
    bool FUN_00501c30(const BSStringT<char>*);
};

// Returns true when the cast fails, the base forms compare equal, or the abbreviations compare equal.
// @fnv 0x00670540
// pdb: ActorValueInfo::Compare | ActorValue.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pinfo
bool ActorValueInfo::Compare(TESForm* apCompare)
{
    ActorValueInfo* other = dynamic_cast<ActorValueInfo*>(apCompare);
    if (!other)
        return true;
    if (TESForm::Compare(other))
        return true;
    if (static_cast<ActorValueStringCompare&>(m_cAbbreviation).FUN_00501c30(&other->m_cAbbreviation))
        return true;
    return false;
}

// @fnv 0x00670080
// pdb: ActorValueInfo::~ActorValueInfo | ActorValue.obj | retail, upstream name already matches, high
ActorValueInfo::~ActorValueInfo()
{}
