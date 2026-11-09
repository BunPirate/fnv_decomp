#ifndef BSSCRAPARRAY_H
#define BSSCRAPARRAY_H

#include "bsscraparray_decls.h"
template <>
// @fnv 0x0087d1b0
// pdb: BSSimpleArray<ActorHavokSyncData,1024>::operator[] | TaskQueueInterface.obj | debug, object-file run extension, low
// pdb params: aiIndex
ScrapArrayWithBase<NiPointer<NiAVObject>, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = MemoryManager_Instance()->GetGeneralAllocator();
    BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(0, false);
}
template <>
// @fnv 0x009789e0
// pdb: BSScrapArray<Actor *,1024>::BSScrapArray<Actor *,1024> | ProcessLists.obj | retail, object-file run extension, low
ScrapArrayWithBase<Animation*, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = MemoryManager_Instance()->GetGeneralAllocator();
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
}
#endif
