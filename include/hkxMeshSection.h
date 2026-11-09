#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkxVertexBuffer;
class hkxIndexBuffer;
class hkxMaterial;

// pdb: class hkxMeshSection, size 0x28, bases: hkReferencedObject, 4 members
class hkxMeshSection : public hkReferencedObject
{
public:
    hkxVertexBuffer* m_vertexBuffer;
    hkArray<hkxIndexBuffer*> m_indexBuffers;
    hkxMaterial* m_material;
    hkArray<hkReferencedObject*> m_userChannels;
};
