#pragma once

#include "NiPoint3.h"

template <class T, unsigned int Growth> class BSSimpleArray;
class NavMeshTriList;

// pdb: structure NavMeshGrid, size 0x28, 6 members
class NavMeshGrid
{
public:
    unsigned int iGridSize; // src: XBOX_RETAIL_PDB +0x0 (old: m_uiGridIndex)
    float fColumnSectionLen; // src: XBOX_RETAIL_PDB +0x4 (old: m_fFirstGridValue)
    float fRowSectionLen; // src: XBOX_RETAIL_PDB +0x8 (old: NavMeshPointEntry)
    NiPoint3 GridBoundsMin; // src: XBOX_RETAIL_PDB +0xc (old: IndexedPointRecord)
    NiPoint3 GridBoundsMax; // src: XBOX_RETAIL_PDB +0x18 (old: IndexedPointData)
    BSSimpleArray<unsigned short, 1024>* GridData; // src: XBOX_RETAIL_PDB +0x24 (old: TESFileRecordLoader)

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
    void Clear_0069d2d0();
    void CopyTo_0069dd50(NavMeshGrid* apGrid);
    void CopyTo_0069dd50(NavMeshGrid* apGrid) const;
};
