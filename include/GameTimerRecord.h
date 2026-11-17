#pragma once

class GameTimerRecord
{
public:
    unsigned char cDisableCounter; // src: XBOX_RETAIL_PDB +0x0 (old: m_ucFirstTimerByte)
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    float fClamp; // src: XBOX_RETAIL_PDB +0x4 (old: m_fFirstTimerValue)
    float fClampRemainder; // src: XBOX_RETAIL_PDB +0x8 (old: m_fSecondTimerValue)
    float fDelta; // src: XBOX_RETAIL_PDB +0xc (old: fTimeSinceScaleStart)
    float fDeltaUnmodified; // src: XBOX_RETAIL_PDB +0x10 (old: m_fFourthTimerValue)
    unsigned int iLastTime; // src: XBOX_RETAIL_PDB +0x14 (old: m_uiFirstTimerValue)
    unsigned int iFirstTime; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiSecondTimerValue)
    bool bUseGlobalTimeMultiplierTarget; // src: XBOX_RETAIL_PDB +0x1c (old: m_bFirstTimerFlag)
    bool bZeroDelta; // src: XBOX_RETAIL_PDB +0x1d (old: m_bSecondTimerFlag)
    unsigned short layoutPadding1E;

    void Update();
    void Update(unsigned int);
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetTime() const;
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    void SetGlobalTimeMultiplier(float, bool);
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    int GetSection();
    void BSTimer_Disable();
};
