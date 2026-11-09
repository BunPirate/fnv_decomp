#pragma once

#include "TESForm.h"
#include "TESSoundFile.h"
#include "MagicTarget.h"

// pdb: class BGSMusicType, size 0x34, bases: TESForm, TESSoundFile, 3 members
struct BGSMusicType : public TESForm, public TESSoundFile
{
public:
    class MusicTrack
    {
    public:
        char m_acTrackName[260];

        MusicTrack(const char* apFilename);
    };

    float fAttenuation;
    BSSimpleList<MusicTrack*> pMusicFileList;
    unsigned int iLastSelection;

    BGSMusicType();
    virtual ~BGSMusicType();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();

    bool Load(TESFile* file);
    void UpdateLoadingStatusCallback();
    bool GetLooping();
    float GetAttenuation();
    const char* GetRandomEntry();
    void BGSMusicType_ClearData(); // exe 0x005913b0: clear the track list
};
