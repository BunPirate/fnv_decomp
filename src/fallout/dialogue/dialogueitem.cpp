// fallout/dialogue/dialogueitem.cpp: DialogueItem and serialization helpers (14 functions)

#include <windows.h>
#include "layout_support.h"
#include "../../../include/DialogueItem.h"

#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESQuest.h"
#include "../../../include/TESResponseList.h"
#include "../../../include/TESTopic.h"
#include "../../../include/TESTopicInfo.h"
#include "../../../include/TESResponse.h"
#include "../../../include/TESSaveLoadGame.h"

// @fnv 0x0083c820
// pdb: DialogueItem::GetCurrentResponse | DialogueItem.obj | debug, call graph, high
DialogueResponse* DialogueItem::GetActiveResponse()
{
    if (pCurrentResponse)
        return pCurrentResponse->GetItem();
    else
        return NULL;
}

// @fnv 0x005e3fa0
// The shared declaration names a different bool-returning function.
TESObjectREFR* __fastcall GetDialogueItemReferenceAt6C(DialogueItem* item)
{
    return *(TESObjectREFR**)((char*)item + 0x6c);
}

void* __fastcall _ref_00726070(void* pThis);

// @fnv 0x0083c7e0
// src: XBOX_PDB 0x0083c7e0
// pdb: DialogueItem::NextResponse | DialogueItem.obj | debug, call graph, high
bool DialogueItem::NextResponse_0083c7e0()
{
    if (pCurrentResponse)
    {
        pCurrentResponse = static_cast<BSSimpleList<DialogueResponse*>*>(_ref_00726070(pCurrentResponse));
    }
    return pCurrentResponse != 0;
}

void __cdecl Deallocate(void*);
// Helpers cover members absent from the shared header. Fastcall keeps the item
// in ECX; value-type arguments retain the original member arguments on the stack.
struct DialogueDeleteFlags
{
    unsigned int flags;
};
// @fnv 0x005c90d0
// pdb: DialogueItem::`scalar deleting destructor' | TESScriptFunctions.obj | debug, call graph, high
void* __fastcall DeleteDialogueItem(DialogueItem* item, DialogueDeleteFlags argument)
{
    item->~DialogueItem();
    if (argument.flags & 1)
        Deallocate(item);
    return item;
}

namespace fnv_0083c670 {
// pdb: class DialogueResponse, size 0x2c, 9 members
struct DialogueResponse
{
    ~DialogueResponse();
};
struct ListX
{
    ~ListX();
    bool _ref_008256d0();
    DialogueResponse** _ref_006815c0();
    void _ref_0063f7b0();
};
}  // namespace fnv_0083c670

// Destructor that repeatedly deletes the list's current DialogueResponse and advances until the list reports empty.
// @fnv 0x0083c670
// pdb: DialogueItem::~DialogueItem | DialogueItem.obj | retail, upstream name already matches, high
// pdb locals: pList
DialogueItem::~DialogueItem()
{
    fnv_0083c670::ListX* pList = reinterpret_cast<fnv_0083c670::ListX*>(&lResponses);
    while (pList && !pList->_ref_008256d0())
    {
        delete *pList->_ref_006815c0();
        pList->_ref_0063f7b0();
    }
}

struct FUN_0083c9e0_resp
{
    unsigned short ProcessAndReturnValue_0083d420();
};
// @fnv 0x0083c9e0
// pdb: DialogueItem::GetSaveSize | DialogueItem.obj | debug, object-file run extension, low
// pdb locals: plist, isize, presponse
unsigned short __fastcall GetDialogueItemSaveSize(DialogueItem* item)
{
    unsigned short usSize = 0;
    usSize += 1;
    BSSimpleList<DialogueResponse*>* pIter = &item->lResponses;
    while (pIter && !pIter->IsEmpty())
    {
        FUN_0083c9e0_resp* pResponse = reinterpret_cast<FUN_0083c9e0_resp*>(pIter->GetItem());
        usSize += pResponse->ProcessAndReturnValue_0083d420();
        pIter = pIter->GetNext();
    }
    usSize += 1;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}

void _FNV_Warning(const char* message);

// Returns the index of response in the dialogue responses list, warning and returning 0 if it is not found.
// @fnv 0x0083c900
// pdb: DialogueItem::InitLoadGame | DialogueItem.obj | retail, object-file run extension, low
// pdb note: debug build links it to DialogueItem::GetDialogueResponseIndex
// pdb locals: ispeakerID
short DialogueItem::GetResponseIndex(DialogueResponse* response)
{
    short iElementIndex = 0;
    BSSimpleList<DialogueResponse*>* pCurrentElementNext = &lResponses;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        if (response == pCurrentElementNext->GetItem())
            return iElementIndex;
        ++iElementIndex;
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    _FNV_Warning(
        "DIALOGUE: When trying to get a dialogue response index, the dialogue item was not found in the dialogue responses list.");
    return 0;
}

void FNV_Warning(const char* message);

// Walks the dialogue response list and returns the response at the given index, warning and returning null if the index is out of range.
// @fnv 0x0083c970
// pdb: DialogueItem::GetSaveSize | DialogueItem.obj | retail, object-file run extension, low
// pdb note: debug build links it to DialogueItem::GetDialogueResponseByIndex
// pdb locals: plist, isize, presponse
DialogueResponse* DialogueItem::GetResponseByIndex(short index)
{
    short current = 0;
    BSSimpleList<DialogueResponse*>* node = &lResponses;
    while (node && !node->IsEmpty())
    {
        if (current == index)
            return node->GetItem();
        ++current;
        node = node->GetNext();
    }
    FNV_Warning(
        "DIALOGUE: When trying to get a dialogue response by its index, the index was larger than the size of the dialogue responses list.");
    return 0;
}

bool __fastcall _ref_008256d0(void*);
DialogueResponse*& __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
struct DialogueResponseArgument
{
    DialogueResponse* response;
};
// @fnv 0x0083c8a0
// pdb: DialogueItem::InitLoadGame | DialogueItem.obj | retail, object-file run extension, low
// pdb note: debug build links it to DialogueItem::SetCurrentResponse
// pdb locals: ispeakerID
void __fastcall SetActiveDialogueResponse(DialogueItem* item, DialogueResponseArgument argument)
{
    void* pCurrentElementNext = (void*)item;
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        if (argument.response == _ref_006815c0(pCurrentElementNext))
        {
            item->pCurrentResponse = static_cast<BSSimpleList<DialogueResponse*>*>(pCurrentElementNext);
            break;
        }
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
struct DialogueResponseSave
{
    void SaveToGame();
};
// @fnv 0x0083ca90
// pdb: DialogueItem::SaveGame | DialogueItem.obj | debug, object-file run extension, low
// pdb locals: plist, pcount, ispeakerID, ccurrentResponse, iinfoID, itopicID, ccount, iquestID, presponse
void __fastcall SaveDialogueItemToSave(DialogueItem* item)
{
    char cCount4 = 0;
    char* pCountPos8 = g_TESSaveLoadGame->GetCurrentPosition();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&cCount4, 1);
    BSSimpleList<DialogueResponse*>* plist2 = &item->lResponses;
    while (plist2 && !plist2->IsEmpty())
    {
        DialogueResponse* presponse3 = plist2->GetItem();
        ((DialogueResponseSave*)presponse3)->SaveToGame();
        cCount4++;
        plist2 = plist2->GetNext();
    }
    *pCountPos8 = cCount4;

    char cCurrentVal = -1;
    if (item->pCurrentResponse)
        cCurrentVal = item->GetResponseIndex(item->pCurrentResponse->GetItem());
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&cCurrentVal, 1);

    unsigned int aIInfoID = 0;
    if (item->pInfo)
        aIInfoID = item->pInfo->GetFormID();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(static_cast<void*>(&aIInfoID), 4);

    unsigned int m_uiTopicFormID = 0;
    if (item->pTopic)
        m_uiTopicFormID = item->pTopic->GetFormID();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(static_cast<void*>(&m_uiTopicFormID), 4);

    unsigned int iQuestID_2 = 0;
    if (item->pQuest)
        iQuestID_2 = item->pQuest->GetFormID();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(static_cast<void*>(&iQuestID_2), 4);

    unsigned int iSpeakerID = 0;
    if (item->pSpeaker)
        iSpeakerID = item->pSpeaker->GetFormID();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID(static_cast<void*>(&iSpeakerID), 4);
}

TESForm* GetFormByID(unsigned int);
// @fnv 0x0083cdf0
// pdb: DialogueItem::InitLoadGame | DialogueItem.obj | debug, object-file gap fill, medium
// pdb locals: ispeakerID
void __fastcall ResolveDialogueItemSpeaker(DialogueItem* item)
{
    unsigned int loc = reinterpret_cast<unsigned int>(item->pSpeaker);
    if (loc)
    {
        item->pSpeaker = dynamic_cast<TESObjectREFR*>(GetFormByID(loc));
    }
}

struct DialogueResponseBufferWriter
{
    void DialogueResponse_SaveGame(BGSSaveGameBuffer*);
};
struct DialogueSaveBufferArgument
{
    BGSSaveGameBuffer* buffer;
};

// Writes the response list, current response index, and associated form data (pInfo, pTopic, pQuest, m_pDialogueSpeaker) to apSaveGameBuffer.
// @fnv 0x0083ce40
// src: XBOX_DEBUG_PDB 0x0083ce40
// pdb: DialogueItem::SaveGame | DialogueItem.obj | debug, call graph, high
// pdb params: apSaveGameBuffer
// pdb locals: scurrentResponse, plist, isaveGameBufferPos, isaveGameCount, presponse
void __fastcall DialogueItem_SaveGame(DialogueItem* item, DialogueSaveBufferArgument argument)
{
    short scurrentResponse;
    ::BSSimpleList< ::DialogueResponse*>* pCurrentElementNext;
    unsigned int isaveGameBufferPos;
    unsigned int isaveGameCount;

    isaveGameCount = 0;
    isaveGameBufferPos = argument.buffer->StartVariableSizedValue();
    pCurrentElementNext = &item->lResponses;
    while (pCurrentElementNext)
    {
        ::DialogueResponse* presponse = pCurrentElementNext->GetItem();
        if (presponse)
        {
            reinterpret_cast<DialogueResponseBufferWriter*>(presponse)->DialogueResponse_SaveGame(argument.buffer);
            isaveGameCount++;
        }
        pCurrentElementNext = pCurrentElementNext->GetNext();
    }
    argument.buffer->SaveVariableSizedValue_00865ff0(isaveGameCount, isaveGameBufferPos);
    scurrentResponse = item->pCurrentResponse ? item->GetResponseIndex(item->pCurrentResponse->GetItem()) : -1;
    argument.buffer->SaveData(static_cast<void*>(&scurrentResponse), 2, 0);
    argument.buffer->SerializeFormData(static_cast<void*>(item->pInfo), 0);
    argument.buffer->SerializeFormData(static_cast<void*>(item->pTopic), 0);
    argument.buffer->SerializeFormData(static_cast<void*>(item->pQuest), 0);
    argument.buffer->SerializeFormData(static_cast<void*>(item->pSpeaker), 0);
}


namespace fnv_0083c520 {
struct DialogueResponse
{
    DialogueResponse(TESQuest*, TESTopic*, TESTopicInfo*, TESObjectREFR*, TESResponse*);
    char* pResponseText;
    unsigned short usResponseLen;
    unsigned short usResponseMax;
    unsigned int eEmotion;
    int ActorProjectileState;
    char* pVoiceFile;
    unsigned short usVoiceLen;
    unsigned short usVoiceMax;
    void* m_pFirstIdleForm;
    void* m_pSecondIdleForm;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
};
}  // namespace fnv_0083c520

// Constructs a dialogue response list by iterating over TESResponse entries from apInfo and appending a DialogueResponse for each.
// @fnv 0x0083c520
// pdb: DialogueItem::DialogueItem | DialogueItem.obj | retail, upstream name already matches, high
DialogueItem::DialogueItem(TESQuest* apQuest, TESTopic* apTopic, TESTopicInfo* apInfo, TESObjectREFR* apSpeaker)
{
    pCurrentResponse = 0;
    pInfo = 0;
    if (apTopic && apInfo && apQuest)
    {
        pInfo = apInfo;
        pTopic = apTopic;
        pQuest = apQuest;
        pSpeaker = apSpeaker;
        TESResponseList responseList;
        apInfo->CloneResponseList(&responseList);
        TESResponse* presponse = (TESResponse*)(unsigned int)responseList;
        while (presponse)
        {
            DialogueResponse* pResponse = reinterpret_cast<DialogueResponse*>(new fnv_0083c520::DialogueResponse(apQuest, apTopic, apInfo, apSpeaker, presponse));
            lResponses.AddTail(pResponse);
            presponse = (TESResponse*)presponse->GetNext();
        }
    }
}

class TESIdleForm;
class DialogueResponse
{
  public:
    DialogueResponse();
    void DialogueResponse_LoadGame();
    BSStringT<char> cText; // src: XBOX_RETAIL_PDB +0x0 (old: m_kResponseText)
    unsigned int eEmotion;
    unsigned int uiEmotion; // src: XBOX_RETAIL_PDB +0xc (old: m_uiEmotionValue)
    BSStringT<char> cVoice; // src: XBOX_RETAIL_PDB +0x10 (old: m_kResponseNotes)
    TESIdleForm* pSpeakerIdle; // src: XBOX_RETAIL_PDB +0x18 (old: m_pFirstIdleForm)
    TESIdleForm* pListenIdle; // src: XBOX_RETAIL_PDB +0x1c (old: m_pSecondIdleForm)
    TESTopic* pVoiceSound; // src: XBOX_RETAIL_PDB +0x20 (old: pTopic)
    TESTopicInfo* bUseEmotion; // src: XBOX_RETAIL_PDB +0x24 (old: pInfo)
    TESQuest* nResponseID; // src: XBOX_RETAIL_PDB +0x28 (old: pQuest)
};
// Reads response count, current index, topic info, topic, quest, and speaker IDs from the save stream into the dialogue item.
// @fnv 0x0083cc10
// src: XBOX_DEBUG_PDB 0x0083cc10
// pdb: DialogueItem::LoadGame | DialogueItem.obj | debug, call graph, high
// pdb locals: ispeakerID, ccurrentResponse, iinfoID, itopicID, ccount, iquestID, i, presponse
void __fastcall DialogueItem_LoadGame(DialogueItem* item)
{
    unsigned char cCount4;
    unsigned int iloopB;
    ::DialogueResponse* presponse3;
    char cCurrentVal;
    unsigned int aIInfoID;
    unsigned int m_uiTopicFormID;
    unsigned int iQuestID_2;
    unsigned int iSpeakerID;

    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&cCount4, 1);
    for (iloopB = 0; iloopB < cCount4; iloopB++)
    {
        presponse3 = reinterpret_cast< ::DialogueResponse*>(new DialogueResponse);
        reinterpret_cast<DialogueResponse*>(presponse3)->DialogueResponse_LoadGame();
        item->lResponses.AddTail(presponse3);
    }

    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&cCurrentVal, 1);
    // The equivalent thiscall signature avoids a temporary value-type argument.
    if (cCurrentVal != -1)
        reinterpret_cast<void (__thiscall*)(DialogueItem*, DialogueResponse*)>(SetActiveDialogueResponse)(
            item, item->GetResponseByIndex(cCurrentVal));
    else
        item->pCurrentResponse = 0;

    g_TESSaveLoadGame->FUN_00857aa0(&aIInfoID, 4);
    if (aIInfoID)
        item->pInfo = dynamic_cast<TESTopicInfo*>(::GetFormByID(aIInfoID));
    g_TESSaveLoadGame->FUN_00857aa0(&m_uiTopicFormID, 4);
    if (m_uiTopicFormID)
        item->pTopic = dynamic_cast<TESTopic*>(::GetFormByID(m_uiTopicFormID));
    g_TESSaveLoadGame->FUN_00857aa0(&iQuestID_2, 4);
    if (iQuestID_2)
        item->pQuest = dynamic_cast<TESQuest*>(::GetFormByID(iQuestID_2));
    g_TESSaveLoadGame->FUN_00857aa0(&iSpeakerID, 4);
    item->pSpeaker = (::TESObjectREFR*)iSpeakerID;
}
