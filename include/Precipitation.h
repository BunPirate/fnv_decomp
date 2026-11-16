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

    NiPointer<NiNode> spCurrentPrecipRoot; // src: XBOX_RETAIL_PDB +0x4 (old: m_pPrecipitationNode)
    NiPointer<NiNode> spLastPrecipRoot; // src: XBOX_RETAIL_PDB +0x8 (old: m_pPreviousNode)
    NiNode* pParent;
    float fBirthRate; // src: XBOX_RETAIL_PDB +0x10 (old: fEmissionRate)
    const void* pQueuedModel; // src: XBOX_RETAIL_PDB +0x14 (old: m_pPrecipitationData)

    void Load(const char* apFilename);
    NiAVObject* Precipitation_CreateShaderGeometry(SkyShaderProperty* apParticleSystem, NiAVObject* akWorldTransform);
    void Update(float afSecondsPassed);
    void FlushAll();
};
