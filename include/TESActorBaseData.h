#pragma once

#include "BaseFormComponent.h"
#include "ActorBaseAttributes.h"
#include "MagicTarget.h"

class Actor;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class BGSVoiceType;
class FactionReaction;
class TESActorBase;
class TESFaction;
class TESForm;
class TESLevItem;
class TESObjectREFR;

namespace TESDataHandlerTypes
{
    class TESFaction;
}

// pdb: class TESActorBaseData, size 0x34, bases: BaseFormComponent, 6 members
class TESActorBaseData : public BaseFormComponent
{
public:
    enum TEMPLATE_USE_FLAG  // values: Xbox PDB TESActorBaseData::TEMPLATE_USE_FLAG
    {
        TU_TRAITS = 0,
        TU_STATS = 1,
        TU_FACTIONS = 2,
        TU_SPELLS = 3,
        TU_AIDATA = 4,
        TU_AIPACKAGES = 5,
        TU_MODEL = 6,
        TU_BASEDATA = 7,
        TU_INVENTORY = 8,
        TU_SCRIPT = 9,
        TU_COUNT = 10,
        TU_COPIED = 15
    };

    TESActorBaseData();
    ~TESActorBaseData();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);
    virtual void CopyFromTemplateForm(TESActorBase* form);
    virtual bool GetNoVATSmelee() const;
    virtual bool GetNoVATSranged() const;
    virtual bool GetAllowPickpocket() const;
    virtual bool GetIsGhost() const;
    virtual bool GetIsInvulnerable() const;
    virtual bool GetNoKnockdowns() const;
    virtual bool GetCanBeAllRaces() const;
    virtual bool GetNoHeadTracking() const;
    virtual bool GetNoPersuasion() const;
    virtual bool GetNoLeftArm() const;
    virtual bool GetNoRightArm() const;
    virtual bool GetNoHead() const;
    virtual bool GetNoShadow() const;
    virtual bool GetNoBloodSpray() const;
    virtual void SetNoBloodSpray(bool value);
    virtual bool GetNoBloodDecal() const;
    virtual void SetNoBloodDecal(bool value);
    virtual unsigned int GetBloodImpactMaterial() const;
    virtual void SetBloodImpactMaterial(unsigned int material);
    virtual unsigned short GetFatigue() const;
    virtual float GetHealthRegeneration() const;
    virtual BGSVoiceType* GetVoiceType() const;

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void InitItem(TESForm* apOwner);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool value);
    void SetTemplateUseFlag(TEMPLATE_USE_FLAG flag, bool value);
    void SetTemplateUseFlag(int flag, bool value);
    bool GetTemplateUseFlag(TEMPLATE_USE_FLAG flag);
    bool GetTemplateUseFlag(int flag);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm* form);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short flags);
    bool __thiscall GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void CalcTemplateForRef(TESObjectREFR* apRef);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short&);
    int* GetFlags();
    void SetFlags(int flags);
    bool GetFlag(unsigned int flag) const;
    bool GetFlagBit(int flag);
    void UpdateFlagBit(int aiFlag, bool abVal, bool abAddChange);
    void UpdateFlagBit(int abVal, bool abAddChange);
    void UpdateFlagBit(bool abVal, bool abAddChange);
    bool IsEssentialActor();
    void SetEssential(bool abVal);
    bool GetRespawn();
    void SetRespawn(bool value);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool abVal, bool abAddChange);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool value);
    bool GetNotPushable();
    void SetNotPushable(bool value);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool value);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool abVal);
    bool GetSummonable();
    void SetSummonable(bool value);
    bool GetNoRumors();
    void SetNoRumors(bool value);
    void SetNoVATSMelee(bool value);
    void SetAllowPCDialogue(bool value);
    void SetAllowPickPocket(bool value);
    void SetIsGhost(bool value);
    void SetInvulnerable(bool value);
    void SetCantOpenDoors(bool value);
    void SetCanBeAllRaces(bool value);
    void SetAutoCalcServiceFlags(bool value);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short asValue);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short asVal);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short asVal);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short asVal);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem* item);
    void SetFatigue(unsigned short ausFatigue);
    static int ConvertToInteger(float value);
    static char* GetActorDisplayName(Actor* apActor);
    void SetKarmaValue(float value);
    void ModKarma(float value);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short ausNewgold);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionReaction(TESActorBase*, int&);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void SetFactionRank(TESDataHandlerTypes::TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    unsigned short GetShortAtOffset12();
    void SetSpeedMult(unsigned short value);
    void SetVoiceType(BGSVoiceType* voiceType);
    void AddFormChange(int flags);
    void RemoveFormChange(int aiChangeFlags);
    void AddFormChangeFlags(int flags);
    void ClearChangeFlags(int flags);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int flags);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void SaveGame(unsigned int aiFlags);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int flags);
    bool HasFaction(TESFaction* faction);
    void ClearFactionList();
    void CopyFactionList(TESActorBaseData* source);
    TESActorBaseData& operator=(const TESActorBaseData& other);

    bool FUN_00461580(unsigned int flag);
    unsigned short GetCalcLevelMin_0047d390();
    unsigned short GetAnimGroupType_0047d3b0();
    unsigned short TESActorBaseData_GetLevel();
    void LoadGame_0047ea70(BGSLoadFormBuffer* apLoadGameBuffer);
    void FUN_0050f9a0(TESLevItem* item);
    void TESCreature_SetNoBloodSpray(bool abVal);

    bool GetVATSmeleeDisabled();
    bool GetNoVATSranged();
    bool GetCanBePickpocketed();
    bool GetIsGhost();
    bool GetIsInvulnerable();
    bool GetNoKnockdowns();
    bool GetCanBeAllRaces();
    bool GetNoHeadTracking();
    bool GetNoPersuasion();
    bool GetNoLeftArm();
    bool GetNoRightArm();
    bool GetNoHead();
    bool GetNoShadow();
    bool GetNoBloodSpray();
    bool GetNoBloodDecal();
    int GetBloodImpactMaterial();
    void SetBloodImpactMaterial(int material);
    unsigned short GetFatigue();
    float GetHealthRegeneration();
    BGSVoiceType* GetVoiceType();

    ActorBaseAttributes actorData;
    TESLevItem* pDeathItem;
    BGSVoiceType* pVoiceType;
    TESForm* pTemplateForm;
    int iChangeFlags;
    BSSimpleList<FactionReaction*> listFactions;
};
