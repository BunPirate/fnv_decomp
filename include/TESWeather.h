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
    bool Load(TESFile* file);
    TESTexture1024* GetCloudTexture(int);
    float GetCloudLayerSpeed(int, float, float);
    bool IsRainy();
    float GetWeatherData(int data, float maximum, float minimum);
    unsigned char GetWeatherDataRaw(int);

    TESTexture1024 cloudTexture[4];
    unsigned char ucCloudLayerSpeed[4];
    unsigned int uiCloudColorData[4][6];
    TESModel precipNIF;
    unsigned char ucWeatherData[15];
    unsigned char layoutPaddingEF[1];
    float fFogData[6];
    unsigned int uiColorData[10][6];
    TESWeather__WeatherSoundList soundList;
    float fHDRData[14];
    ImageSpaceModifierParameterData pImageSpaceParameterMods[2];
    int iNumCloudLayers;
};
