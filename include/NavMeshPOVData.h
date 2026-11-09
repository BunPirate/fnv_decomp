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
    NavMeshTriangleHandle Edge1;
    NavMeshTriangleHandle Edge2;
};
