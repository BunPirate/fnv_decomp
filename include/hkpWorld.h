#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkVector4.h"
#include "hkMultiThreadCheck.h"
#include "hkBool.h"
#include "hkaAnimation.h"

class hkpSimulation;
class hkpSimulationIsland;
class hkpPhantom;
class hkpCollisionDispatcher;
class hkpPhysicsSystem;
class hkpEntity;
class hkpRigidBody;
class hkpUnaryAction;
class hkpWorldCinfo;
class hkBoolH;
class hkBoolResult;

// pdb: class hkpWorld, size 0x350, bases: hkReferencedObject, 84 members
class hkpWorld : public hkReferencedObject
{
  public:
    enum ReintegrationRecollideMode
    {
        RR_MODE_REINTEGRATE = 1,
        RR_MODE_RECOLLIDE_BROADPHASE = 2,
        RR_MODE_RECOLLIDE_NARROWPHASE = 4,
        RR_MODE_ALL = 7
    };
    enum MtAccessChecking
    {
        MT_ACCESS_CHECKING_ENABLED = 0,
        MT_ACCESS_CHECKING_DISABLED = 1
    };
    enum CachedAabbUpdate
    {
        SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS = 0,
        SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS = 1
    };
    hkpSimulation* m_simulation; // src: XBOX_RETAIL_PDB +0x8 (old: m_pSimulation)
    char padC[0x4];
    hkVector4 m_gravity; // src: XBOX_RETAIL_PDB +0x10 (old: m_kGravity)
    void* m_fixedIsland; // src: XBOX_RETAIL_PDB +0x20 (old: m_pFixedIsland)
    void* m_fixedRigidBody; // src: XBOX_RETAIL_PDB +0x24 (old: m_pFixedRigidBody)
    hkArray<void*> m_activeSimulationIslands; // src: XBOX_RETAIL_PDB +0x28 (old: m_kActiveSimulationIslands)
    hkArray<void*> m_inactiveSimulationIslands; // src: XBOX_RETAIL_PDB +0x34 (old: m_kInactiveSimulationIslands)
    hkArray<void*> m_dirtySimulationIslands; // src: XBOX_RETAIL_PDB +0x40 (old: m_kDirtySimulationIslands)
    void* m_maintenanceMgr; // src: XBOX_RETAIL_PDB +0x4c (old: m_pMaintenanceManager)
    void* m_memoryWatchDog; // src: XBOX_RETAIL_PDB +0x50 (old: m_pMemoryWatchDog)
    hkBool m_assertOnRunningOutOfSolverMemory; // src: XBOX_RETAIL_PDB +0x54 (old: m_bAssertOnRunningOutOfSolverMemory)
    char pad55[0x3];
    void* m_broadPhase; // src: XBOX_RETAIL_PDB +0x58 (old: m_pJobSemaphore)
    void* m_kdTreeManager; // src: XBOX_RETAIL_PDB +0x5c (old: m_pKdTreeManager)
    hkBool m_autoUpdateTree; // src: XBOX_RETAIL_PDB +0x60 (old: m_bUseKdTree)
    char pad61[0x3];
    void* m_broadPhaseDispatcher; // src: XBOX_RETAIL_PDB +0x64 (old: m_pBroadPhaseDispatcher)
    void* m_phantomBroadPhaseListener; // src: XBOX_RETAIL_PDB +0x68 (old: m_pPhantomBroadPhaseListener)
    void* m_entityEntityBroadPhaseListener; // src: XBOX_RETAIL_PDB +0x6c (old: m_pEntityEntityBroadPhaseListener)
    void* m_broadPhaseBorderListener; // src: XBOX_RETAIL_PDB +0x70 (old: m_pBroadPhaseBorderListener)
    void* m_multithreadedSimulationJobData; // src: XBOX_RETAIL_PDB +0x74 (old: m_pMultithreadedSimulationJobData)
    void* m_collisionInput; // src: XBOX_RETAIL_PDB +0x78 (old: m_pCollisionInput)
    void* m_collisionFilter; // src: XBOX_RETAIL_PDB +0x7c (old: m_pCollisionFilter)
    void* m_collisionDispatcher; // src: XBOX_RETAIL_PDB +0x80 (old: m_pDispatcher)
    void* m_convexListFilter; // src: XBOX_RETAIL_PDB +0x84 (old: m_pConvexListCollisionFilter)
    void* m_pendingOperations; // src: XBOX_RETAIL_PDB +0x88 (old: m_pPendingOperations)
    hkInt32 m_pendingOperationsCount; // src: XBOX_RETAIL_PDB +0x8c (old: m_iPendingOperationCount)
    hkInt32 m_pendingBodyOperationsCount; // src: XBOX_RETAIL_PDB +0x90 (old: m_iQueuedOperationCount)
    hkInt32 m_criticalOperationsLockCount; // src: XBOX_RETAIL_PDB +0x94 (old: m_iCriticalOperationsLockCount)
    hkInt32 m_criticalOperationsLockCountForPhantoms; // src: XBOX_RETAIL_PDB +0x98 (old: m_iCriticalOperationsLockCountForPhantoms)
    hkBool m_blockExecutingPendingOperations; // src: XBOX_RETAIL_PDB +0x9c (old: m_bBlockExecutingPendingOperations)
    hkBool m_criticalOperationsAllowed; // src: XBOX_RETAIL_PDB +0x9d (old: m_bBlockExecutingPendingOperationQueues)
    char pad9E[0x2];
    void* m_pendingOperationQueues; // src: XBOX_RETAIL_PDB +0xa0 (old: m_pPendingOperationQueues)
    hkInt32 m_pendingOperationQueueCount; // src: XBOX_RETAIL_PDB +0xa4 (old: m_iPendingOperationQueueCount)
    hkMultiThreadCheck m_multiThreadCheck; // src: XBOX_RETAIL_PDB +0xa8 (old: m_kMultiThreadCheck)
    hkBool m_processActionsInSingleThread; // src: XBOX_RETAIL_PDB +0xb0 (old: m_bProcessActionsInSingleThread)
    hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob; // src: XBOX_RETAIL_PDB +0xb1 (old: m_bAllowUnconstrainedIslandJob)
    char padB2[0x2];
    unsigned int m_minDesiredIslandSize; // src: XBOX_RETAIL_PDB +0xb4 (old: m_uiMinDesiredIslandSize)
    void* m_modifyConstraintCriticalSection; // src: XBOX_RETAIL_PDB +0xb8 (old: m_pModifyConstraintCriticalSection)
    hkInt32 m_isLocked; // src: XBOX_RETAIL_PDB +0xbc (old: m_iIsLocked)
    void* m_islandDirtyListCriticalSection; // src: XBOX_RETAIL_PDB +0xc0 (old: m_pIslandDirtyListCriticalSection)
    void* m_propertyMasterLock; // src: XBOX_RETAIL_PDB +0xc4 (old: m_pPropertyMasterLock)
    hkBool m_wantSimulationIslands; // src: XBOX_RETAIL_PDB +0xc8 (old: m_bWantSimulationIslands)
    char padC9[0x3];
    hkReal m_snapCollisionToConvexEdgeThreshold; // src: XBOX_RETAIL_PDB +0xcc (old: m_fSnapCollisionToConvexEdgeThreshold)
    hkReal m_snapCollisionToConcaveEdgeThreshold; // src: XBOX_RETAIL_PDB +0xd0 (old: m_fSnapCollisionToConcaveEdgeThreshold)
    hkBool m_enableToiWeldRejection; // src: XBOX_RETAIL_PDB +0xd4 (old: m_bEnableToiWeldRejection)
    hkBool m_wantDeactivation; // src: XBOX_RETAIL_PDB +0xd5 (old: m_bWantDeactivation)
    hkBool m_shouldActivateOnRigidBodyTransformChange; // src: XBOX_RETAIL_PDB +0xd6 (old: m_bActivateOnBodyTransformChange)
    char padD7[0x1];
    hkReal m_deactivationReferenceDistance; // src: XBOX_RETAIL_PDB +0xd8 (old: m_fDeactivationReferenceDistance)
    hkReal m_toiCollisionResponseRotateNormal; // src: XBOX_RETAIL_PDB +0xdc (old: m_fToiCollisionResponseRotateNormal)
    hkInt32 m_maxSectorsPerCollideTask; // src: XBOX_RETAIL_PDB +0xe0 (old: m_iMaxSectorsPerMidphaseTask)
    hkBool m_processToisMultithreaded; // src: XBOX_RETAIL_PDB +0xe4 (old: m_bProcessToisMultithreaded)
    char padE5[0x3];
    hkInt32 m_maxEntriesPerToiCollideTask; // src: XBOX_RETAIL_PDB +0xe8 (old: m_iMaxSectorsPerNarrowphaseTask)
    hkInt32 m_maxNumToiCollisionPairsSinglethreaded; // src: XBOX_RETAIL_PDB +0xec (old: m_iMaxEntriesPerMidphaseToiTask)
    hkInt32 m_simulationType; // src: XBOX_RETAIL_PDB +0xf0 (old: m_iMaxEntriesPerNarrowphaseToiTask)
    hkReal m_numToisTillAllowedPenetrationSimplifiedToi; // src: XBOX_RETAIL_PDB +0xf4 (old: m_fSimplifiedToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToi; // src: XBOX_RETAIL_PDB +0xf8 (old: m_fToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToiHigher; // src: XBOX_RETAIL_PDB +0xfc (old: m_fHigherToiPenetrationThreshold)
    hkReal m_numToisTillAllowedPenetrationToiForced; // src: XBOX_RETAIL_PDB +0x100 (old: m_fForcedToiPenetrationThreshold)
    unsigned int m_lastEntityUid; // src: XBOX_RETAIL_PDB +0x104 (old: m_uiLastEntityUid)
    unsigned int m_lastIslandUid; // src: XBOX_RETAIL_PDB +0x108 (old: m_uiLastIslandUid)
    unsigned int m_lastConstraintUid; // src: XBOX_RETAIL_PDB +0x10c (old: m_uiLastConstraintUid)
    hkArray<hkpPhantom*> m_phantoms; // src: XBOX_RETAIL_PDB +0x110 (old: m_kPhantoms)
    hkArray<void*> m_actionListeners; // src: XBOX_RETAIL_PDB +0x11c (old: m_kActionListeners)
    hkArray<void*> m_entityListeners; // src: XBOX_RETAIL_PDB +0x128 (old: m_kEntityListenerArray)
    hkArray<void*> m_phantomListeners; // src: XBOX_RETAIL_PDB +0x134 (old: m_kPhantomListeners)
    hkArray<void*> m_constraintListeners; // src: XBOX_RETAIL_PDB +0x140 (old: m_kConstraintListeners)
    hkArray<void*> m_worldDeletionListeners; // src: XBOX_RETAIL_PDB +0x14c (old: m_kWorldDeletionListeners)
    hkArray<void*> m_islandActivationListeners; // src: XBOX_RETAIL_PDB +0x158 (old: m_kIslandActivationListeners)
    hkArray<void*> m_worldPostSimulationListeners; // src: XBOX_RETAIL_PDB +0x164 (old: m_kWorldPostSimulationListeners)
    hkArray<void*> m_worldPostIntegrateListeners; // src: XBOX_RETAIL_PDB +0x170 (old: m_kWorldPostIntegrateListeners)
    hkArray<void*> m_worldPostCollideListeners; // src: XBOX_RETAIL_PDB +0x17c (old: m_kWorldPostCollideListeners)
    hkArray<void*> m_islandPostIntegrateListeners; // src: XBOX_RETAIL_PDB +0x188 (old: m_kIslandPostIntegrateListeners)
    hkArray<void*> m_islandPostCollideListeners; // src: XBOX_RETAIL_PDB +0x194 (old: m_kIslandPostCollideListeners)
    hkArray<void*> m_contactListeners; // src: XBOX_RETAIL_PDB +0x1a0 (old: m_kContactListeners)
    hkArray<void*> m_contactImpulseLimitBreachedListeners; // src: XBOX_RETAIL_PDB +0x1ac (old: m_kContactImpulseLimitBreachedListeners)
    void* m_violatedConstraintArray; // src: XBOX_RETAIL_PDB +0x1b8 (old: m_pViolatedConstraintArray)
    void* m_broadPhaseBorder; // src: XBOX_RETAIL_PDB +0x1bc (old: m_pBroadPhaseBorder)
    void* m_collisionCallbackUtil; // src: XBOX_RETAIL_PDB +0x1c0 (old: m_pBroadPhaseQueryCache)
    void* m_destructionWorld; // src: XBOX_RETAIL_PDB +0x1c4 (old: m_pBroadPhaseRegionData)
    char pad1C8[0x148];
    hkVector4 m_broadPhaseExtents[2]; // src: XBOX_RETAIL_PDB +0x310 (old: m_kBroadPhaseAabb)
    hkInt32 m_broadPhaseNumMarkers; // src: XBOX_RETAIL_PDB +0x330 (old: m_iBroadPhaseNumMarkers)
    hkInt32 m_sizeOfToiEventQueue;
    hkInt32 m_broadPhaseQuerySize; // src: XBOX_RETAIL_PDB +0x338 (old: m_iBroadPhaseQuerySize)
    hkInt32 m_broadPhaseUpdateSize; // src: XBOX_RETAIL_PDB +0x33c (old: m_iBroadPhaseNumObjects)
    signed char m_contactPointGeneration; // src: XBOX_RETAIL_PDB +0x340 (old: m_iContactPointGeneration)
    char pad341[0xF];

    hkpWorld(const hkpWorldCinfo* info) throw();
    static void* __cdecl operator new(std::size_t size) throw();

    hkpCollisionDispatcher* getCollisionDispatcher() const;
    void lockCriticalOperations();
    void unlockCriticalOperations();
    void unlockAndAttemptToExecutePendingOperations();
    void attemptToExecutePendingOperations(bool executeBodyOperations = true);
  private:
    void ExecutePendingOperations();
    void ExecutePendingOperationQueues();

  public:
    void allowCriticalOperations(hkBool allow);
    void allowCriticalOperations(hkBoolH allow);
    void lock();
    void unlock();
    hkpPhysicsSystem* getWorldAsOneSystem() const;
    void* getUserData() const;
    void reenableCollisionBetweenEntityPair(hkpEntity* entityA, hkpEntity* entityB);
    hkBoolResult ProcessTarget(hkpRigidBody* entity);
    void RemoveActionFromEntity(hkpUnaryAction* action, hkpEntity* entity);
    void __cdecl AddCollisionShape(void* entity) throw();

    float hkpWorld_getCurrentTime();
    float hkpWorld_getCurrentPsiTime();
    void nullsub_5(hkpSimulationIsland* island);
    void __thiscall nullsub_6();
    void FUN_00c91120();
    void UpdateFields_00c91140();
    void hkpWorld_queueOperation(void* operation);
    void* hkpWorld_addEntity(hkpRigidBody* entity, int initialActivationState);
    void hkpWorld_attachActionToEntity(hkpUnaryAction* action, hkpEntity* entity);
    int __thiscall hkpWorld_getMemoryWatchDog();
    void hkpWorld_addPhantom(hkpPhantom* phantom);
    void hkpWorld_addWorldPostSimulationListener(void* worldListener);
    void hkpWorld_addWorldDeletionListener(void* worldListener);
    void hkpWorld_updateCollisionFilterOnEntity(void* entity, void* collection, int updateShape);
    hkpWorld* hkpWorld_hkpWorld(const hkpWorldCinfo* info, unsigned int sdkversion = 0x111d4) throw();
    void hkpWorld_updateCollisionFilterOnWorld(int updateMode, int updateShapeCollectionFilter) throw();
    void hkpWorld_addPhysicsSystem(hkpPhysicsSystem* sys) throw();
};
