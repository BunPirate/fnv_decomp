#pragma once

#include "PathingAvoidNode.h"

// pdb: class NavMeshStaticAvoidNode, size 0x28, bases: PathingAvoidNode, 1 members
class NavMeshStaticAvoidNode : public PathingAvoidNode
{
public:
    unsigned short usTriangle; // src: XBOX_RETAIL_PDB +0x24 (old: m_usTriangleID)
    unsigned char layoutPadding26[2];

    unsigned short GetShortValueAtOffset24();
    float GetFloatAtOffset1C();
};
