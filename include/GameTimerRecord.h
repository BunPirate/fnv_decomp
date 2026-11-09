#pragma once

class GameTimerRecord
{
public:
    unsigned char cDisableCounter;
    unsigned char layoutPadding1;
    unsigned short layoutPadding2;
    float fClamp;
    float fClampRemainder;
    float fDelta;
    float fDeltaUnmodified;
    unsigned int iLastTime;
    unsigned int iFirstTime;
    bool bUseGlobalTimeMultiplierTarget;
    bool bZeroDelta;
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
