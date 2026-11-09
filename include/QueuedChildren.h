#pragma once

#include "ShadowSceneLight.h"

class QueuedFile;

// pdb: class QueuedChildren, size 0x14, bases: BSSimpleArray<NiPointer<QueuedFile>, 1 members
class QueuedChildren : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
public:
    virtual ~QueuedChildren();
    virtual NiPointer<QueuedFile>* _Allocate(unsigned int count);
    virtual void _Deallocate(NiPointer<QueuedFile>* items);
    virtual NiPointer<QueuedFile>* _Reallocate(NiPointer<QueuedFile>* items, unsigned int count);

    void AddFinishedChild();
    unsigned int GetChildCountFinished();

    volatile unsigned int iNumChildrenFinished;
};
