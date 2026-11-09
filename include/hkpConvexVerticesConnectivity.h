#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

typedef unsigned short hkUint16;
typedef unsigned char hkUint8;

// pdb: class hkpConvexVerticesConnectivity, size 0x20, bases: hkReferencedObject, 2 members
class hkpConvexVerticesConnectivity : public hkReferencedObject
{
public:
    virtual void vf03();

    hkArray<hkUint16> m_vertexIndices;
    hkArray<hkUint8> m_numVerticesPerFace;
};
