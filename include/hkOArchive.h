#pragma once

#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkStreamWriter.h"

// pdb: class hkOArchive, size 0x10, bases: hkReferencedObject, 2 members
class hkOArchive : public hkReferencedObject
{
public:
    hkStreamWriter* m_writer;
    hkBool m_byteSwap;

    hkOArchive(hkStreamWriter* writer, hkBool byteSwap);
    virtual ~hkOArchive() throw();

    void WriteRaw(const void* data, int size);
    void WriteInt(unsigned int value);
    void WriteUint32(unsigned int u);
    void WriteUint8(unsigned char value);
    // 0x00d60900: writeArrayGeneric(&i, 2, 1) (0x00d60600 = WriteSwapped here); Havok 7.1 hkOArchive::write16.
    void write16(short i);
    void WriteUint64(unsigned __int64 value);
    void WriteInt64(int low, int high);
    void WriteSwapped(const void* data, unsigned int size, unsigned int elementCount);
    void WriteArray(const void* data, unsigned int elementCount);
    void WriteBinaryData(void* data, int size, int elementCount);
};
