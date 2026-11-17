#pragma once

#include "BaseFormComponent.h"

class QueuedFile;

enum IO_TASK_PRIORITY;

// pdb: class BGSPreloadable, size 0x4, bases: BaseFormComponent, 0 members
class BGSPreloadable : public BaseFormComponent
{
public:
    BGSPreloadable();

    virtual void QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file);
};
