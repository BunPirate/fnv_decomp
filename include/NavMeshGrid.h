#pragma once

#include "NiPoint3.h"

template <class T, unsigned int Growth> class BSSimpleArray;
class NavMeshTriList;

// pdb: structure NavMeshGrid, size 0x28, 6 members
class NavMeshGrid
{
public:
    unsigned int iGridSize;
    float fColumnSectionLen;
    float fRowSectionLen;
    NiPoint3 GridBoundsMin;
    NiPoint3 GridBoundsMax;
    BSSimpleArray<unsigned short, 1024>* GridData;

    NavMeshGrid();
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    int GetCellIndex(const NiPoint3& arPos);
    NavMeshTriList* NavMeshGrid_GetTriangleArray(unsigned int auiCol, unsigned int auiRow);
    void GetTriangleData(const NiPoint3& aLoc, NavMeshTriList** apArray);
    void GetTriangleData(const NiPoint3& aLoc, NavMeshTriList*& apArray);
    void GetTriangleData(const NiPoint3* aLoc, NavMeshTriList** apArray);
    void InitFromPoints(const NiPoint3& arMin, const NiPoint3& arMax, unsigned int auiCount);
    unsigned int Modelloader_GetReferencedThis();
    void SetTriangleData(unsigned short aiTriangle, unsigned int aiColumn, unsigned int aiRow);
    NiPoint3 NavMeshGrid_GetGridPosition(unsigned int auiCol, unsigned int auiRow);
    void NavMeshGrid_Clear();
    void CopyTo_0069dd50(NavMeshGrid* apGrid);
    void CopyTo_0069dd50(NavMeshGrid* apGrid) const;
};
