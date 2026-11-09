#pragma once

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class TimeoutTimer
{
public:
    float fStartTime;
    float fTargetTime;

    TimeoutTimer();
    void TESWeightForm_InitializeDataComponent();
    float CombatTimer_GetTargetTime();
    bool CheckTimer() const;
    void __thiscall LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void Start(float t);
    bool Expired();
    void Reset();
    bool IsRunning();
};
