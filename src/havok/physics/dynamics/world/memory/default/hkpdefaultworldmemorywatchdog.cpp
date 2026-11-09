
// src/havok/physics/dynamics/world/memory/default/hkpdefaultworldmemorywatchdog.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/memory/default/hkpdefaultworldmemorywatchdog.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkBoolResult.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// The getter at 0x00e48260 reads the same +0x08 memory limit used by ProcessList at 0x00e48300.
class WatchdogReclaimer
{
  public:
    int unk00;
    int unk04;
    int m_memoryLimit;
    int GetMemoryLimit();
    void ProcessList(hkpWorld* world);
};

// @fnv 0x00e48260
int WatchdogReclaimer::GetMemoryLimit()
{
    return m_memoryLimit;
}

// The call at 0x00e48270 passes two arguments to 0x00c91620; the shared world method declares one.
struct WatchdogCallback
{
    void ProcessTarget(void** source, int value);
};

// The callback shim reads a callback at +0x18 and an indirect value at +0x48 in this state record.
struct WatchdogState
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    WatchdogCallback* callback18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    int* value48;
};

// @fnv 0x00e48270
// pdb: hkpDefaultWorldMemoryWatchDog::reduceConstraintsInIsland | hkpDefaultWorldMemoryWatchDog.obj | retail, vtable slot, high
// pdb params: island, solverBufferSize
void __stdcall NotifyWatchdogCallback(WatchdogState* island, int solverBufferSize)
{
    island->callback18->ProcessTarget(reinterpret_cast<void**>(&island), *island->value48);
}

// The original allocator invokes its bool-returning allocation check through vtable slot +0x24.
__forceinline bool hkMemoryAllocator::canAllocTotal(int bytes)
{
    typedef bool (__thiscall *AllocationCheck)(hkMemoryAllocator*, int);
    return (*reinterpret_cast<AllocationCheck**>(this))[9](this, bytes);
}


// This island view uses a world pointer at +0x18; the shared island declares it at +0x0c.
struct EntityRemovalIsland
{
    int unk00[6];
    hkpWorld* m_world;
    int unk1C[11];
    hkpEntity** m_entities;
    int m_numEntities;
};

// @fnv 0x00e48290
// src: HAVOK_LIB 0x00e48290
// pdb: hkpDefaultWorldMemoryWatchDog::removeObjectsFromIsland | hkpDefaultWorldMemoryWatchDog.obj | retail, upstream name already matches, high
// pdb params: island, currentAutoRemoveLevel, freeHeapMemoryRequested, maxFoundAutoRemoveLevelOut
void __cdecl hkpDefaultWorldMemoryWatchDog_removeObjectsFromIsland(EntityRemovalIsland* island, int currentAutoRemoveLevel, int freeHeapMemoryRequested, int* maxFoundAutoRemoveLevelOut)
{
    for (int i = island->m_numEntities - 1; i >= 0; i--)
    {
        hkpEntity* entity = island->m_entities[i];
        int iPriority = entity->m_autoRemoveLevel;
        if (iPriority >= currentAutoRemoveLevel)
        {
            island->m_world->ProcessTarget(reinterpret_cast<hkpRigidBody*>(entity));
            if (!reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()).canAllocTotal(freeHeapMemoryRequested))
                return;
        }
        else
        {
            *maxFoundAutoRemoveLevelOut = (*maxFoundAutoRemoveLevelOut > iPriority) ? *maxFoundAutoRemoveLevelOut : iPriority;
        }
    }
}

// Remove entities by descending auto-remove level until the heap can satisfy the memory limit.
// @fnv 0x00e48300
// pdb: hkpDefaultWorldMemoryWatchDog::freeHeapMemoryTillRequestedAmountIsAvailable | hkpDefaultWorldMemoryWatchDog.obj | retail, vtable slot, high
// pdb params: world
// pdb locals: maxFoundAutoRemoveLevel, assertBuf, ostr
void WatchdogReclaimer::ProcessList(hkpWorld* world)
{
    int bytes = m_memoryLimit;
    int iFlags = 0x7f;
    do
    {
        int iOut = 0;
        int i = world->m_activeSimulationIslands.m_iElementCount - 1;
        while (i >= -world->m_inactiveSimulationIslands.m_iElementCount)
        {
            if (i >= world->m_activeSimulationIslands.m_iElementCount)
            {
                i = world->m_activeSimulationIslands.m_iElementCount - 1;
                if (i < -world->m_inactiveSimulationIslands.m_iElementCount)
                    return;
            }
            EntityRemovalIsland* island;
            if (i >= 0)
                island = static_cast<EntityRemovalIsland*>(world->m_activeSimulationIslands.m_data[i]);
            else
                island = static_cast<EntityRemovalIsland*>(world->m_inactiveSimulationIslands.m_data[-i - 1]);
            hkpDefaultWorldMemoryWatchDog_removeObjectsFromIsland(island, iFlags, bytes, &iOut);
            if (reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap()).canAllocTotal(bytes))
                return;
            i--;
        }
        iFlags = iOut;
    } while (iFlags > 0);
}
