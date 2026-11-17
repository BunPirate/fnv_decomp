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

    float fAttenuation; // src: XBOX_RETAIL_PDB +0x24 (old: fVolumeScale)
    BSSimpleList<MusicTrack*> pMusicFileList; // src: XBOX_RETAIL_PDB +0x28 (old: m_kMusicFiles)
    unsigned int iLastSelection; // src: XBOX_RETAIL_PDB +0x30 (old: m_uiSelectedSoundIndex)

    BGSMusicType();
    virtual ~BGSMusicType();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();

    bool Load(TESFile* apFile);
    void UpdateLoadingStatusCallback();
    bool GetLooping();
    float GetAttenuation();
    const char* GetRandomEntry();
    void BGSMusicType_ClearData(); // exe 0x005913b0: clear the track list
};
