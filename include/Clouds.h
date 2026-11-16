#pragma once

#include "SkyObject.h"
#include "NiColor.h"

class NiGeometry;
class NiTexture;

// pdb: class Clouds, size 0x5c, bases: SkyObject, 5 members
class Clouds : public SkyObject
{
public:
    virtual ~Clouds();
    virtual void Initialize(NiNode*);
    virtual void Update(Sky*, float);

    int GetOffset58();
    NiColor& GetPointAt(int);
    void SetCloudCount(int);
    void ClearCloudLayers();
    void ForceTransTextureUpdate();

    NiPointer<NiGeometry> spClouds[4]; // src: XBOX_RETAIL_PDB +0x8 (old: m_pCloudLayerGeometry)
    NiPointer<NiTexture> spTransTexture[4]; // src: XBOX_RETAIL_PDB +0x18 (old: m_pCloudLayerTexture)
    NiColor pColors[4];
    unsigned short usNumLayers; // src: XBOX_RETAIL_PDB +0x58 (old: m_usCloudCount)
    bool bForceUpdate;
};
