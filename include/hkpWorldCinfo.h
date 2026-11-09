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
    hkVector4 m_gravity;
    hkInt32 m_broadPhaseQuerySize;
    hkReal m_contactRestingVelocity;
    hkInt8 m_broadPhaseBorderBehaviour;
    hkBool m_mtPostponeAndSortBroadPhaseBorderCallbacks;
    char pad2A[0x6];
    hkAabb m_broadPhaseWorldAabb;
    hkBool m_useKdTree;
    hkBool m_useMultipleTree;
    hkInt8 m_treeUpdateType;
    hkBool m_autoUpdateKdTree;
    hkReal m_collisionTolerance;
    hkpCollisionFilter* m_collisionFilter;
    hkpConvexListFilter* m_convexListFilter;
    hkReal m_expectedMaxLinearVelocity;
    hkInt32 m_sizeOfToiEventQueue;
    hkReal m_expectedMinPsiDeltaTime;
    hkWorldMemoryAvailableWatchDog* m_memoryWatchDog;
    hkInt32 m_broadPhaseNumMarkers;
    hkInt8 m_contactPointGeneration;
    hkBool m_allowToSkipConfirmedCallbacks;
    char pad76[0x2];
    hkReal m_solverTau;
    hkReal m_solverDamp;
    hkInt32 m_solverIterations;
    hkInt32 m_solverMicrosteps;
    hkReal m_maxConstraintViolation;
    hkBool m_forceCoherentConstraintOrderingInSolver;
    char pad8D[0x3];
    hkReal m_snapCollisionToConvexEdgeThreshold;
    hkReal m_snapCollisionToConcaveEdgeThreshold;
    hkBool m_enableToiWeldRejection;
    hkBool m_enableDeprecatedWelding;
    char pad9A[0x2];
    hkReal m_iterativeLinearCastEarlyOutDistance;
    hkInt32 m_iterativeLinearCastMaxIterations;
    hkUint8 m_deactivationNumInactiveFramesSelectFlag0;
    hkUint8 m_deactivationNumInactiveFramesSelectFlag1;
    hkUint8 m_deactivationIntegrateCounter;
    hkBool m_shouldActivateOnRigidBodyTransformChange;
    hkReal m_deactivationReferenceDistance;
    hkReal m_toiCollisionResponseRotateNormal;
    hkInt32 m_maxSectorsPerCollideTask;
    hkBool m_processToisMultithreaded;
    char padB5[0x3];
    hkInt32 m_maxEntriesPerToiCollideTask;
    hkInt32 m_maxNumToiCollisionPairsSinglethreaded;
    hkReal m_numToisTillAllowedPenetrationSimplifiedToi;
    hkReal m_numToisTillAllowedPenetrationToi;
    hkReal m_numToisTillAllowedPenetrationToiHigher;
    hkReal m_numToisTillAllowedPenetrationToiForced;
    hkBool m_enableDeactivation;
    hkInt8 m_simulationType;
    hkBool m_enableSimulationIslands;
    char padD3[0x1];
    hkUint32 m_minDesiredIslandSize;
    hkBool m_processActionsInSingleThread;
    hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
    char padDA[0x2];
    hkReal m_frameMarkerPsiSnap;
    hkBool m_fireCollisionCallbacks;
    char padE1[0xF];
};
