#pragma once

#include "QueuedFileEntry.h"

// pdb: class QueuedTexture, size 0x38 (here 0x30), bases: QueuedFileEntry, 2 members
class QueuedTexture : public QueuedFileEntry
{
public:
    virtual unsigned char GetFileIndex() override;
};
