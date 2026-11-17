#pragma once

#include "TESRegionData.h"

class TESFile;
class TESTexture;

// pdb: class TESRegionDataLandscape, size 0xc, bases: TESRegionData, 1 members
class TESRegionDataLandscape : public TESRegionData
{
public:
    TESTexture* m_pLandscapeTexture;

    TESRegionDataLandscape();
    virtual ~TESRegionDataLandscape();
    virtual bool ReadLandscapeData(TESFile* apFile);
    virtual void vf10();
    virtual void vf11();
};
