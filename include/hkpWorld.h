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
    hkpSimulation* m_simulation;
    char padC[0x4];
    hkVector4 m_gravity;
    void* m_fixedIsland;
    void* m_fixedRigidBody;
    hkArray<void*> m_activeSimulationIslands;
    hkArray<void*> m_inactiveSimulationIslands;
    hkArray<void*> m_dirtySimulationIslands;
    void* m_maintenanceMgr;
    void* m_memoryWatchDog;
    hkBool m_assertOnRunningOutOfSolverMemory;
    char pad55[0x3];
    void* m_broadPhase;
    void* m_kdTreeManager;
    hkBool m_autoUpdateTree;
    char pad61[0x3];
    void* m_broadPhaseDispatcher;
    void* m_phantomBroadPhaseListener;
    void* m_entityEntityBroadPhaseListener;
    void* m_broadPhaseBorderListener;
    void* m_multithreadedSimulationJobData;
    void* m_collisionInput;
    void* m_collisionFilter;
    void* m_collisionDispatcher;
    void* m_convexListFilter;
    void* m_pendingOperations;
    hkInt32 m_pendingOperationsCount;
    hkInt32 m_pendingBodyOperationsCount;
    hkInt32 m_criticalOperationsLockCount;
    hkInt32 m_criticalOperationsLockCountForPhantoms;
    hkBool m_blockExecutingPendingOperations;
    hkBool m_criticalOperationsAllowed;
    char pad9E[0x2];
    void* m_pendingOperationQueues;
    hkInt32 m_pendingOperationQueueCount;
    hkMultiThreadCheck m_multiThreadCheck;
    hkBool m_processActionsInSingleThread;
    hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
    char padB2[0x2];
    unsigned int m_minDesiredIslandSize;
    void* m_modifyConstraintCriticalSection;
    hkInt32 m_isLocked;
    void* m_islandDirtyListCriticalSection;
    void* m_propertyMasterLock;
    hkBool m_wantSimulationIslands;
    char padC9[0x3];
    hkReal m_snapCollisionToConvexEdgeThreshold;
    hkReal m_snapCollisionToConcaveEdgeThreshold;
    hkBool m_enableToiWeldRejection;
    hkBool m_wantDeactivation;
    hkBool m_shouldActivateOnRigidBodyTransformChange;
    char padD7[0x1];
    hkReal m_deactivationReferenceDistance;
    hkReal m_toiCollisionResponseRotateNormal;
    hkInt32 m_maxSectorsPerCollideTask;
    hkBool m_processToisMultithreaded;
    char padE5[0x3];
    hkInt32 m_maxEntriesPerToiCollideTask;
    hkInt32 m_maxNumToiCollisionPairsSinglethreaded;
    hkInt32 m_simulationType;
    hkReal m_numToisTillAllowedPenetrationSimplifiedToi;
    hkReal m_numToisTillAllowedPenetrationToi;
    hkReal m_numToisTillAllowedPenetrationToiHigher;
    hkReal m_numToisTillAllowedPenetrationToiForced;
    unsigned int m_lastEntityUid;
    unsigned int m_lastIslandUid;
    unsigned int m_lastConstraintUid;
    hkArray<hkpPhantom*> m_phantoms;
    hkArray<void*> m_actionListeners;
    hkArray<void*> m_entityListeners;
    hkArray<void*> m_phantomListeners;
    hkArray<void*> m_constraintListeners;
    hkArray<void*> m_worldDeletionListeners;
    hkArray<void*> m_islandActivationListeners;
    hkArray<void*> m_worldPostSimulationListeners;
    hkArray<void*> m_worldPostIntegrateListeners;
    hkArray<void*> m_worldPostCollideListeners;
    hkArray<void*> m_islandPostIntegrateListeners;
    hkArray<void*> m_islandPostCollideListeners;
    hkArray<void*> m_contactListeners;
    hkArray<void*> m_contactImpulseLimitBreachedListeners;
    void* m_violatedConstraintArray;
    void* m_broadPhaseBorder;
    void* m_collisionCallbackUtil;
    void* m_destructionWorld;
    char pad1C8[0x148];
    hkVector4 m_broadPhaseExtents[2];
    hkInt32 m_broadPhaseNumMarkers;
    hkInt32 m_sizeOfToiEventQueue;
    hkInt32 m_broadPhaseQuerySize;
    hkInt32 m_broadPhaseUpdateSize;
    signed char m_contactPointGeneration;
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
    void hkpWorld_reenableCollisionBetweenEntityPair(hkpEntity* entityA, hkpEntity* entityB);
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
    hkpWorld* hkpWorld_ctor(const hkpWorldCinfo* info, unsigned int sdkversion = 0x111d4) throw();
    void hkpWorld_updateCollisionFilterOnWorld(int updateMode, int updateShapeCollectionFilter) throw();
    void hkpWorld_addPhysicsSystem(hkpPhysicsSystem* sys) throw();
};
