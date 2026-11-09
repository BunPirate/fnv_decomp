#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

// pdb: class hkxIndexBuffer, size 0x2c, bases: hkReferencedObject, 5 members
class hkxIndexBuffer : public hkReferencedObject
{
public:
    enum IndexType
    {
        INDEX_TYPE_INVALID = 0,
        INDEX_TYPE_TRI_LIST = 1,
        INDEX_TYPE_TRI_STRIP = 2,
        INDEX_TYPE_TRI_FAN = 3,
        INDEX_TYPE_MAX_ID = 4
    };

    hkInt8 m_indexType;
    hkInt8 unk09;
    hkInt16 unk0A;
    hkArray<hkUint16> m_indices16;
    hkArray<hkUint32> m_indices32;
    hkUint32 m_vertexBaseOffset;
    hkUint32 m_length;

    int GetPrimitiveCount() const;
    bool GetTriangleIndices(unsigned int offset, unsigned int& a, unsigned int& b, unsigned int& c) const;
};
