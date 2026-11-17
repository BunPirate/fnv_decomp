#pragma once

class NiAVObject;
class NiPoint3;

// Bethesda's sound handle: 12 bytes (Xbox debug PDB Fallout_Release_Beta.pdb; RTTI names it as a template argument).
// Declarations only: a unit whose original inlines a body defines it out of class.
// pdb: class BSSoundHandle, size 0xc, 3 members
class BSSoundHandle
{
public:
    enum ASSUMED_STATE
    {
        ASSUMED_STATE_INITIALIZED = 0,
        ASSUMED_STATE_PLAYING = 1,
        ASSUMED_STATE_STOPPED = 2,
        ASSUMED_STATE_PAUSED = 3,
    };
    typedef void (__cdecl* CompletionCallback)(void*, bool);

    unsigned int iSoundID;   // +0x0
    bool bAssumeSuccess;     // +0x4
    ASSUMED_STATE eState;    // +0x8

    BSSoundHandle();
    BSSoundHandle(unsigned int uiSoundID);
    BSSoundHandle(const BSSoundHandle& kOther);
    ~BSSoundHandle();
    BSSoundHandle& operator=(const BSSoundHandle& kOther);
    bool operator==(unsigned int uiSoundID) const;
    bool operator==(const BSSoundHandle& kOther) const;
    bool operator!=(unsigned int uiSoundID);
    bool operator!=(const BSSoundHandle& kOther) const;

    void Clear();
    bool Play(bool abLoopPlayback);
    bool PlayAfter(unsigned int aiDelay, int aiPlayFlags);
    bool Pause();
    bool Stop();
    bool IsPlaying();
    bool IsValid();
    int GetSoundType();
    float GetVolume();
    bool SetVolume(float fVolume);
    bool SetFrequency(float afNewFrequency);
    bool SetModFrequency(float afNewFrequency);
    bool SetFrequencyVariance(unsigned char aiFreqVariance);
    bool SetBalance(int aiNewBalance);
    bool SetStaticAttenuation(unsigned short usAttenuation);
    int GetDuration();
    bool SetPosition(const NiPoint3& aPosition);
    bool SetPosition(float afX, float afY, float afZ);
    bool SetBeamEnd(const NiPoint3& kPosition);
    bool SetBeamEnd(float afX, float afY, float afZ);
    void SetMinMax(float fMin, float fMax);
    void SetAttenuationCurve(unsigned short aiPt1, unsigned short aiPt2, unsigned short aiPt3, unsigned short aiPt4, unsigned short aiPt5);
    void SetReverbAttenuation(unsigned short aiReverbAtt);
    bool SetOrientation(float afX, float afY, float afZ);
    unsigned int GetID() const;
    void SetObjectToFollow(NiAVObject* pkObject);
    void Seek(unsigned int aiMilliseconds);
    void SetFollowsListener(bool abFollowsListener);
    void SetCompletionCallback(CompletionCallback apfnCallback, void* pvData);
    void SetPlayCallback(CompletionCallback apfnCallback, void* apContext);
    bool Release();
    bool FadeInPlay(unsigned int aiMilliseconds);
    bool FadeOutAndRelease(unsigned int aiMilliseconds);
    bool FadeOut(unsigned int aiMilliseconds);
    void SetTimeConstraints(unsigned char aiStart, unsigned char aiStop);
    void SetSynchStartTime(unsigned int aiStartTime);
    void ClearSynchStartTime();
    void SetPriority(unsigned int aiPriority);
    void SetAssumeSuccess(bool bAssume);
    ASSUMED_STATE QState() const;
};
