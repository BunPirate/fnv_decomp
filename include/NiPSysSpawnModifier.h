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

    unsigned short m_usNumSpawnGenerations;
    unsigned char layoutPadding1A[2];
    float m_fPercentageSpawned;
    unsigned short m_usMinNumToSpawn;
    unsigned short m_usMaxNumToSpawn;
    float m_fSpawnSpeedChaos;
    float m_fSpawnDirChaos;
    float m_fLifeSpan;
    float m_fLifeSpanVar;
};
