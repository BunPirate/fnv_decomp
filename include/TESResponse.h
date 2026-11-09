#pragma once

#include "TESFullName.h"

class BGSVoiceType;
class TESFile;
class TESForm;
class TESIdleForm;
class TESQuest;
class TESSound;
class TESTopic;
class TESTopicInfo;
enum DIALOGUE_EMOTION;

// The TRDT record of a response (0x18 bytes): emotion type and value, topic, flags, sound, use-emotion-animation.
class DialogueResponseData
{
  public:
    DialogueResponseData();                // 0x00616d70
    void Endian();

    DIALOGUE_EMOTION eEmotion;             // +0x00
    unsigned int ActorProjectileState;     // +0x04 emotion value
    TESTopic* m_pTopic;                    // +0x08
    unsigned char m_ucResponseFlags;       // +0x0C response number
    unsigned char layoutPaddingD[3];
    TESSound* m_pResponseSound;            // +0x10
    bool m_bTenthFlag;                     // +0x14
    unsigned char layoutPadding15[3];
};

// Bethesda TESResponse: one line of a TESTopicInfo's response list (TESResponseList, singly linked by pNext),
// 0x2C bytes. Constructor 0x00616ce0: DialogueResponseData() at +0, BSStringT at +0x18, zeroes +0x20/+0x24/+0x28;
// destructor 0x00616dc0, scalar deleting destructor 0x0061cb30. No vtable.
// pdb: class TESResponse, size 0x2c, 5 members
class TESResponse
{
  public:
    DialogueResponseData Data;        // +0x00
    BSStringT<char> cResponseText;  // +0x18
    TESIdleForm* pSpeakerIdle;    // +0x20 speaker idle
    TESIdleForm* pListenerIdle;   // +0x24 listener idle
    TESResponse* pNext;               // +0x28

    TESResponse();                                                 // 0x00616ce0
    ~TESResponse();                                                // 0x00616dc0

    void Copy(TESResponse* response);
    DialogueResponseData* GetData();
    TESIdleForm* GetSpeakerIdle();
    TESIdleForm* GetListenerIdle();
    void SetListenerIdle(TESIdleForm* idle);
    void AppendResponse(TESResponse* response);
    TESResponse* GetNext();                                        // 0x0045cd60 (folded +0x28 getter)
    void SetSpeakerIdle(TESIdleForm* idle);                        // 0x0050f9c0
    DIALOGUE_EMOTION GetEmotion();                                 // 0x00559450 (folded +0 getter)
    const char* GetDialogueText();                                 // 0x00616de0
    static void GetAudioQuestTopicCombined(TESQuest* apQuest, TESTopic* apTopic, char* apOutBuffer, unsigned int aiBufferSize); // 0x006172c0
    void GetAudioFilename(TESQuest* apOwnerQuest, TESTopic* apOwnerTopic, TESTopicInfo* apOwnerInfo, BSStringT<char>& aFilename); // 0x00617400
    unsigned int GetResponseID();                                  // 0x006174b0
    void Load(TESFile* apFile);                                      // 0x00617530
    void InitItem(TESForm* apOwner);                                 // 0x00617580
    void SetNext(TESResponse* next);                               // 0x0061cc40
    void SetResponseText(const char* text);                        // 0x0061eb40
    void SetEmotionValue(unsigned int value);                      // 0x006ecd40
    void GetListenerIdle(TESIdleForm* idle);                       // 0x007037c0
    int AngleSinCosArc_GetLength();                                               // 0x0083e0a0
};
