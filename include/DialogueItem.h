#pragma once

#include "MagicTarget.h"

class BGSLoadFormBuffer;
class DialogueResponse;
class DialoguePolicy;
class TESTopicInfo;
class TESTopic;
class TESQuest;
class TESObjectREFR;

// pdb: class DialogueItem, size 0x1c, 6 members
class DialogueItem
{
public:
    BSSimpleList<DialogueResponse*> lResponses; // src: XBOX_RETAIL_PDB +0x0 (old: m_kResponseList)
    BSSimpleList<DialogueResponse*>* pCurrentResponse; // src: XBOX_RETAIL_PDB +0x8 (old: m_pCurrentResponseList)
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* pSpeaker; // src: XBOX_RETAIL_PDB +0x18 (old: m_pDialogueSpeaker)

    DialogueItem();
    DialogueItem(TESQuest* quest, TESTopic* topic, TESTopicInfo* info, TESObjectREFR* speaker);
    ~DialogueItem();
    static void operator delete(void*);
    void DialogueItem_LoadGame(BGSLoadFormBuffer*);
    void RefreshObjectRef(BGSLoadFormBuffer*);
    bool SelectDefaultResponseList();
    bool NextResponse();
    DialogueResponse* GetActiveResponse();
    DialogueResponse* GetCurrentItem();
    DialogueResponse* GetResponseByIndex(short index);
    short GetResponseIndex(DialogueResponse*);
    TESTopicInfo* GetInfo();
    TESQuest* GetQuest();
    TESTopic* GetAudioBackendData();
    TESTopic* Deallocate();
    DialoguePolicy* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    bool FUN_0083c7b0();
    bool NextResponse_0083c7e0();
    void FUN_0083c850(int);
};
