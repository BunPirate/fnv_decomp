// bsaudio/bssoundhandle.cpp: sound playback and HUD helpers (37 functions)

#include "bssoundhandle_decls.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioManager.h"
#include "../../include/HUDMainMenu.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/Setting.h"

extern BSAudio* DAT_011f6d98;

__forceinline BSAudio* BSAudio::GetRandomGenerator()
{
    return DAT_011f6d98;
}

__forceinline bool BSAudio::IsAudioEnabled() const
{
    return bAudioEnabled;
}

// @fnv 0x00ad8e60
// pdb: BSSoundHandle::SetCompletionCallback | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: apfnCallback, apContext
void BSSoundHandle::SetCompletionCallback(CompletionCallback apfnCallback, void* context)
{
    if (!BSAudio::GetRandomGenerator()->IsAudioEnabled() && apfnCallback)
    {
        apfnCallback(context, false);
    }
    if (iSoundID != 0xffffffff)
    {
        BSAudioManager::GetRandomGenerator().BSAudioManager_SetCompletionCallback(iSoundID, apfnCallback, context);
    }
}

// Returns false when the sound handle is invalid, otherwise checks the cached state or queries BSAudioManager::IsPlaying for the handle.
// @fnv 0x00ad8930
// pdb: BSSoundHandle::IsPlaying | BSSoundHandle.obj | retail, upstream name already matches, high
bool BSSoundHandle::IsPlaying()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    if (bAssumeSuccess)
    {
        return eState == ASSUMED_STATE_PLAYING;
    }
    else
    {
        return BSAudioManager::GetRandomGenerator().IsPlaying(iSoundID);
    }
}

// If the stored sound handle is valid, sets the state to playing and forwards the handle, delay and start time to BSAudioManager.
// @fnv 0x00ad8870
// pdb: BSSoundHandle::PlayAfter | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiDelay, aiPlayFlags
bool BSSoundHandle::PlayAfter(unsigned int aiDelay, int aiPlayFlags)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_PlayAfter(iSoundID, aiDelay, aiPlayFlags);
}

// If a sound handle is set, passes it with fadeTime and 0x26 to BSAudioManager, clears the handle, and returns true; otherwise returns false.
// @fnv 0x00ad8da0
// pdb: BSSoundHandle::FadeOutAndRelease | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiMilliseconds
bool BSSoundHandle::FadeOutAndRelease(unsigned int aiMilliseconds)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(iSoundID, aiMilliseconds, 0x26);
    iSoundID = 0xffffffff;
    return true;
}

// @fnv 0x00719060
// pdb: SystemColorManager::GetColor | InterfaceManager.obj | retail, call graph, high
// pdb params: aiID, aOutColor
// pdb locals: pcolor
bool SystemColorManager::GetColor(int aiID, NiColor& aOutColor)
{
    SystemColor* systemColor = Find(aiID);
    if (systemColor)
    {
        systemColor->GetColor(aOutColor);
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x00ad8a90
// pdb: BSSoundHandle::SetModFrequency | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: afNewFrequency
bool BSSoundHandle::SetModFrequency(float afNewFrequency)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().SetPlaybackFrequency(iSoundID, afNewFrequency);
}

// @fnv 0x00ad8ce0
// pdb: BSSoundHandle::IsValid | BSSoundHandle.obj | retail, upstream name already matches, high
bool BSSoundHandle::IsValid()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().BSAudioManager_IsValid(iSoundID);
}

// This singleton helper is distinct from the shared instance RefreshTargetDisplay method.
// @fnv 0x00778b10
// src: XBOX_DEBUG_PDB 0x00778b10
// pdb: HUDMainMenu::RefreshInfoForRef | HUDMainMenu.obj | debug, call graph, high
void __cdecl HUDMainMenu_RefreshInfoForRef()
{
    if (HUDMainMenu::g_pHudMainMenuInstance)
    {
        HUDMainMenu::UpdateTargetReference(HUDMainMenu::g_pHudMainMenuInstance->pLastObject, false, true);
    }
}

void __cdecl abs_0072fa80(int);

// @fnv 0x0072fa60
// src: XBOX_PDB 0x0072fa60
// pdb: BSAbs | BarterMenu.obj | debug, upstream name already matches, high
// pdb params: alValue
void __cdecl BSAbs(int alValue)
{
    abs_0072fa80(alValue);
}

// @fnv 0x00ad8830
// pdb: BSSoundHandle::Play | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: abLoopPlayback
bool BSSoundHandle::Play(bool abLoopPlayback)
{
    if (iSoundID == 0xffffffff)
        return false;
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Play(iSoundID, abLoopPlayback);
}

// @fnv 0x00ad89b0
// pdb: BSSoundHandle::SetStaticAttenuation | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiStaticAttenutation
bool BSSoundHandle::SetStaticAttenuation(unsigned short aiStaticAttenutation)
{
    if (iSoundID == -1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetStaticAttenuation(iSoundID, aiStaticAttenutation);
}

// @fnv 0x00ad89e0
// pdb: BSSoundHandle::SetVolume | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiNewVolume
bool BSSoundHandle::SetVolume(float aiNewVolume)
{
    if (static_cast<int>(iSoundID) == -1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetVolume(static_cast<int>(iSoundID), aiNewVolume);
}

// If id is valid, forwards id and v to BSAudioManager's FUN_00adb8e0 and returns its result; otherwise returns false.
// @fnv 0x00ad8ad0
// pdb: BSSoundHandle::SetFrequencyVariance | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiFreqVariance
bool BSSoundHandle::SetFrequencyVariance(unsigned char aiFreqVariance)
{
    if (iSoundID == 0xffffffff)
        return false;
    // Forward the original byte unchanged; converting it to bool adds normalization code.
    return (BSAudioManager::GetRandomGenerator().*reinterpret_cast<bool (BSAudioManager::*)(unsigned int, unsigned char)>(
        static_cast<bool (BSAudioManager::*)(unsigned int, bool)>(&BSAudioManager::BSAudioManager_SetFrequencyVariance)))(iSoundID, aiFreqVariance);
}

// @fnv 0x00ad8b60
// pdb: BSSoundHandle::SetPosition | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aPosition
bool BSSoundHandle::SetPosition(float afX, float afY, float afZ)
{
    if (iSoundID == 0xFFFFFFFF)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetPosition(iSoundID, afX, afY, afZ);
}

// @fnv 0x00ad8be0
// pdb: BSSoundHandle::SetMinMax | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: afMin, afMax
void BSSoundHandle::SetMinMax(float afMin, float afMax)
{
    if (iSoundID == 0xFFFFFFFF)
        return;

    BSAudioManager::GetRandomGenerator().BSAudioManager_SetMinMax(iSoundID, afMin, afMax);
}

// @fnv 0x00ad8c20
// pdb: BSSoundHandle::SetAttenuationCurve | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiPt1, aiPt2, aiPt3, aiPt4, aiPt5
void BSSoundHandle::SetAttenuationCurve(unsigned short aiPt1, unsigned short aiPt2, unsigned short aiPt3,
                                            unsigned short aiPt4, unsigned short aiPt5)
{
    if (iSoundID == 0xFFFFFFFF)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetAttenuationCurve(iSoundID, aiPt1, aiPt2, aiPt3, aiPt4, aiPt5);
}

// @fnv 0x00ad8c70
// pdb: BSSoundHandle::SetReverbAttenuation | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiReverbAtt
void BSSoundHandle::SetReverbAttenuation(unsigned short aiReverbAtt)
{
    if (iSoundID == -1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetReverbAttenuation(iSoundID, aiReverbAtt);
}

extern void(__cdecl* DAT_011f6e08)(NiAVObject*);
// If the stored id is valid and apObj is non-null, calls DAT_011f6e08 on apObj and then FUN_00adc1e0 with the stored id and apObj.
// @fnv 0x00ad8f20
// pdb: BSSoundHandle::SetObjectToFollow | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: apObj
void BSSoundHandle::SetObjectToFollow(NiAVObject* apObj)
{
    if (iSoundID == 0xFFFFFFFF || !apObj)
        return;
    if (DAT_011f6e08)
        DAT_011f6e08(apObj);
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetObjectToFollow(iSoundID, apObj);
}

// @fnv 0x00ad8f70
// pdb: BSSoundHandle::Seek | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: aiMilliseconds
void BSSoundHandle::Seek(unsigned int aiMilliseconds)
{
    if (iSoundID == 0xffffffff)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetPriority(iSoundID, aiMilliseconds);
}

extern Setting originalRuntimeFloatSetting104;

struct FUN_008bc240_h
{
    char pad[0x150];
    unsigned int f150;
    float f154;
    void Actor_SetActionSoundValue(unsigned int aiValue);
};

// Stores v into f150 and copies the float from originalRuntimeFloatSetting104 into f154.
// @fnv 0x008bc240
// src: COMMUNITY 0x008bc240
// pdb: Actor::SetActionSoundValue | Actor.obj | debug, upstream name already matches, high
// pdb params: aiValue
void FUN_008bc240_h::Actor_SetActionSoundValue(unsigned int aiValue)
{
    f150 = aiValue;
    f154 = *originalRuntimeFloatSetting104.Float();
}

struct Owner009b11c0
{
    void Explosion_StopSounds();
};

// @fnv 0x009b11c0
// src: XBOX_PDB 0x009b11c0
// pdb: Explosion::StopSounds | Explosion.obj | retail, upstream name already matches, high
void Owner009b11c0::Explosion_StopSounds()
{
    if (((BSSoundHandle*)((char*)this + 0xac))->IsValid())
    {
        ((BSSoundHandle*)((char*)this + 0xac))->Stop();
        if (((BSSoundHandle*)((char*)this + 0xac))->IsValid())
        {
            ((BSSoundHandle*)((char*)this + 0xac))->Release();
        }
    }
    if (((BSSoundHandle*)((char*)this + 0xb8))->IsValid())
    {
        ((BSSoundHandle*)((char*)this + 0xb8))->Stop();
        if (((BSSoundHandle*)((char*)this + 0xb8))->IsValid())
        {
            ((BSSoundHandle*)((char*)this + 0xb8))->Release();
        }
    }
}

// @fnv 0x00ad88b0
// pdb: BSSoundHandle::Pause | BSSoundHandle.obj | retail, upstream name already matches, high
bool BSSoundHandle::Pause()
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_PAUSED;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Pause(iSoundID);
}

// @fnv 0x00ad88f0
// pdb: BSSoundHandle::Stop | BSSoundHandle.obj | retail, upstream name already matches, high
bool BSSoundHandle::Stop()
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_STOPPED;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Stop(iSoundID);
}

// @fnv 0x00ad8980
// pdb: BSSoundHandle::GetSoundType | BSSoundHandle.obj | debug, upstream name already matches, high
int BSSoundHandle::GetSoundType()
{
    if (iSoundID == 0xFFFFFFFF)
        return 0;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetSoundType(iSoundID);
}

// @fnv 0x00ad8a20
// pdb: BSSoundHandle::GetVolume | BSSoundHandle.obj | retail, upstream name already matches, high
float BSSoundHandle::GetVolume()
{
    if (iSoundID == 0xFFFFFFFF)
        return 0.0f;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetVolume(iSoundID);
}

// If the stored id is not -1, forwards the id and arg to BSAudioManager's FUN_00adb7c0 and returns its result; otherwise returns false.
// @fnv 0x00ad8a50
// pdb: BSSoundHandle::SetFrequency | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: afNewFrequency
bool BSSoundHandle::SetFrequency(float afNewFrequency)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetFrequency(iSoundID, afNewFrequency);
}

// Returns false if id is -1, otherwise forwards id and arg to FUN_00adb960 on the BSAudioManager singleton.
// @fnv 0x00ad8b00
// pdb: BSSoundHandle::SetBalance | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: aiNewBalance
bool BSSoundHandle::SetBalance(int aiNewBalance)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetBalance(iSoundID, static_cast<unsigned int>(aiNewBalance));
}

// Queries the duration through the audio manager when this handle is valid.
// @fnv 0x00ad8b30
// pdb: BSSoundHandle::GetDuration | BSSoundHandle.obj | retail, upstream name already matches, high
int BSSoundHandle::GetDuration()
{
    if (iSoundID == -1)
        return 0;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetDuration(iSoundID);
}

// Returns false if id is -1, otherwise forwards id and the three floats to the audio manager's FUN_00adb9f0 and returns its result.
// @fnv 0x00ad8ba0
// pdb: BSSoundHandle::SetBeamEnd | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: afX, afY, afZ
bool BSSoundHandle::SetBeamEnd(float afX, float afY, float afZ)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetBeamEnd(iSoundID, afX, afY, afZ);
}

// If id is not -1, forwards id and the three floats to the audio manager's FUN_00adbf40 and returns its result; otherwise returns false.
// @fnv 0x00ad8ca0
// pdb: BSSoundHandle::SetOrientation | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: afX, afY, afZ
bool BSSoundHandle::SetOrientation(float afX, float afY, float afZ)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetOrientation(iSoundID, afX, afY, afZ);
}

// @fnv 0x00ad8de0
// pdb: BSSoundHandle::FadeOut | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: aiMilliseconds
bool BSSoundHandle::FadeOut(unsigned int aiMilliseconds)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_STOPPED;
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(iSoundID, aiMilliseconds, 0);
    return true;
}

// If id is not -1, forwards id and the two byte arguments to FUN_00adc4e0 on the BSAudioManager singleton.
// @fnv 0x00ad8e20
// pdb: BSSoundHandle::SetTimeConstraints | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiStart, aiStop
void BSSoundHandle::SetTimeConstraints(unsigned char aiStart, unsigned char aiStop)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetTimeConstraints(iSoundID, aiStart, aiStop);
}

typedef void(__cdecl* LocalCb)(void*, unsigned int);

// @fnv 0x00ad8ec0
// pdb: BSSoundHandle::SetPlayCallback | BSSoundHandle.obj | debug, upstream name already matches, high
// pdb params: apfnCallback, apContext
void BSSoundHandle::SetPlayCallback(CompletionCallback apfnCallback, void* apContext)
{
    BSAudio* audio = DAT_011f6d98;
    bool flag = audio->bAudioEnabled;
    if (!flag && apfnCallback)
    {
        reinterpret_cast<LocalCb>(apfnCallback)(apContext, 5000);
    }
    if (iSoundID != 0xFFFFFFFF)
    {
        BSAudioManager::GetRandomGenerator().BSAudioManager_SetPlayCallback(iSoundID, reinterpret_cast<LocalCb>(apfnCallback), apContext);
    }
}

// If id is not -1, forwards id and arg to FUN_00adc260 on the BSAudioManager instance.
// @fnv 0x00ad8fd0
// pdb: BSSoundHandle::SetSynchStartTime | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiStartTime
void BSSoundHandle::SetSynchStartTime(unsigned int aiStartTime)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_Seek(iSoundID, aiStartTime);
}

// If the stored id is not -1, forwards it and arg to BSAudioManager's FUN_00adc2e0.
// @fnv 0x00ad8fa0
// pdb: BSSoundHandle::SetFollowsListener | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: abFollowsListener
void BSSoundHandle::SetFollowsListener(bool abFollowsListener)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetAtListener(iSoundID, static_cast<unsigned char>(abFollowsListener));
}

// If the stored id is not -1, forwards it and arg to BSAudioManager::FUN_00adc360.
// @fnv 0x00ad9030
// pdb: BSSoundHandle::SetPriority | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb params: aiPriority
void BSSoundHandle::SetPriority(unsigned int aiPriority)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetSynchStartTime(iSoundID, aiPriority);
}

// BSSoundHandle::ClearSynchStartTime (community FalloutNV.pdb at this address).
// @fnv 0x00ad9000
// pdb: BSSoundHandle::ClearSynchStartTime | BSSoundHandle.obj | debug, upstream name already matches, high
void BSSoundHandle::ClearSynchStartTime()
{
    if (iSoundID == 0xFFFFFFFF)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_ClearSynchStartTime(iSoundID);
}
