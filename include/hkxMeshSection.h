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
    hkxVertexBuffer* m_vertexBuffer; // src: XBOX_RETAIL_PDB +0x8 (old: m_pMeshVertexBuffer)
    hkArray<hkxIndexBuffer*> m_indexBuffers; // src: XBOX_RETAIL_PDB +0xc (old: m_kIndexBuffers)
    hkxMaterial* m_material; // src: XBOX_RETAIL_PDB +0x18 (old: m_iMaterialIndex)
    hkArray<hkReferencedObject*> m_userChannels; // src: XBOX_RETAIL_PDB +0x1c (old: m_kUserChannels)
};
