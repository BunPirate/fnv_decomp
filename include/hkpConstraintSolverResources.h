#pragma once

#include "hkStepInfo.h"

class hkpSolverInfo;
class hkpConstraintQueryIn;
class hkpVelocityAccumulator;
class hkpSolverSumVelocities;

// pdb: structure hkpConstraintSolverResources, size 0x50, 13 members
class hkpConstraintSolverResources
{
public:
    struct BufferState
    {
        char* m_pRayStart;
        char* m_kRayEnd;
        char* m_pTileTemplate;
        char* m_pValues;
    };

    const hkStepInfo* m_stepInfo; // src: XBOX_RETAIL_PDB +0x0 (old: m_pStepInfo)
    hkpSolverInfo* m_solverInfo; // src: XBOX_RETAIL_PDB +0x4 (old: m_pSolverInfo)
    hkpConstraintQueryIn* m_constraintQueryInput; // src: XBOX_RETAIL_PDB +0x8 (old: m_pConstraintQueryIn)
    hkpVelocityAccumulator* m_accumulators; // src: XBOX_RETAIL_PDB +0xc (old: m_pVelocityAccumulatorA)
    hkpVelocityAccumulator* m_accumulatorsEnd; // src: XBOX_RETAIL_PDB +0x10 (old: m_pVelocityAccumulatorB)
    hkpVelocityAccumulator* m_accumulatorsCurrent; // src: XBOX_RETAIL_PDB +0x14 (old: m_pVelocityAccumulatorC)
    union
    {
        char* m_pBufferA;
        hkpSolverSumVelocities* m_sumVelocities;
    };
    char* m_accumulatorsBackupEnd; // src: XBOX_RETAIL_PDB +0x1c (old: m_pBufferB)
    BufferState m_schemas[3]; // src: XBOX_RETAIL_PDB +0x20 (old: m_akBufferStates)
};
