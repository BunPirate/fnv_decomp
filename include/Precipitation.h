#pragma once

#include "NiAVObject.h"

class NiNode;
class SkyShaderProperty;
struct PrecipQueuedObject;

// pdb: class Precipitation, size 0x18, 5 members
class Precipitation
{
public:
    Precipitation();
    virtual ~Precipitation();

    void* DestroyIfFlagged(unsigned int flags);
    void InitParent();
    void QueuePrecipitationObject(PrecipQueuedObject* object);

    NiPointer<NiNode> spCurrentPrecipRoot;
    NiPointer<NiNode> spLastPrecipRoot;
    NiNode* pParent;
    float fBirthRate;
    const void* pQueuedModel;

    void Load(const char* apFilename);
    NiAVObject* Precipitation_CreateShaderGeometry(SkyShaderProperty* apParticleSystem, NiAVObject* akWorldTransform);
    void Update(float afSecondsPassed);
    void FlushAll();
};
