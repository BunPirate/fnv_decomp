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

    const hkStepInfo* m_stepInfo;
    hkpSolverInfo* m_solverInfo;
    hkpConstraintQueryIn* m_constraintQueryInput;
    hkpVelocityAccumulator* m_accumulators;
    hkpVelocityAccumulator* m_accumulatorsEnd;
    hkpVelocityAccumulator* m_accumulatorsCurrent;
    union
    {
        char* m_pBufferA;
        hkpSolverSumVelocities* m_sumVelocities;
    };
    char* m_accumulatorsBackupEnd;
    BufferState m_schemas[3];
};
