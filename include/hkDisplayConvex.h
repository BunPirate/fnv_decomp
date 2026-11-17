#pragma once

#include "hkDisplayGeometry.h"

class hkGeometry;

// pdb: class hkDisplayConvex, size 0x60, bases: hkDisplayGeometry, 0 members
class hkDisplayConvex : public hkDisplayGeometry
{
public:
    hkGeometry* m_pSourceGeometry;

    hkDisplayConvex(hkGeometry* geom);
};
