#pragma once

#include "NiPoint3.h"
#include "BSSimpleArray.h"

// pdb: class NavMeshBounds, size 0x38, 4 members
class NavMeshBounds
{
public:
    // RTTI BSSimpleArray<NavMeshBounds::NavMeshBoundsTriangle,1024> (vftable 0x0106b28c); 6 bytes, GetAt 0x0069ccf0
    // scales the index by 6 and 0x0069c070 reads three vertex indices from it
    struct NavMeshBoundsTriangle
    {
        unsigned short Vertices, b, c; // src: XBOX_RETAIL_PDB +0x0 (old: a)
    };

    NiPoint3 BoundingBoxMin; // src: XBOX_RETAIL_PDB +0x0 (old: min)
    NiPoint3 BoundingBoxMax; // src: XBOX_RETAIL_PDB +0xc (old: max)
    BSSimpleArray<NavMeshBoundsTriangle, 1024> Triangles; // src: XBOX_RETAIL_PDB +0x18 (old: triangles)
    // BSSimpleArray<NiPoint3,1024> (RTTI vftable 0x0101e114): 12-byte elements (0x006a1440, CopyTo 0x0069cfe0), the
    // vertices 0x0069c070 indexes; src: COMMUNITY (JIP NavMeshBounds pointArr at +0x28)
    BSSimpleArray<NiPoint3, 1024> Vertices; // src: XBOX_RETAIL_PDB +0x28 (old: vertices)

    NavMeshBounds();
    ~NavMeshBounds();
    void CopyTo(NavMeshBounds* apDestBounds);
    NiPoint3 DistanceFromPointToBounds(const NiPoint3& aPoint);
    bool ContainsPoint(const NiPoint3& point);
};
