#pragma once

#include "hkIArchive.h"

class hkVector4;
class hkTransform;
class hkGeometry;
class hkDisplayGeometry;

// pdb: class hkDisplaySerializeIStream, size 0x10 (here 0xc), bases: hkIArchive, 0 members
class hkDisplaySerializeIStream : public hkIArchive
{
public:
    virtual ~hkDisplaySerializeIStream();

    void hkIArchive_readArrayGeneric(void* array, int elemsize, int arraySize);
    void readTransform(hkTransform* t);
    void readTransform(hkTransform& t);
    void readQuadVector4(hkVector4& v);
    void readGeometry(hkGeometry* g);
    void UpdateFields_00ddada0(hkDisplayGeometry*& geometry);

    signed char readInt8();
    int readInt32();
    float readFloat32();
    void ReadVector4(hkVector4& v);
    void ReadTransform(hkTransform& t);
    void ReadGeometry(hkGeometry* g);
};

