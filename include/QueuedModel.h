#pragma once

#include "QueuedFileEntry.h"

// pdb: class QueuedModel, size 0x48 (here 0x30), bases: QueuedFileEntry, 5 members
class QueuedModel : public QueuedFileEntry
{
public:
    virtual void GenerateKey() override;
    virtual void DispatchToManager() override;
    virtual void OnChildCompletion() override;
    virtual void vf12();
};
