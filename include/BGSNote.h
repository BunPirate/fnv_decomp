#pragma once

#include "TESBoundObject.h"
#include "NOTE_TYPE.h"
#include "TESModel.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "BGSPickupPutdownSounds.h"
#include "MagicTarget.h"
#include "BSSimpleList.h"

class TESActorBase;
class TESDescription;
class TESFile;
class TESQuest;
class TESSound;
class TESTopic;


class BGSNote : public TESBoundObject,
                public TESModel,
                public TESFullName,
                public TESIcon,
                public BGSPickupPutdownSounds
{
public:
    void* m_pText;
    void* pSpeaker;
    BSSimpleList<TESQuest*> OwnerQuests;
    signed char cType;
    bool bHasBeenRead;
    char padding7e[2];

    BGSNote();
    virtual ~BGSNote();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* apCompare);

    void* Release(unsigned int flags);
    void ClearNoteData();
    void SaveNote();
    void SetNoteImage(TESTexture* apTex);
    void SetNoteText(TESDescription* apDesc);
    BSSimpleList<TESQuest*>* GetOwnerQuests();

    void SetNoteType(NOTE_TYPE aeVal);
    bool Load(TESFile* apFile);
    TESTexture* GetNoteImage();
    TESSound* GetNoteSound();
    void SetNoteSound(TESSound* apSound);
    TESTopic* GetNoteTopic();
    void SetNoteTopic(TESTopic* topic);
    TESActorBase* GetNoteSpeaker();
    void SetNoteSpeaker(TESActorBase* speaker);
    void ResetFormData();
    int GetNoteType();
    TESDescription* GetNoteText();
    bool GetUnk7d();
    void SetSoundNotePlayed(bool played);
};
