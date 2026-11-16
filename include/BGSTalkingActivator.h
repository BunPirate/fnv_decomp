#pragma once

#include "TESObjectACTI.h"

class BGSVoiceType;
class RadioStationRef;
class RefStub;
class TESObjectREFR;
template <class T> class BSSimpleList;

// pdb: class BGSTalkingActivator, size 0x98, bases: TESObjectACTI, 2 members
class BGSTalkingActivator : public TESObjectACTI
{
public:
    BGSTalkingActivator();

    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void InitItem(void);

    virtual bool IsRadioStationObject() const;
    virtual bool GetReflectedByAutoWater() const;

    void ResetFormData();
    bool Load(TESFile* apFile);
    void SetRadioTemplate(TESSound* apSound);
    void SetVoiceType(BGSVoiceType* apVoice);
    bool IsRadioStation();
    bool IsRadioStation() const;
    TESObjectREFR* GetTempRef() const;
    RefStub* GetTempRef();

    static bool IsRadioStation(TESForm* apForm, unsigned int aiData);
    static void AddRadioStation(TESObjectREFR* apRef);
    static void FindRadioStations(TESObjectREFR* apListenRef,
                                  BSSimpleList<TESObjectREFR*>* apOutList,
                                  BSSimpleList<float>* apDistancesList);
    static void FindRadioStations(TESObjectREFR* apListenRef,
                                  BSSimpleList<RadioStationRef*>* apOutList,
                                  BSSimpleList<float>* apDistancesList);
    static BSSimpleList<TESObjectREFR*> ms_kRadioStations;

    TESObjectREFR* pTempRef;    // 0x90 // src: XBOX_RETAIL_PDB +0x90 (old: m_pTempRef)
    BGSVoiceType* pVoiceType; // 0x94 // src: XBOX_RETAIL_PDB +0x94 (old: m_kFactionList)
};
