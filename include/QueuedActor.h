#pragma once

#include "QueuedReference.h"

// pdb: class QueuedActor, size 0x40 (here 0x28), bases: QueuedReference, 0 members
class QueuedActor : public QueuedReference
{
public:
    void QueuedReference_QueueModels();
    void QueueDismemberedLimbLoads();
};
