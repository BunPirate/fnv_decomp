#pragma once

#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkAabb.h"
#include "hkBool.h"
#include "hkpCollisionFilter.h"

class hkWorldMemoryAvailableWatchDog;
class hkpConvexListFilter;
struct ClassMemberDescriptor;

typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef int hkInt32;
typedef unsigned int hkUint32;

// pdb: class hkpWorldCinfo, size 0xf0, bases: hkReferencedObject, 54 members
class hkpWorldCinfo : public hkReferencedObject
{
  public:
    static const ClassMemberDescriptor Members[];

    enum SolverType
    {
        SOLVER_TYPE_INVALID = 0,
        SOLVER_TYPE_2ITERS_SOFT = 1,
        SOLVER_TYPE_2ITERS_MEDIUM = 2,
        SOLVER_TYPE_2ITERS_HARD = 3,
        SOLVER_TYPE_4ITERS_SOFT = 4,
        SOLVER_TYPE_4ITERS_MEDIUM = 5,
        SOLVER_TYPE_4ITERS_HARD = 6,
        SOLVER_TYPE_8ITERS_SOFT = 7,
        SOLVER_TYPE_8ITERS_MEDIUM = 8,
        SOLVER_TYPE_8ITERS_HARD = 9,
        SOLVER_TYPE_MAX_ID = 10
    };
    enum SimulationType
    {
        SIMULATION_TYPE_INVALID = 0,
        SIMULATION_TYPE_DISCRETE = 1,
        SIMULATION_TYPE_CONTINUOUS = 2,
        SIMULATION_TYPE_MULTITHREADED = 3
    };
    enum ContactPointGeneration
    {
        CONTACT_POINT_ACCEPT_ALWAYS = 0,
        CONTACT_POINT_REJECT_DUBIOUS = 1,
        CONTACT_POINT_REJECT_MANY = 2
    };
    enum BroadPhaseBorderBehaviour
    {
        BROADPHASE_BORDER_ASSERT = 0,
        BROADPHASE_BORDER_FIX_ENTITY = 1,
        BROADPHASE_BORDER_REMOVE_ENTITY = 2,
        BROADPHASE_BORDER_DO_NOTHING = 3
    };
    enum TreeUpdateType
    {
        REBUILD_ACTIVE = 0,
        REBUILD_ALL = 1
    };
    char pad8[0x8];
    hkVector4 m_gravity; // src: XBOX_RETAIL_PDB +0x10 (old: m_kGravity)
    hkInt32 m_broadPhaseQuerySize; // src: XBOX_RETAIL_PDB +0x20 (old: m_iBroadPhaseQuerySize)
    hkReal m_contactRestingVelocity; // src: XBOX_RETAIL_PDB +0x24 (old: m_fContactRestingVelocity)
    hkInt8 m_broadPhaseBorderBehaviour; // src: XBOX_RETAIL_PDB +0x28 (old: m_iBroadPhaseBorderBehaviour)
    hkBool m_mtPostponeAndSortBroadPhaseBorderCallbacks; // src: XBOX_RETAIL_PDB +0x29 (old: m_bPostponeAndSortBorderCallbacks)
    char pad2A[0x6];
    hkAabb m_broadPhaseWorldAabb; // src: XBOX_RETAIL_PDB +0x30 (old: m_kBroadPhaseWorldAabb)
    hkBool m_useKdTree; // src: XBOX_RETAIL_PDB +0x50 (old: m_bUseKdTree)
    hkBool m_useMultipleTree; // src: XBOX_RETAIL_PDB +0x51 (old: m_bUseMultipleTree)
    hkInt8 m_treeUpdateType; // src: XBOX_RETAIL_PDB +0x52 (old: m_iTreeUpdateType)
    hkBool m_autoUpdateKdTree; // src: XBOX_RETAIL_PDB +0x53 (old: m_bAutoUpdateKdTree)
    hkReal m_collisionTolerance; // src: XBOX_RETAIL_PDB +0x54 (old: m_fCollisionTolerance)
    hkpCollisionFilter* m_collisionFilter; // src: XBOX_RETAIL_PDB +0x58 (old: m_pCollisionFilter)
    hkpConvexListFilter* m_convexListFilter; // src: XBOX_RETAIL_PDB +0x5c (old: m_pConvexListCollisionFilter)
    hkReal m_expectedMaxLinearVelocity; // src: XBOX_RETAIL_PDB +0x60 (old: m_fExpectedMaxLinearVelocity)
    hkInt32 m_sizeOfToiEventQueue;
    hkReal m_expectedMinPsiDeltaTime; // src: XBOX_RETAIL_PDB +0x68 (old: m_fExpectedMinPsiDeltaTime)
    hkWorldMemoryAvailableWatchDog* m_memoryWatchDog; // src: XBOX_RETAIL_PDB +0x6c (old: m_pMemoryWatchDog)
    hkInt32 m_broadPhaseNumMarkers; // src: XBOX_RETAIL_PDB +0x70 (old: m_iBroadPhaseNumMarkers)
    hkInt8 m_contactPointGeneration; // src: XBOX_RETAIL_PDB +0x74 (old: m_iContactPointGeneration)
    hkBool m_allowToSkipConfirmedCallbacks; // src: XBOX_RETAIL_PDB +0x75 (old: m_bAllowToSkipConfirmedCallbacks)
    char pad76[0x2];
    hkReal m_solverTau; // src: XBOX_RETAIL_PDB +0x78 (old: m_fSolverTau)
    hkReal m_solverDamp; // src: XBOX_RETAIL_PDB +0x7c (old: m_fSolverDamp)
    hkInt32 m_solverIterations; // src: XBOX_RETAIL_PDB +0x80 (old: m_iSolverIterations)
    hkInt32 m_solverMicrosteps; // src: XBOX_RETAIL_PDB +0x84 (old: m_iSolverMicrosteps)
    hkReal m_maxConstraintViolation; // src: XBOX_RETAIL_PDB +0x88 (old: m_fMaxConstraintViolation)
    hkBool m_forceCoherentConstraintOrderingInSolver; // src: XBOX_RETAIL_PDB +0x8c (old: m_bForceCoherentConstraintOrderingInSolver)
    char pad8D[0x3];
    hkReal m_snapCollisionToConvexEdgeThreshold; // src: XBOX_RETAIL_PDB +0x90 (old: m_fSnapCollisionToConvexEdgeThreshold)
    hkReal m_snapCollisionToConcaveEdgeThreshold; // src: XBOX_RETAIL_PDB +0x94 (old: m_fSnapCollisionToConcaveEdgeThreshold)
    hkBool m_enableToiWeldRejection; // src: XBOX_RETAIL_PDB +0x98 (old: m_bEnableToiWeldRejection)
    hkBool m_enableDeprecatedWelding; // src: XBOX_RETAIL_PDB +0x99 (old: m_bEnableDeprecatedWelding)
    char pad9A[0x2];
    hkReal m_iterativeLinearCastEarlyOutDistance; // src: XBOX_RETAIL_PDB +0x9c (old: m_fValue)
    hkInt32 m_iterativeLinearCastMaxIterations; // src: XBOX_RETAIL_PDB +0xa0 (old: m_iValue)
    hkUint8 m_deactivationNumInactiveFramesSelectFlag0; // src: XBOX_RETAIL_PDB +0xa4 (old: m_uiDeactivationNumInactiveFramesSelectFlag0)
    hkUint8 m_deactivationNumInactiveFramesSelectFlag1; // src: XBOX_RETAIL_PDB +0xa5 (old: m_uiDeactivationNumInactiveFramesSelectFlag1)
    hkUint8 m_deactivationIntegrateCounter; // src: XBOX_RETAIL_PDB +0xa6 (old: m_ucDeactivationIntegrateCounter)
    hkBool m_shouldActivateOnRigidBodyTransformChange; // src: XBOX_RETAIL_PDB +0xa7 (old: m_bActivateOnBodyTransformChange)
    hkReal m_deactivationReferenceDistance; // src: XBOX_RETAIL_PDB +0xa8 (old: m_fDeactivationReferenceDistance)
    hkReal m_toiCollisionResponseRotateNormal; // src: XBOX_RETAIL_PDB +0xac (old: m_fToiCollisionResponseRotateNormal)
    hkInt32 m_maxSectorsPerCollideTask; // src: XBOX_RETAIL_PDB +0xb0 (old: m_iMaxSectorsPerMidphaseTask)
    hkBool m_processToisMultithreaded; // src: XBOX_RETAIL_PDB +0xb4 (old: m_bProcessToisMultithreaded)
    char padB5[0x3];
    hkInt32 m_maxEntriesPerToiCollideTask; // src: XBOX_RETAIL_PDB +0xb8 (old: m_iMaxSectorsPerNarrowphaseTask)
    hkInt32 m_maxNumToiCollisionPairsSinglethreaded; // src: XBOX_RETAIL_PDB +0xbc (old: m_iMaxEntriesPerMidphaseToiTask)
    hkReal m_numToisTillAllowedPenetrationSimplifiedToi; // src: XBOX_RETAIL_PDB +0xc0 (old: m_fSimplifiedToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToi; // src: XBOX_RETAIL_PDB +0xc4 (old: m_fToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToiHigher; // src: XBOX_RETAIL_PDB +0xc8 (old: m_fHigherToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToiForced; // src: XBOX_RETAIL_PDB +0xcc (old: m_fForcedToiPenetrationThreshold)
    hkBool m_enableDeactivation; // src: XBOX_RETAIL_PDB +0xd0 (old: m_bRigidBodyFlag)
    hkInt8 m_simulationType; // src: XBOX_RETAIL_PDB +0xd1 (old: m_iMaxEntriesPerNarrowphaseToiTask)
    hkBool m_enableSimulationIslands; // src: XBOX_RETAIL_PDB +0xd2 (old: m_bEnableSimulationIslands)
    char padD3[0x1];
    hkUint32 m_minDesiredIslandSize; // src: XBOX_RETAIL_PDB +0xd4 (old: m_uiMinDesiredIslandSize)
    hkBool m_processActionsInSingleThread; // src: XBOX_RETAIL_PDB +0xd8 (old: m_bProcessActionsInSingleThread)
    hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob; // src: XBOX_RETAIL_PDB +0xd9 (old: m_bAllowUnconstrainedIslandJob)
    char padDA[0x2];
    hkReal m_frameMarkerPsiSnap; // src: XBOX_RETAIL_PDB +0xdc (old: m_fFrameMarkerPsiSnap)
    hkBool m_fireCollisionCallbacks; // src: XBOX_RETAIL_PDB +0xe0 (old: m_bFireCollisionCallbacks)
    char padE1[0xF];
};
