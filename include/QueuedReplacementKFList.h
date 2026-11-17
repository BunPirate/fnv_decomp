#pragma once

#include "QueuedFile.h"

// pdb: class QueuedReplacementKFList, size 0x38 (here 0x28), bases: QueuedFile, 3 members
class QueuedReplacementKFList : public QueuedFile
{
public:
    void OnChildCompletion() override;

    void CheckFinished();
};
