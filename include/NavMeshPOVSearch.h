#pragma once

#include "AStarSearch.h"

class NavMeshPOVSearchNode;
class NavMeshPOVSearchLink;
class Sphere;
class SphereTangents;

#include "ANGLE_DIRECTION.h"

// pdb: class NavMeshPOVSearch, size 0x20f8 (here 0x4), bases: AStarSearch<NavMeshPOVSearchNode, 10 members
class NavMeshPOVSearch : public AStarSearch<NavMeshPOVSearchNode, NavMeshPOVSearchLink>
{
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();

    static int FindSphereTangents(const Sphere&, const Sphere&, ANGLE_DIRECTION, SphereTangents&);
};
