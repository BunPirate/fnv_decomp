#pragma once

#include "QueuedFileLoad.h"

// pdb: class QueuedFaceGenFile, size 0x40, bases: QueuedFileLoad, 2 members
class QueuedFaceGenFile : public QueuedFileLoad
{
public:
    virtual ~QueuedFaceGenFile();

    char spFaceGenModel[4]; // src: XBOX_RETAIL_PDB +0x38 (old: m_kObject)
    char spModelMeshData[4]; // src: XBOX_RETAIL_PDB +0x3c (old: m_pMesh)
};
