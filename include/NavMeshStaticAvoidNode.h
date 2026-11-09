#pragma once

#include "PathingAvoidNode.h"

// pdb: class NavMeshStaticAvoidNode, size 0x28, bases: PathingAvoidNode, 1 members
class NavMeshStaticAvoidNode : public PathingAvoidNode
{
public:
    unsigned short usTriangle;
    unsigned char layoutPadding26[2];

    unsigned short GetShortValueAtOffset24();
    float GetFloatAtOffset1C();
};
