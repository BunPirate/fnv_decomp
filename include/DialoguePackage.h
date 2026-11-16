#pragma once

#include "TESPackage.h"

class BGSSaveFormBuffer;
class Conversation;
class DialogueActor;
class DialogueItem;
class DialogueResponse;

// pdb: class DialoguePackage, size 0xd0, bases: TESPackage, 23 members
class DialoguePackage : public TESPackage
{
public:
    struct Date
    {
        unsigned char b[0x24];
        ~Date();
    };

    struct Q
    {
        ~Q();
    };

    virtual ~DialoguePackage();
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void CopyFrom(const TESForm* form);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();
    virtual void InitLoadGameTES();
    virtual bool IsPackageDoneForActor(Actor* actor = 0);

    union
    {
        // The anonymous struct retains automatic destruction of the owner.
        struct
        {
            Date d;
        };
        struct
        {
            union
            {
                struct
                {
                    unsigned int unk80;
                    unsigned int unk84;
                    unsigned int unk88;
                };
                unsigned char pad80[0x0C];
            };
            union
            {
                unsigned int topic;
                TESForm* speaker;
            };
            unsigned int state;
            union
            {
                MobileObject* m_pkMobileObject;
                Actor* target;
            };
            unsigned char flags;
            unsigned char unk99;
            unsigned short unk9A;
            union
            {
                unsigned int unk9C;
                TESObjectREFR* m_pkReference;
            };
            unsigned int unkA0;
        };
    };
    union
    {
        Conversation* conversation;
        Conversation* m_pkConversation;
        Q* p;
    };
    DialogueItem* pCurrentItem; // src: XBOX_RETAIL_PDB +0xa8 (old: item)
    DialogueResponse* pCurrentResponse; // src: XBOX_RETAIL_PDB +0xac (old: response)
    union
    {
        TESForm* quest;
        MobileObject* pActor;
    };
    union
    {
        TESForm* info;
        MobileObject* pTargetActor;
        Actor* listener;
    };
    MobileObject* pTalkingActivator; // src: XBOX_RETAIL_PDB +0xb8 (old: m_pLinkedReference)
    unsigned char bActorHeadTrack; // src: XBOX_RETAIL_PDB +0xbc (old: unkBC)
    unsigned char bCreatedPack; // src: XBOX_RETAIL_PDB +0xbd (old: unkBD)
    unsigned char bContinueMoving; // src: XBOX_RETAIL_PDB +0xbe (old: unkBE)
    unsigned char bTargetContinueMoving; // src: XBOX_RETAIL_PDB +0xbf (old: unkBF)
    unsigned char bTargetMoveTowardStarter; // src: XBOX_RETAIL_PDB +0xc0 (old: unkC0)
    unsigned char bDoNotControlTargetMovement; // src: XBOX_RETAIL_PDB +0xc1 (old: unkC1)
    unsigned char bReachedAmbushLocation; // src: XBOX_RETAIL_PDB +0xc2 (old: unkC2)
    unsigned char unkC3;
    unsigned int iEmotion; // src: XBOX_RETAIL_PDB +0xc4 (old: unkC4)
    unsigned int iEmotionValue; // src: XBOX_RETAIL_PDB +0xc8 (old: unkC8)
    unsigned char bSoundFile; // src: XBOX_RETAIL_PDB +0xcc (old: unkCC)

    void SavePackage();
    void TESForm_SaveGameDataOLD(void*, int);
    void ForwardToSaveLoadGame(void*, int);
    void Stop();
    DialogueActor* First();
    DialogueActor* Second();
    DialogueActor* Target();
    void CopyFromPackage(TESForm*);
    void Copy_009ee060(TESForm* apCopy);
    unsigned short GetSaveSize_009ef560();
    void SaveGame_009ef6e0();
    void InitLoadGame_009f0740(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadGame_009f0460(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadSaveData();
    void ResolveReferences();
    void* Destroy(unsigned int flags);
    void FUN_0083dec0();
    bool IsPointerMatch(const void* apValue);
    unsigned char GetByteAtBC();
    Actor* FUN_008d80e0(); // 0x008d80e0
    Actor* DialoguePackage_GetActorStartedConversation(); // 0x009ee040
    bool FUN_008e95e0(); // 0x008e95e0
    bool FUN_008e95a0(); // 0x008e95a0
    void FUN_008e9600(int); // 0x008e9600
    bool __thiscall DialoguePackage_GetTargetContinueMoving();
    bool FUN_0087eed0();                     // 0x0087eed0 (HighProcess::Update 0x008eeec0)
    void DialoguePackage_Speak(bool process);
};
