#pragma once

#include "QueuedKF.h"

// pdb: class QueuedReplacementKF, size 0x40 (here 0x30), bases: QueuedKF, 2 members
class QueuedReplacementKF : public QueuedKF
{
public:
    virtual void Finish();
    virtual bool GetDescription(char* description, unsigned int bufferSize);

    void QueuedKF_Finish();
    void IncrementCounter();
    bool BSTask_int64_GetTaskCanceled();
    void Finish_0043e940();
    bool GetDescription_0043ea00(char* apDescription, unsigned int aiBufferSize);
};
