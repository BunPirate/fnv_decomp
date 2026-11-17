#pragma once

#include "QueuedCharacter.h"

// pdb: class QueuedPlayer, size 0x48 (here 0x28), bases: QueuedCharacter, 0 members
class QueuedPlayer : public QueuedCharacter
{
public:
    void Attach();
};
