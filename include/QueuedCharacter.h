#pragma once

#include "QueuedActor.h"

// pdb: class QueuedCharacter, size 0x48 (here 0x28), bases: QueuedActor, 2 members
class QueuedCharacter : public QueuedActor
{
public:
    void Attach();
};
