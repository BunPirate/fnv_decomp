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
        int m_a;
        int m_b;
        int m_c;
        int m_material;

        void set(int a, int b, int c, int material = -1);
    };

    hkArray<hkVector4> m_vertices;
    hkArray<Triangle> m_triangles;

    hkGeometry();
    ~hkGeometry();

    static void* operator new(size_t size) throw();
};
