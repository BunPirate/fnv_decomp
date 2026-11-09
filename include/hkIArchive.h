#pragma once

#include "hkReferencedObject.h"

// pdb: class hkIArchive, size 0x10 (here 0xc), bases: hkReferencedObject, 2 members
class hkIArchive : public hkReferencedObject
{
public:
    virtual ~hkIArchive();

    void ReleaseArchiveReader();
    void hkIArchive_readArrayGeneric(void* array, int elemsize, int arraySize);

    hkReferencedObject* m_streamReader;
};
