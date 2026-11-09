#pragma once

#include "SkyObject.h"
#include "NiPointer.h"

// pdb: class Stars, size 0x10, bases: SkyObject, 2 members
class Stars : public SkyObject
{
public:
    Stars();
    virtual ~Stars();
    void Initialize(NiNode* apSkyRoot) override;
    void Update(Sky* pWeatherSky, float fSeconds) override;

    void LoadGeometry(const char* apFilename);

    NiPointer<NiNode> spStars;
    float fAlpha;
};
