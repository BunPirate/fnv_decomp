#pragma once

#include "TESForm.h"
#include "BaseFormComponent.h"
#include "TESTexture1024.h"
#include "TESModel.h"
#include "TESWeather__WeatherSoundList.h"
#include "ImageSpaceModifierParameterData.h"

class TESImageSpaceModifier;

template <unsigned int Count>
class TESImageSpaceModifiableCountForm : public BaseFormComponent
{
public:
    TESImageSpaceModifiableCountForm();
    void InitItem(TESForm* form);

    TESImageSpaceModifier* m_pImageSpaceModifier[Count];
};

// pdb: class TESWeather, size 0x36c, bases: TESForm, TESImageSpaceModifiableCountForm<6>, 11 members
struct TESWeather : public TESForm, public TESImageSpaceModifiableCountForm<6>
{
public:
    class WeatherSound;

    TESWeather();
    virtual ~TESWeather();

    virtual void ClearData();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();

    void ResetFormData();
    void MakeDefault();
    bool Load(TESFile* apFile);
    TESTexture1024* GetCloudTexture(int);
    float GetCloudLayerSpeed(int, float, float);
    bool IsRainy();
    float GetWeatherData(int data, float maximum, float minimum);
    unsigned char GetWeatherDataRaw(int);

    TESTexture1024 cloudTexture[4]; // src: XBOX_RETAIL_PDB +0x34 (old: m_kCloudLayerTextures)
    unsigned char ucCloudLayerSpeed[4]; // src: XBOX_RETAIL_PDB +0x64 (old: m_aucCloudLayerSpeeds)
    unsigned int uiCloudColorData[4][6]; // src: XBOX_RETAIL_PDB +0x68 (old: m_auiCloudLayerColors)
    TESModel precipNIF; // src: XBOX_RETAIL_PDB +0xc8 (old: m_kWeatherModel)
    unsigned char ucWeatherData[15]; // src: XBOX_RETAIL_PDB +0xe0 (old: m_aucWeatherFlags)
    unsigned char layoutPaddingEF[1];
    float fFogData[6]; // src: XBOX_RETAIL_PDB +0xf0 (old: m_afFogDistances)
    unsigned int uiColorData[10][6]; // src: XBOX_RETAIL_PDB +0x108 (old: m_auiWeatherColors)
    TESWeather__WeatherSoundList soundList;
    float fHDRData[14]; // src: XBOX_RETAIL_PDB +0x200 (old: m_afHdrParameters)
    ImageSpaceModifierParameterData pImageSpaceParameterMods[2]; // src: XBOX_RETAIL_PDB +0x238 (old: m_akImageSpaceModifierParameters)
    int iNumCloudLayers; // src: XBOX_RETAIL_PDB +0x368 (old: m_iCloudLayerCount)
};
