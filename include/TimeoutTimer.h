#pragma once

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;

class TimeoutTimer
{
public:
    float fStartTime; // src: XBOX_RETAIL_PDB +0x0 (old: m_fStartTime)
    float fTargetTime; // src: XBOX_RETAIL_PDB +0x4 (old: m_fTimeout)

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
