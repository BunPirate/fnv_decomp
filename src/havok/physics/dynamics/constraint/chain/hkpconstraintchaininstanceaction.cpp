
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkpConstraintChainInstance.h"
#include "../../../../../../include/hkpConstraintChainInstanceAction.h"

// @fnv 0x00e063e0
// src: HAVOK_LIB 0x00e063e0
// pdb: hkpConstraintChainInstanceAction::entityRemovedCallback | hkpConstraintChainInstanceAction.obj | debug, upstream name already matches, high
// pdb params: entity
void __fastcall hkpConstraintChainInstanceAction_entityRemovedCallback(hkpConstraintChainInstanceAction* self, void* unusedEdx, int arg0)
{
    self->m_constraintInstance->vf04((void*)arg0);
}

// @fnv 0x00e063c0
// src: COMMUNITY 0x00e063c0
// pdb: hkpConstraintChainInstanceAction::applyAction | hkpConstraintChainInstanceAction.obj | debug, vtable slot, medium
// pdb params: stepInfo
// pdb locals: assertBuf, ostr
void __stdcall nullsub_82(int)
{}

// @fnv 0x00e063d0
// src: GUESS 0x00e063d0 (confidence: high)
// pdb: hkpConstraintChainInstanceAction::clone | hkpConstraintChainInstanceAction.obj | debug, vtable slot, medium
// pdb params: newEntities, newPhantoms
// pdb locals: assertBuf, ostr
int __stdcall hkpConstraintChainInstanceAction_ReturnZero(int arg0, int arg1)
{
    return 0;
}

struct FnvAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* AllocateMemoryBlock(int* bytes);
    virtual void ReleaseBlock(void* ptr, int bytes);
};
struct FnvMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FnvAllocator* allocator;
};
extern "C" FnvMemoryRouter* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00e063f0
// pdb: hkpConstraintChainInstanceAction::getEntities | hkpConstraintChainInstanceAction.obj | retail, vtable slot, high
// pdb params: entitiesOut
void __fastcall CopyEntityArray(hkpConstraintChainInstanceAction* self, void* unusedEdx, hkArray<hkpEntity*>* output)
{
    hkArray<hkpEntity*>* source = &self->m_constraintInstance->m_chainedEntities;
    FnvAllocator* allocator = hkMemoryRouter_getInstance()->allocator;
    int capacity = output->m_iCapacityState & 0x3fffffff;
    if (capacity < source->m_iElementCount)
    {
        if (!(output->m_iCapacityState & 0x80000000))
            allocator->ReleaseBlock(output->m_data, capacity * 4);
        int bytes = source->m_iElementCount * 4;
        output->m_data = (hkpEntity**)allocator->AllocateMemoryBlock(&bytes);
        output->m_iCapacityState = bytes / 4;
    }
    int count = source->m_iElementCount;
    output->m_iElementCount = count;
    hkpEntity** dest = output->m_data;
    hkpEntity** from = source->m_data;
    for (int i = 0; i < count; ++i)
        dest[i] = from[i];
}
