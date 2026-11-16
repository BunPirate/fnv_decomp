#pragma once

class NavMeshEdgeData;

class NavMeshTriangleHandle
{
public:
    unsigned short m_usIndex;

    void Set(const NavMeshEdgeData&);
};

// pdb: structure NavMeshPOVData, size 0x4, 2 members
class NavMeshPOVData
{
public:
    NavMeshTriangleHandle Edge1; // src: XBOX_RETAIL_PDB +0x0 (old: m_kFirstEdge)
    NavMeshTriangleHandle Edge2; // src: XBOX_RETAIL_PDB +0x2 (old: m_kSecondEdge)
};
