#pragma once

#include "QueuedFile.h"

// pdb: class QueuedHead, size 0x38 (here 0x28), bases: QueuedFile, 3 members
class QueuedHead : public QueuedFile
{
public:
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void DispatchToManager();
    virtual void OnChildCompletion();

    bool GetQueuedHeadDescription(char* apDescription, unsigned int aiBufferSize);
};
