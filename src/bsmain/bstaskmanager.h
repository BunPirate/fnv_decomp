#ifndef FNV_BSTASKMANAGER_H
#define FNV_BSTASKMANAGER_H
#include "bstaskmanager_types.h"

// @fnv 0x00440540
// pdb: IOTask::IOTask | ModelLoader.obj | debug, upstream name already matches, high
// pdb params: aePriority
IOTask::IOTask(IO_TASK_PRIORITY aePriority) : BSTask<__int64>()
{
    SetIOTaskPriority(aePriority);
}
#endif
