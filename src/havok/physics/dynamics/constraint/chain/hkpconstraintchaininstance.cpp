
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkStringPtr.h"
#include "../../../../../../include/hkpAction.h"
#include "../../../../../../include/hkpConstraintChainData.h"
#include "../../../../../../include/hkpConstraintChainInstanceAction.h"
#include "../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../include/hkpConstraintChainInstance.h"
#include "../../../../../../include/hkaAnimation.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryRouter.h"

struct FUN_00c91120
{
    void ExecutePendingOperations();
};
struct FUN_00c91140
{
    void ExecutePendingOperationQueues();
};
struct FUN_00c97510
{
    void ProcessPointer(void*);
};
struct FUN_00cb3da0
{
    static void hkpWorldOperationUtil_removeConstraintFromCriticalLockedIsland(void*, void*);
};
// @fnv 0x00dd0460
// pdb: hkpConstraintChainInstance::entityRemovedCallback | hkpConstraintChainInstance.obj | retail, vtable slot, high
// pdb params: entity
// pdb locals: assertBuf, ostr
void hkpConstraintChainInstance::EntityRemovedCallback(void* entity)
{
    FUN_00c97510* w = *(FUN_00c97510**)((char*)entity + 8);
    ++*(int*)((char*)w + 0x94);
    FUN_00c97510* w2 = (FUN_00c97510*)m_action;
    w->ProcessPointer(w2);
    FUN_00cb3da0::hkpWorldOperationUtil_removeConstraintFromCriticalLockedIsland(w, this);
    if (--*(int*)((char*)w + 0x94) == 0 && !*(char*)((char*)w + 0x9c))
    {
        if (*(int*)((char*)w + 0x8c))
            ((FUN_00c91120*)w)->ExecutePendingOperations();
        if (*(int*)((char*)w + 0xa4) == 1 && *(int*)((char*)w + 0x90))
            ((FUN_00c91140*)w)->ExecutePendingOperationQueues();
    }
}

// hkMemoryRouter is the shared router: GetMonitorStream binds to 0x00c85750, heap is at +0x10.

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T> __forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}

// @fnv 0x00dd04d0
// src: XBOX_RETAIL_PDB 0x00dd04d0
// pdb: hkpConstraintChainInstance::addEntity | hkpConstraintChainInstance.obj | retail, call graph, high
// pdb params: entity
// pdb locals: assertBuf, ostr
void hkpConstraintChainInstance::addEntity(hkpEntity* entity)
{
    int iSlot = m_chainedEntities.m_iElementCount;
    if (iSlot < 2 && m_entities[iSlot] == 0)
    {
        m_entities[iSlot] = entity;
        ((hkReferencedObject*)entity)->addReference();
    }
    m_chainedEntities.pushBack(entity);
    ((hkReferencedObject*)entity)->addReference();
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

// @fnv 0x00dd05c0
// pdb: hkpConstraintChainInstance::~hkpConstraintChainInstance | hkpConstraintChainInstance.obj | retail, upstream name already matches, high
// pdb locals: assertBuf, ostr
hkpConstraintChainInstance::~hkpConstraintChainInstance() throw()
{
    for (int i = 0; i < m_chainedEntities.m_iElementCount; i++)
        ((hkReferencedObject*)m_chainedEntities.m_data[i])->removeReference();
    m_action->removeReference();
}



inline void* hkReferencedObject::operator new(std::size_t nbytes) throw()
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(
        hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
    b->m_memSizeAndFlags = (unsigned short)nbytes;
    return b;
}

inline void hkReferencedObject::operator delete(void* p)
{
    hkReferencedObject* object = static_cast<hkReferencedObject*>(p);
    hkMemoryRouter::getInstance().heap().blockFree(p, object->m_memSizeAndFlags);
}

inline hkpAction::hkpAction() throw()
    : m_world(0), m_island(0), m_userData(0)
{}

inline hkpConstraintChainInstanceAction::hkpConstraintChainInstanceAction(
    hkpConstraintInstance* pkInstance) throw()
    : m_constraintInstance(static_cast<hkpConstraintChainInstance*>(pkInstance))
{}

// @fnv 0x00dd0530
// pdb: hkpConstraintChainInstance::hkpConstraintChainInstance | hkpConstraintChainInstance.obj | retail, call graph (shared callers), high
// pdb params: f
hkpConstraintChainInstance::hkpConstraintChainInstance(hkpConstraintChainData* data)
    : hkpConstraintInstance(1)
{
    m_data = data;
    data->FUN_00c90510();
    m_entities[0] = 0;
    m_entities[1] = 0;
    m_action = new hkpConstraintChainInstanceAction(this);
}
