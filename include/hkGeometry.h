#pragma once

#include <stddef.h>
#include "hkaAnimation.h"
#include "hkVector4.h"

// pdb: structure hkGeometry, size 0x18, 2 members
class hkGeometry
{
public:
    struct Triangle
    {
        int m_a; // src: XBOX_RETAIL_PDB +0x0 (old: m_kPointA)
        int m_b; // src: XBOX_RETAIL_PDB +0x4 (old: m_kPointB)
        int m_c; // src: XBOX_RETAIL_PDB +0x8 (old: m_iThirdValue)
        int m_material; // src: XBOX_RETAIL_PDB +0xc (old: m_iMaterialIndex)

        void set(int a, int b, int c, int material = -1);
    };

    hkArray<hkVector4> m_vertices; // src: XBOX_RETAIL_PDB +0x0 (old: m_kVertices)
    hkArray<Triangle> m_triangles; // src: XBOX_RETAIL_PDB +0xc (old: m_uiTriangleCount)

    hkGeometry();
    ~hkGeometry();

    static void* operator new(size_t size) throw();
};
