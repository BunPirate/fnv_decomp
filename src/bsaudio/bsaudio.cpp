// bsaudio/bsaudio.cpp: audio forwarding and playback handles

#include "bsaudio_decls.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioListener.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/AutoMemContext.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/Tile.h"
#include "../../include/TESResponse.h"

struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;

__forceinline AutoMemContext::AutoMemContext(int context)
{
    int previous = g_tls_00ad7740.memContext;
    iOldMemContext = static_cast<MEM_CONTEXT>(previous);
    g_tls_00ad7740.memContext = context;
}

__forceinline AutoMemContext::~AutoMemContext()
{
    int previous = iOldMemContext;
    g_tls_00ad7740.memContext = previous;
}

inline BSSoundHandle::BSSoundHandle(const BSSoundHandle& rhs)
    : iSoundID(rhs.iSoundID), bAssumeSuccess(rhs.bAssumeSuccess), eState(rhs.eState)
{}

inline BSSoundHandle::~BSSoundHandle()
{}

// @fnv 0x00ad8780
void BSAudio::SetAudioState(unsigned int argument0)
{}

// @fnv 0x00762150
void BSAudio::EnableAudio()
{
    DAT_011dcfa4 = 1;
}

// @fnv 0x007624c0
void BSAudio::DeactivateAudio()
{
    DAT_011dcfa4 = 0;
}

// @fnv 0x007ec380
// src: XBOX_DEBUG_PDB 0x007ec380
// pdb: BSAudio::UnPauseWorldSounds | VATSMenu.obj | debug, call graph, high
void BSAudio::UnPauseWorldSounds()
{
    reinterpret_cast<BSAudioManager*>(this)->UnPauseAllOfType(0x3002, false);
}

// @fnv 0x00ad7ae0
// pdb: BSAudio::GetMusicVolume | BSAudio.obj | retail, upstream name already matches, high
float BSAudio::GetMusicVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fRadioVolume;
    return volume;
}

// @fnv 0x00ad8480
// src: XBOX_DEBUG_PDB 0x00ad8480
// pdb: BSAudio::MuteType | BSAudio.obj | debug, call graph, high
// pdb params: aiType, aiFadeTimeMS, aiMillibels
void BSAudio::MuteType(unsigned int aiType, unsigned int aiFadeTimeMS, unsigned int aiMillibels)
{
    BSAudioManager::GetRandomGenerator().SetAudioSettingValue(aiType, aiFadeTimeMS, aiMillibels);
}

// @fnv 0x00ad78b0
// src: XBOX_RETAIL_PDB 0x00ad78b0
// pdb: BSAudio::PositionListener | BSAudio.obj | retail, object-file run extension, high
// pdb params: aNewPosition
void BSAudio::PositionListener(NiPoint3 aNewPosition)
{
    BSAudioManager::GetRandomGenerator().SetListenerPosition(aNewPosition);
}

// @fnv 0x00ad8d10
// pdb: BSSoundHandle::Release | BSSoundHandle.obj | retail, upstream name already matches, high
// pdb locals: bretValue
bool BSSoundHandle::Release()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }

    bool released = BSAudioManager::GetRandomGenerator().BSAudioManager_Release(iSoundID);
    if (released)
    {
        iSoundID = 0xffffffff;
    }
    return released;
}

// @fnv 0x00ad79f0
// pdb: BSAudio::GetMasterVolume | BSAudio.obj | retail, upstream name already matches, high
float BSAudio::GetMasterVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMasterVolume;
    return volume;
}

// @fnv 0x00ad7a20
// src: COMMUNITY 0x00ad7a20
// pdb: BSAudio::GetFootVolume | BSAudio.obj | retail, upstream name already matches, high
float BSAudio::GetFootVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fFootVolume;
    return volume;
}

// @fnv 0x00ad7a50
// src: COMMUNITY 0x00ad7a50
// pdb: BSAudio::GetVoiceVolume | BSAudio.obj | retail, upstream name already matches, high
float BSAudio::GetVoiceVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fVoiceVolume;
    return volume;
}

// @fnv 0x00ad7a80
// src: COMMUNITY 0x00ad7a80
float BSAudio::GetEffectsVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fEffectsVolume;
    return volume;
}

// @fnv 0x00ad7ab0
// src: COMMUNITY 0x00ad7ab0
float BSAudio::GetMusicVolume_00ad7ab0()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMusicVolume;
    return volume;
}

// @fnv 0x00ad7c80
// src: COMMUNITY 0x00ad7c80
// pdb: BSAudio::GetMasterSecondaryVolume | BSAudio.obj | retail, upstream name already matches, high
float BSAudio::GetMasterSecondaryVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMasterSecondaryVolume;
    return volume;
}

inline bool IsListenerUnderwater(BSAudioManager* manager)
{
    return manager->bListenerUnderwater;
}

// @fnv 0x00ad7c50
// src: COMMUNITY 0x00ad7c50
// pdb: BSAudio::IsListenerUnderwater | BSAudio.obj | debug, object-file gap fill, medium
bool BSAudio::IsListenerUnderwater_00ad7c50()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    return IsListenerUnderwater(manager);
}

// @fnv 0x00ad7990
// src: COMMUNITY 0x00ad7990
// pdb: BSAudio::SetListenerUnderwater | BSAudio.obj | retail, upstream name already matches, high
// pdb params: abIsUnderwater
void BSAudio::SetListenerUnderwater(bool abIsUnderwater)
{
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetListenerUnderwater(abIsUnderwater);
}

// @fnv 0x00ad7940
// src: COMMUNITY 0x00ad7940
// pdb: BSAudio::OrientListener | BSAudio.obj | retail, upstream name already matches, high
// pdb params: aFront, aTop
void BSAudio::OrientListener(NiPoint3 aFront, NiPoint3 aTop)
{
    if (*reinterpret_cast<const NiPointer<BSAudioListener>*>(&pListener))
        (*reinterpret_cast<const NiPointer<BSAudioListener>*>(&pListener))->vfn_14(&aFront, &aTop);
}

// Calls the synchronization callback, then clears bit 0 of the synchronization flags.
// @fnv 0x00ad8740
// src: XBOX_PDB 0x00ad8740
// pdb: BSAudio::UnPauseSynchTimer | BSAudio.obj | retail, upstream name already matches, high
void BSAudio::UnPauseSynchTimer()
{
    if (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))
    {
        (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))();
    }
    char* p = reinterpret_cast<char*>(this) + 0x14;
    *reinterpret_cast<unsigned int*>(p + 8) &= ~1u;
}

// Sets the thread-local memory context to 0xb for the duration of the call, then forwards abFlag to BSAudioManager::Update.
// @fnv 0x00ad7740
// pdb: BSAudio::Update | BSAudio.obj | retail, upstream name already matches, high
// pdb params: abPlayGameWorldSounds
// pdb locals: tempMemContext
void BSAudio::Update(bool abPlayGameWorldSounds)
{
    AutoMemContext guard(0xb);
    BSAudioManager::GetRandomGenerator().BSAudioManager_Update(abPlayGameWorldSounds);
}

// @fnv 0x00ad7fa0
// pdb: BSAudio::Precache | BSAudio.obj | retail, call graph, high
// pdb params: apSoundName, aiFlags
// pdb locals: tempMemContext
void BSAudio::Precache(char* apSoundName, unsigned int aiFlags)
{
    AutoMemContext guard(0xb);
    BSAudioManager::GetRandomGenerator().BSAudioManager_Precache(apSoundName, aiFlags);
}

struct FUN_0083b8d0_stub
{
    void FUN_0083b8d0();
};
struct FUN_00798450_shell
{
    void* FUN_00798450(unsigned int flags);
};
// Calls FUN_0083b8d0 on this, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x00798450
// pdb: Conversation::~Conversation | Conversation.obj | retail, call graph (shared callers), low
// pdb note: debug build links it to Conversation::`scalar deleting destructor'
void* FUN_00798450_shell::FUN_00798450(unsigned int flags)
{
    ((FUN_0083b8d0_stub*)this)->FUN_0083b8d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl InterfaceManager_GetSingleton();
extern int DAT_011da9a4;
// If DAT_011da9a4 is set, stores 7 at offset 0x28 and calls Set(0xfa9, 255.0f, true) on the next TESResponse tile.
// @fnv 0x007c2420
// src: COMMUNITY 0x007c2420
// pdb: SlotMachineMenu::Close | SlotMachineMenu.obj | debug, call graph, high
void SlotMachineMenu_SetShouldExit()
{
    if (DAT_011da9a4)
    {
        *(int*)(DAT_011da9a4 + 0x28) = 7;
        ((Tile*)((TESResponse*)InterfaceManager_GetSingleton())->GetNext())->Set(0xfa9, 255.0f, true);
    }
}

struct FUN_00aa4a50_shell2
{
    void Thiscall_1Arg(int a);
};
// @fnv 0x00aa4a50
// src: COMMUNITY 0x00aa4a50
void FUN_00aa4a50_shell2::Thiscall_1Arg(int a)
{}

__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
inline bool IsAudioActive(BSAudio* audio)
{
    return audio->bAudioEnabled;
}

// If audio is enabled, stops multithreaded processing when needed, clears initialization, and resets the manager.
// @fnv 0x00ad7150
// src: XBOX_PDB 0x00ad7150
// pdb: BSAudio::Shutdown | BSAudio.obj | retail, upstream name already matches, high
// pdb locals: tempMemContext
void __fastcall BSAudio_Shutdown(BSAudio* audio)
{
    AudioThreadModeScope scope;
    if (IsAudioActive(audio))
    {
        if (audio->bMultiThread)
            BSAudioManager::GetRandomGenerator().BSAudioManager_StopAudioThread();
        audio->bInitialized = false;
        BSAudioManager::GetRandomGenerator().BSAudioManager_Shutdown();
    }
}

extern NiPoint3 _NiPoint3_ZERO;
// BSAudio.h currently declares this operation with weapon_audio::NiPoint3,
// rather than the NiPoint3 value returned by this unit.
struct FUN_00ad78e0_cls : public BSAudio
{
    NiPoint3 BSAudio_GetListenerPosition();
};
// @fnv 0x00ad78e0
// src: COMMUNITY 0x00ad78e0
// pdb: BSAudio::GetListenerPosition | BSAudio.obj | retail, upstream name already matches, high
NiPoint3 FUN_00ad78e0_cls::BSAudio_GetListenerPosition()
{
    const NiPoint3* p = pListener ? &pListener->GetPosition_00aeaad0() : &_NiPoint3_ZERO;
    return *p;
}

// Sets BSAudioManager's master volume to f and calls FUN_00adc160 with the manager.
// @fnv 0x00ad7b10
// pdb: BSAudio::SetMasterVolume | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afNewVol
void BSAudio::SetMasterVolume(float afNewVol)
{
    BSAudioManager& mgr = BSAudioManager::GetRandomGenerator();
    mgr.fMasterVolume = afNewVol;
    mgr.BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7b40
// src: XBOX_RETAIL_PDB 0x00ad7b40
// pdb: BSAudio::SetFootVolume | BSAudio.obj | retail, object-file gap fill, high
// pdb params: afNewVol
void BSAudio::SetFootVolume(float afNewVol)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fFootVolume = afNewVol;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7b70
// src: COMMUNITY 0x00ad7b70
// pdb: BSAudio::SetVoiceVolume | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afNewVol
void BSAudio::SetVoiceVolume(float afNewVol)
{
    BSAudioManager& instance = BSAudioManager::GetRandomGenerator();
    instance.fVoiceVolume = afNewVol;
    instance.BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7ba0
// src: XBOX_RETAIL_PDB 0x00ad7ba0
// pdb: BSAudio::SetEffectVolume | BSAudio.obj | retail, object-file gap fill, high
// pdb params: afNewVol
void BSAudio::SetEffectVolume(float afNewVol)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fEffectsVolume = afNewVol;
    mgr->BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7bd0
// src: COMMUNITY 0x00ad7bd0
// pdb: BSAudio::SetMusicVolume | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afNewVol
void BSAudio::SetMusicVolume(float afNewVol)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMusicVolume = afNewVol;
    mgr->BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7c00
// src: XBOX_PDB 0x00ad7c00
// pdb: BSAudio::SetRadioVolume | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afNewVol
void BSAudio::SetRadioVolume(float afNewVol)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fRadioVolume = afNewVol;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7c30
// src: COMMUNITY 0x00ad7c30
// pdb: BSAudio::VolumeChanged | BSAudio.obj | debug, upstream name already matches, high
void __fastcall BSAudio_VolumeChanged(BSAudio*)
{
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetRadioVolume();
}

// Reads the float at offset 0x15c of the BSAudioManager singleton and returns it.
// @fnv 0x00ad7cb0
// src: COMMUNITY 0x00ad7cb0
// pdb: BSAudio::GetFootSecondaryVolume | BSAudio.obj | debug, upstream name already matches, high
float __fastcall BSAudio_GetFootSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float val = mgr->fFootSecondaryVolume;
    return val;
}

// @fnv 0x00ad7ce0
// src: COMMUNITY 0x00ad7ce0
// pdb: BSAudio::GetVoiceSecondaryVolume | BSAudio.obj | debug, upstream name already matches, high
float __fastcall BSAudio_GetVoiceSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fVoiceSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d10
// src: COMMUNITY 0x00ad7d10
// pdb: BSAudio::GetEffectSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
float __fastcall BSAudio_GetEffectsSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fEffectsSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d40
// src: COMMUNITY 0x00ad7d40
// pdb: BSAudio::GetMusicSecondaryVolume | BSAudio.obj | debug, upstream name already matches, high
float __fastcall BSAudio_GetMusicSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fMusicSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d70
// src: COMMUNITY 0x00ad7d70
// pdb: BSAudio::GetRadioSecondaryVolume | BSAudio.obj | debug, upstream name already matches, high
float __fastcall BSAudio_GetRadioSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fRadioSecondaryVolume;
    return result;
}

namespace fnv_00ad7da0 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7da0
// src: COMMUNITY 0x00ad7da0
// pdb: BSAudio::SetMasterSecondaryVolume | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afNewVol
void __fastcall BSAudio_SetMasterSecondaryVolume(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMasterSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7da0

namespace fnv_00ad7dd0 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7dd0
// src: COMMUNITY 0x00ad7dd0
// pdb: BSAudio::SetFootSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: afNewVol
void __fastcall BSWin32Audio_SetFootstepVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fFootSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7dd0

namespace fnv_00ad7e00 {

// Stores value into the audio manager's field and then calls FUN_00adc160 on it.
// @fnv 0x00ad7e00
// src: COMMUNITY 0x00ad7e00
// pdb: BSAudio::SetVoiceSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: afNewVol
void __fastcall BSWin32Audio_SetVoiceVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fVoiceSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7e00

namespace fnv_00ad7e30 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7e30
// src: COMMUNITY 0x00ad7e30
// pdb: BSAudio::SetEffectSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: afNewVol
void __fastcall BSWin32Audio_SetEffectsVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fEffectsSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7e30

// @fnv 0x00ad7e60
// src: COMMUNITY 0x00ad7e60
// pdb: BSAudio::SetMusicSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: afNewVol
void __fastcall BSWin32Audio_SetMusicVolumeMult(BSAudio*, float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMusicSecondaryVolume = v;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7e90
// src: COMMUNITY 0x00ad7e90
// pdb: BSAudio::SetRadioSecondaryVolume | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: afNewVol
void __fastcall BSWin32Audio_SetRadioVolumeMult(BSAudio*, float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fRadioSecondaryVolume = v;
    mgr->BSAudioManager_SetRadioVolume();
}

void __fastcall BSAudioManager_ClearSecondaryVolumes(BSAudioManager* m);
// @fnv 0x00ad7ec0
// src: COMMUNITY 0x00ad7ec0
// pdb: BSAudio::ClearSecondaryVolumes | BSAudio.obj | retail, upstream name already matches, high
void __fastcall BSAudio_ClearSecondaryVolumes(BSAudio*)
{
    BSAudioManager_ClearSecondaryVolumes(&BSAudioManager::GetRandomGenerator());
}

namespace fnv_00ad7ee0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudioManager.h lacks int FUN_00ae5ff0(unsigned int).
struct FUN_00ae5ff0_stub
{
    int BSAudioManager_GetDebugString(unsigned int);
};
// BSAudio.h lacks int FUN_00ad7ee0(unsigned int).
struct FUN_00ad7ee0_shell
{
    int BSAudioManager_DebugPrintSounds_(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it and returns the result of FUN_00ae5ff0(n).
// @fnv 0x00ad7ee0
// src: COMMUNITY 0x00ad7ee0
// pdb: BSAudio::GetDebugString | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: aiPage
// pdb locals: tempMemContext
int FUN_00ad7ee0_shell::BSAudioManager_DebugPrintSounds_(unsigned int n)
{
    AudioThreadModeScope scope;
    return ((FUN_00ae5ff0_stub*)&BSAudioManager::GetRandomGenerator())->BSAudioManager_GetDebugString(n);
}
}  // namespace fnv_00ad7ee0

namespace fnv_00ad81c0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudio.h lacks void SetAudioThreadModeAndForward(unsigned int).
struct FUN_00ad81c0_shell
{
    void SetAudioThreadModeAndForward(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the scope, and forwards n to SetAudioCacheSize on the BSAudioManager singleton.
// @fnv 0x00ad81c0
// pdb: BSAudio::SetAudioCacheSizeInK | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: aiNewSize
// pdb locals: tempMemContext
void FUN_00ad81c0_shell::SetAudioThreadModeAndForward(unsigned int auiValue)
{
    AudioThreadModeScope scope;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetAudioCacheSizeInK(static_cast<int>(auiValue));
}
}  // namespace fnv_00ad81c0

namespace fnv_00ad8270 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// @fnv 0x00ad8270
// src: COMMUNITY 0x00ad8270
// pdb: BSAudio::GetAudioCacheSizeInK | BSAudio.obj | debug, upstream name already matches, high
// pdb locals: tempMemContext
int __fastcall BSAudio_GetAudioCacheSizeInK(BSAudio*)
{
    AudioThreadModeScope scope;
    return BSAudioManager::GetRandomGenerator()._BSAudioManager_AudioCacheSize();
}
}  // namespace fnv_00ad8270

namespace fnv_00ad8320 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudio.h lacks void FUN_00ad8320(bool).
struct FUN_00ad8320_shell
{
    void BSAudio_SetCacheEnabled(bool abEnableCache);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it after forwarding b to FUN_00ae6ca0 on the audio manager.
// @fnv 0x00ad8320
// src: COMMUNITY 0x00ad8320
// pdb: BSAudio::SetCacheEnabled | BSAudio.obj | debug, upstream name already matches, high
// pdb params: abEnableCache
// pdb locals: tempMemContext
void FUN_00ad8320_shell::BSAudio_SetCacheEnabled(bool abEnableCache)
{
    AudioThreadModeScope scope;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetCacheEnabled(abEnableCache);
}
}  // namespace fnv_00ad8320

namespace fnv_00ad83d0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// @fnv 0x00ad83d0
// src: COMMUNITY 0x00ad83d0
// pdb: BSAudio::GetCacheEnabled | BSAudio.obj | debug, upstream name already matches, high
// pdb locals: tempMemContext
bool __fastcall BSAudio_GetCacheEnabled(BSAudio*)
{
    AudioThreadModeScope scope;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_IsEnableAudioCache();
}
}  // namespace fnv_00ad83d0

extern MemoryManager g_memoryManager;
void __fastcall FUN_00ad7000(BSAudio*);
// BSAudio.h lacks void* FUN_00ad8790(unsigned int), the deleting destructor.
struct FUN_00ad8790_shell
{
    void* FUN_00ad8790(unsigned int flags);
};
// Calls FUN_00ad7000 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ad8790
// pdb: BSThread::`scalar deleting destructor' | BSThread_Xenon.obj | debug, object-file run extension, low
void* FUN_00ad8790_shell::FUN_00ad8790(unsigned int flags)
{
    FUN_00ad7000(reinterpret_cast<BSAudio*>(this));
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

extern bool DAT_01202800;

struct SettingBool
{
    virtual ~SettingBool();
    bool bValue;
    char* pKey;
    bool& GetBool()
    {
        return this ? bValue : (DAT_01202800 = false);
    }
};

extern SettingBool g_011f6dfc;

inline bool BSAudio::IsAudioEnabled() const
{
    return bAudioEnabled;
}

// @fnv 0x00ad7230
// pdb: BSAudio::SetMultiThreaded | BSAudio.obj | retail, call graph (shared callers), high
// pdb params: abUseMultipleThreads
// pdb locals: tempMemContext
void BSAudio::SetUseMultipleThreads(bool abUseMultipleThreads)
{
    MemContextScope tempMemContext(11);
    if (!IsAudioEnabled())
    {
        return;
    }
    if (!g_011f6dfc.GetBool() && abUseMultipleThreads)
    {
        return;
    }
    if (abUseMultipleThreads && !bMultiThread)
    {
        BSAudioManager::GetRandomGenerator().StartAudioThreads();
    }
    else if (!abUseMultipleThreads && bMultiThread)
    {
        BSAudioManager::GetRandomGenerator().StopAudioThreads();
    }
    bMultiThread = abUseMultipleThreads;
}

// BSAudioManager.h lacks BSSoundHandle FUN_00ae5870(unsigned int, unsigned int).
struct FUN_00ae5870_t
{
    BSSoundHandle BSAudioManager_GetSoundHandleByNumericID(unsigned int, unsigned int);
};
extern __declspec(thread) int BSAudioThreadContext;
__forceinline int BSAudioGetMemContext()
{
    return BSAudioThreadContext;
}
__forceinline void BSAudioSetMemContext(int aiMemoryContext)
{
    BSAudioThreadContext = aiMemoryContext;
}
struct BSAudioScopedMemContext
{
    int m_eMemoryContext;
    __forceinline BSAudioScopedMemContext(int m_iLineNumber) : m_eMemoryContext(BSAudioGetMemContext())
    {
        BSAudioSetMemContext(m_iLineNumber);
    }
    __forceinline ~BSAudioScopedMemContext()
    {
        BSAudioSetMemContext(m_eMemoryContext);
    }
};
// Sets the audio memory context to 11, then forwards the form ID and type flags to the sound manager to create a sound handle.
// @fnv 0x00ad73b0
// src: COMMUNITY 0x00ad73b0
// pdb: BSAudio::GetSoundHandleByNumericID | BSAudio.obj | debug, call graph, high
// pdb params: aiFormID, aiTypeFlags
// pdb locals: tempMemContext
BSSoundHandle BSAudio::GetSoundHandleByFormID_00ad73b0(unsigned int aiFormID, unsigned int aiTypeFlags)
{
    BSAudioScopedMemContext tempMemContext(11);
    return reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->BSAudioManager_GetSoundHandleByNumericID(aiFormID, aiTypeFlags);
}

namespace fnv_00ad7620 {
extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

// BSAudioManager.h lacks BSSoundHandle FUN_00ae5870(unsigned int, unsigned int).
struct FUN_00ae5870_t
{
    BSSoundHandle BSAudioManager_GetSoundHandleByNumericID(unsigned int, unsigned int);
};

// BSAudio.h lacks this four-argument positioned-handle factory.
struct FUN_00ad7620_t : public BSAudio
{
    BSSoundHandle BSAudio_SpawnSoundReference(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc, unsigned int aiID);
};

// Creates a sound handle for the given form and type flags, positions it at aLoc, starts playback, and returns the handle.
// @fnv 0x00ad7620
// src: XBOX_PDB 0x00ad7620
// pdb: BSAudio::SpawnSoundReference | BSAudio.obj | retail, upstream name already matches, high
// pdb params: aiFormID, aiTypeFlags, aLoc, aiID
// pdb locals: tempMemContext, hndl
BSSoundHandle FUN_00ad7620_t::BSAudio_SpawnSoundReference(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc,
                                             unsigned int aiID)
{
    MemContextScope tempMemContext(11);
    BSSoundHandle hndl =
        reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->BSAudioManager_GetSoundHandleByNumericID(aiFormID, aiTypeFlags);
    hndl.SetPosition(aLoc.x, aLoc.y, aLoc.z);
    hndl.Play(true);
    return hndl;
}
}  // namespace fnv_00ad7620

namespace fnv_00ad77f0 {
struct OH2TlsBlock
{
    char pad[0x2b4];
    int m_iThreadLocalValue;
};
extern __declspec(thread) OH2TlsBlock g_OH2Tls;
struct OH2MemContext
{
    int m_eMemoryContext;
    __forceinline OH2MemContext(int aiContext)
    {
        int iOld = g_OH2Tls.m_iThreadLocalValue;
        m_eMemoryContext = iOld;
        g_OH2Tls.m_iThreadLocalValue = aiContext;
    }
    __forceinline ~OH2MemContext()
    {
        int iOld = m_eMemoryContext;
        g_OH2Tls.m_iThreadLocalValue = iOld;
    }
};
} // namespace fnv_00ad77f0

// @fnv 0x00ad77f0
// src: COMMUNITY 0x00ad77f0
// pdb: BSAudio::SetConditions | BSAudio.obj | retail, upstream name already matches, high
// pdb params: afCurrentGamehour, aiWeatherConditions
// pdb locals: tempMemContext
void BSAudio::SetConditions(float afCurrentGamehour, unsigned int aiWeatherConditions)
{
    fnv_00ad77f0::OH2MemContext tempMemContext(0xb);
    BSAudioManager::GetRandomGenerator().SetConditions_00ada300(afCurrentGamehour, aiWeatherConditions);
}

__forceinline BSAudioListener* BSAudioGetListener(BSAudio* pAudio)
{
    return pAudio->pListener;
}
// If a listener is attached, forwards aiEnviroType to SetListenerID.
// @fnv 0x00ad79b0
// src: XBOX_PDB 0x00ad79b0
// pdb: BSAudio::SetEnvironment | BSAudio.obj | debug, upstream name already matches, high
// pdb params: aiEnviroType
void BSAudio::SetEnvironment(unsigned int aiEnviroType)
{
    if (BSAudioGetListener(this))
    {
        BSAudioGetListener(this)->SetListenerID(aiEnviroType);
    }
}

extern __declspec(thread) int g_tlsMemContext;

namespace sad8050 {

struct MemContextGuard
{
    int m_iPrevious;

    MemContextGuard(int aiMemoryContext)
    {
        int iPrevious = g_tlsMemContext;
        m_iPrevious = iPrevious;
        g_tlsMemContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        int iPrevious = m_iPrevious;
        g_tlsMemContext = iPrevious;
    }
};

} // namespace sad8050

// Sets the thread memory context to 0xb and forwards iArg0 and iArg1 to FUN_00add630 on the Manager returned by FUN_00ad9060.
// @fnv 0x00ad8050
// pdb: BSAudio::Precache | BSAudio.obj | debug, object-file gap fill, medium
// pdb params: aiFormID, aiFlags
// pdb locals: tempMemContext
void BSAudio::ForwardToManager(unsigned int iArg0, unsigned int iArg1)
{
    sad8050::MemContextGuard kGuard(0xb);
    BSAudioManager::GetRandomGenerator().Precache(iArg0, iArg1);
}

namespace fnv_00ad8100 {

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

static inline int GetCurrentMemContext()
{
    return g_tlsData.memContext;
}

static inline void SetCurrentMemContext(int context)
{
    g_tlsData.memContext = context;
}

struct MemContextScope
{
    int oldContext;
    MemContextScope(int newContext)
    {
        oldContext = GetCurrentMemContext();
        g_tlsData.memContext = newContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(oldContext);
    }
};

} // namespace fnv_00ad8100

// Sets memory context 11 and forwards the sound name, flags, and parameter to BSAudioManager::FUN_00add6f0.
// @fnv 0x00ad8100
// src: COMMUNITY 0x00ad8100
// pdb: BSAudio::Precache | BSAudio.obj | debug, call graph, high
// pdb params: apFilenameToCache, aiFlags, apSettingsContext
// pdb locals: tempMemContext
void BSAudio::Precache_00ad8100(unsigned int apFilenameToCache, unsigned int aiFlags, unsigned int apSettingsContext)
{
    fnv_00ad8100::MemContextScope tempMemContext(11);
    BSAudioManager::GetRandomGenerator().BSAudioManager_Precache(apFilenameToCache, aiFlags, apSettingsContext);
}
