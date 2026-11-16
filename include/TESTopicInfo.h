#pragma once

#include "TESForm.h"
#include "PerkEntryConditionSet.h"
#include "TopicInfoData.h"
#include "TESFile.h"

class ActorValueInfo;
class BGSPerk;
class Character;
class MagicItem;
class MobileObject;
class Script;
class TESActorBase;
class TESObjectREFR;
class TESQuest;
class TESResponseList;
class TESTopic;
class TESTopicInfoData;
class XActor;

enum DIALOGUE_TYPE;
enum SPEECH_CHALLENGE_LEVEL;

// pdb: class TESTopicInfo, size 0x50, bases: TESForm, 12 members
class TESTopicInfo : public TESForm
{
public:
    PerkEntryConditionSet objConditions; // src: XBOX_RETAIL_PDB +0x18 (old: m_kInfoConditions)
    unsigned short iInfoIndex; // src: XBOX_RETAIL_PDB +0x20 (old: m_uiInfoIndex)
    bool bSaidOnce; // src: XBOX_RETAIL_PDB +0x22 (old: m_bGoodbye)
    TopicInfoData m_Data;
    unsigned char layoutPadding27;
    BSStringT<char> cPrompt; // src: XBOX_RETAIL_PDB +0x28 (old: m_kPrompt)
    BSSimpleList<TESTopic*> m_listAddTopics; // src: XBOX_RETAIL_PDB +0x30 (old: m_kAddTopicList)
    TESTopicInfoData* m_pConversationData; // src: XBOX_RETAIL_PDB +0x38 (old: m_pResponseData)
    TESActorBase* pSpeaker; // src: XBOX_RETAIL_PDB +0x3c (old: m_pDialogueSpeaker)
    TESForm* pPerkSkillStat; // src: XBOX_RETAIL_PDB +0x40 (old: m_pPerkSkillStat)
    SPEECH_CHALLENGE_LEVEL eDifficulty; // src: XBOX_RETAIL_PDB +0x44 (old: m_eDifficultyLevel)
    TESQuest* pOwnerQuest; // src: XBOX_RETAIL_PDB +0x48 (old: m_pOwnerQuest)
    unsigned long iFileOffset; // src: XBOX_RETAIL_PDB +0x4c (old: m_ulTopicFlags)

    TESTopicInfo(DIALOGUE_TYPE aeType);
    TESTopicInfo(int aeType);
    virtual ~TESTopicInfo();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();
    virtual void SetAltered(bool abVal);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);

    void __vslot_10();
    void Save();
    bool Load(TESFile* apFile);
    void Copy(TESForm* apCopy);
    void ResetFormData();
    bool CopyTopicData(FormRecordHeader* header);
    bool CopyTopicData(TESForm* form);
    bool LoadTopicInfoData(FormRecordHeader* header, bool arg1, bool arg2);
    void CreateGroupData(FormRecordHeader* header, TESFileGroup* group);
    void SerializeTopicInfoData(void* data);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void LoadGameLegacy(unsigned int arg0, unsigned int arg1);
    virtual void RevertLegacy(unsigned int flags);

    void SetOwnerTopic(TESTopic* owner);
    int GetTopicType();
    int GetNextSpeaker();
    void SetNextSpeaker(int speaker);
    unsigned short GetInfoIndex();
    bool IsRunForRumors();
    void SetInfoIndex(unsigned short index);
    PerkEntryConditionSet* GetInfoConditions();
    void SetConditionList(PerkEntryConditionSet* conditions);
    BSSimpleList<TESTopic*>* GetAddTopicList();
    bool InAddTopicList(TESTopic* topic);
    void FormatDebugInfo(void* text, bool firstOnly);
    void GetInfoDisplayText(BSStringT<char>& aString, bool abFirstOnly);
    TESQuest* GetParentQuest();
    void SetOwnerQuest(TESQuest* quest);
    bool IsGoodbye();
    void SetGoodbye(bool goodbye);
    bool IsRandom();
    void SetRandom(bool random);
    bool IsRandomEnd();
    void SetRandomEnd(bool randomEnd);
    bool IsSayOnce();
    void SetSayOnce(bool sayOnce);
    bool IsInfoRefusal();
    void SetInfoRefusal(bool refusal);
    bool IsRunImmediately();
    void SetRunImmediately(bool immediately);
    bool IsRunRumorResults();
    void SetRunRumorResults(bool runResults);
    bool IsSpeechChallenge();
    void SetSpeechChallenge(bool challenge);
    bool IsSayOnceADay();
    void SetSayOnceADay(bool onceADay);
    bool IsAlwaysDarkened();
    void SetAlwaysDarkened(bool darkened);
    int GetDummyNodeState();
    void SetDummyNodeState(int state);
    TESTopicInfoData* GetConversationData();
    void SetConversationData(TESTopicInfoData* apConversationData);
    const BSStringT<char>& GetPrompt();
    void SetPrompt(char* prompt);
    void SetPrompt(const char* prompt);
    bool HasPrompt();
    void SetActorValue(ActorValueInfo* value);
    void SetPerk(BGSPerk* perk);
    ActorValueInfo* GetActorValue();
    BGSPerk* GetPerk();
    TESForm* GetPerkSkillStat();
    int GetDifficultyLevel();
    void SetDifficultyLevel(int difficulty);
    void SetDifficultyLevel(SPEECH_CHALLENGE_LEVEL difficulty);
    int GetNextSpeakerType();
    TESActorBase* GetSpeaker();
    void SetSpeaker(TESActorBase* speaker);
    void SetSpeaker(MagicItem* speaker);
    void CloneResponseList(TESResponseList* list);
    Script* GetResultScript(int aeScript);
    Script* GetResultScript(unsigned int aeScript);
    bool HasResultScript();
    unsigned int GetTempDataOffset();
    void SetTempDataOffset(unsigned int offset);
    bool IsInfoValidForDialogue(bool* deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    bool IsInfoValidForDialogue(bool& deferred, TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    bool IsInfoValidForDialogue(TESQuest* quest, TESObjectREFR* speaker, TESObjectREFR* listener);
    void HyperLinkCompile(char* text);
    void RemoveHyperLinks();
    void AppendTopicInfo(int arg, TESObjectREFR* reference);
    void AddTopicList();
    bool SaidOnce();
    void SetSaidOnce();
    void ResetSaidOnceFlags();
    bool IsValidSaveID(bool arg);
    TESResponseList* GetResponseList(TESResponseList* apList);
    void ClearResponseList();
    void ClearAddTopicList();
    TopicInfoData* GetData();
    void RunResultScript(bool aeScript, MobileObject* apRef);
    void RunResultScript(int aeScript, Character* apRef);
    void RunResultScript(int onEnd, XActor* speaker);
    bool IsNew();
    bool IsRefusal();
    void MarkAsRefusal();
    bool IsChallengeFlagSet();
    bool IsFlagSet();

    static void AddTopicInfoToSortedList(TESTopicInfo* info, void* list);
    static bool CompareTopicInfos(TESTopicInfo* left, TESTopicInfo* right);
};
