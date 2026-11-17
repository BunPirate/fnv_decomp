#pragma once

#include "hkStreamWriter.h"
#include "hkArray.h"

class hkCharArray;

// pdb: class hkArrayStreamWriter, size 0x14, bases: hkStreamWriter, 3 members
class hkArrayStreamWriter : public hkStreamWriter
{
public:
    hkArrayStreamWriter(hkCharArray* arr, int ownership);
    virtual ~hkArrayStreamWriter() throw();

    virtual int write(const void* buf, int len);
    virtual void Reset();

    int Seek(int offset, int whence);

    hkArray<char>* m_arr; // src: XBOX_RETAIL_PDB +0x8 (old: m_aiIndexedValues)
    int m_offset;
    int m_ownerShip; // src: XBOX_RETAIL_PDB +0x10 (old: m_ownership)
};
