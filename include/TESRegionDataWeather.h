#pragma once

#include "TESRegionData.h"
#include "TESWeatherList.h"

class TESFile;
class TESRegion;

// pdb: class TESRegionDataWeather, size 0x10, bases: TESRegionData, 1 members
class TESRegionDataWeather : public TESRegionData
{
public:
    TESWeatherList weatherList;

    TESRegionDataWeather();
    TESRegionDataWeather(const TESRegionDataWeather& other);
    virtual ~TESRegionDataWeather();
    virtual void LoadWeatherData(TESFile* apFile, TESRegion* apRegion);
    virtual void Save();
    virtual TESRegionData* Clone();
    virtual TESRegionData* CopyFrom(const TESRegionData* apSrc);
    virtual void SetFromData(const TESRegionData* apRegionData, unsigned int aiTotalBlending);
    virtual bool IsValid();
};
