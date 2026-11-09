#pragma once

#include "QueuedKF.h"

// pdb: class QueuedAnimIdle, size 0x40 (here 0x30), bases: QueuedKF, 2 members
class QueuedAnimIdle : public QueuedKF
{
public:
    virtual void OnChildCompletion();
    virtual void ProcessLoadedAnimIdle();
};
