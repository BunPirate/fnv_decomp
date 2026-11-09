#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "TESWeatherList.h"
#include "TESTexture.h"

// pdb: class TESClimate, size 0x58, bases: TESForm, 4 members
class TESClimate : public TESForm
{
public:
    TESClimate();
    virtual ~TESClimate();
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    void MakeDefault();
    bool Load(TESFile* apFile);
    void SetMoonPhaseDays(unsigned int days);
    void SetUsesMasser(bool value);
    void SetUsesSecunda(bool value);
    unsigned char GetTransTime(int a1);

    TESModel m_kStarsModel;
    TESWeatherList weatherList;
    TESTexture m_kSunTextures[2];
    unsigned char m_ucTimeSettings[6];
    unsigned char layoutPadding56[2];
};
