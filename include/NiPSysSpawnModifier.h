#pragma once

#include "NiPSysModifier.h"

class ParticleSystemX;

// pdb: class NiPSysSpawnModifier, size 0x34, bases: NiPSysModifier, 8 members
class NiPSysSpawnModifier : public NiPSysModifier
{
public:
    virtual void LoadBinary(NiStream& kStream);
    virtual void SpawnChildParticles(float fTime, float fCollisionTime, unsigned int uiIndex,
                                    NiPSysData* pkData);
    virtual void UpdateSpawning(float fCurrentTime, float fSpawnTime, unsigned short usOldIndex,
                               ParticleSystemX* pkSystem);

    unsigned short m_usNumSpawnGenerations; // src: XBOX_RETAIL_PDB +0x18 (old: m_usSpawnGenerationCount)
    unsigned char layoutPadding1A[2];
    float m_fPercentageSpawned; // src: XBOX_RETAIL_PDB +0x1c (old: m_fSpawnPercentage)
    unsigned short m_usMinNumToSpawn; // src: XBOX_RETAIL_PDB +0x20 (old: m_usMinimumParticlesToSpawn)
    unsigned short m_usMaxNumToSpawn; // src: XBOX_RETAIL_PDB +0x22 (old: m_usMaximumParticlesToSpawn)
    float m_fSpawnSpeedChaos; // src: XBOX_RETAIL_PDB +0x24 (old: m_fSpawnedSpeedChaos)
    float m_fSpawnDirChaos; // src: XBOX_RETAIL_PDB +0x28 (old: m_fSpawnDirectionChaos)
    float m_fLifeSpan; // src: XBOX_RETAIL_PDB +0x2c (old: m_fYValue)
    float m_fLifeSpanVar; // src: XBOX_RETAIL_PDB +0x30 (old: m_fLifeSpanVariation)
};
