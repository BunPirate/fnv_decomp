// fallout_shared/pathfinding/navmesh.h: defines NavMesh::GetNavMeshData
#ifndef FNV_NAVMESH_H
#define FNV_NAVMESH_H

#include "navmesh_decls.h"
// @fnv 0x00558220
// pdb: NavMesh::GetCenter | TESObjectCELL.obj | debug, call graph, medium
// pdb params: apTriangle
// pdb locals: v5, val, ptri, v2, v4, v1, v3
NiPoint3 NavMesh::GetNavMeshData(unsigned short m_usTriangleID)
{
    NavMeshTriangle* pTriangle = GetTriangle(m_usTriangleID);
    {
        NiPoint3 Center = GetVertex_0068f0a0(pTriangle->GetVert_005582d0(0));
        Center += GetVertex_0068f0a0(pTriangle->GetVert_005582d0(1));
        Center += GetVertex_0068f0a0(pTriangle->GetVert_005582d0(2));
        Center *= DAT_0102f200;
        return Center;
    }
}
#endif
