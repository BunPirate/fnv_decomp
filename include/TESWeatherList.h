#pragma once

#include "BSSimpleList.h"

class TESFile;
class TESForm;
class WeatherEntry;

// A list of WeatherEntry (8 bytes, src: XBOX_PDB size): the constructor 0x005822c0 runs the list constructor 0x0096a2d0
// on +0, then ClearWeatherSounds.
// pdb: class TESWeatherList, size 0x8, bases: BSSimpleList<WeatherEntry *>, 0 members
class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
public:
    TESWeatherList();
    ~TESWeatherList();

    void FlushList();
    void CopyWeatherList(const TESWeatherList*, bool);
    bool TESWeatherList_CompareComponent(TESWeatherList*);
    void TESWeatherList_Save(unsigned int);
    static void LoadWeatherListChunk(TESWeatherList* apWeatherList, TESFile* apFile, TESForm* pForm);
};
