#pragma once

#include "TESRegionData.h"

class TESFile;
class TESRegionGrassObjectList;

// pdb: class TESRegionDataGrass, size 0xc, bases: TESRegionData, 1 members
class TESRegionDataGrass : public TESRegionData
{
public:
    TESRegionGrassObjectList* m_pObjectList;

    TESRegionDataGrass();
    virtual ~TESRegionDataGrass();
    virtual bool ReadGrassData(TESFile* apFile);
    virtual TESRegionGrassObjectList* vf10();
};
