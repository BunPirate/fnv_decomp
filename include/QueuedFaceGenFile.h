#pragma once

#include "QueuedFileLoad.h"

// pdb: class QueuedFaceGenFile, size 0x40, bases: QueuedFileLoad, 2 members
class QueuedFaceGenFile : public QueuedFileLoad
{
public:
    virtual ~QueuedFaceGenFile();

    char spFaceGenModel[4];
    char spModelMeshData[4];
};
