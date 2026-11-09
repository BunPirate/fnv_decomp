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

    NiPointer<NiGeometry> spClouds[4];
    NiPointer<NiTexture> spTransTexture[4];
    NiColor pColors[4];
    unsigned short usNumLayers;
    bool bForceUpdate;
};
