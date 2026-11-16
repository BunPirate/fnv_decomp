#pragma once

// pdb: structure NavMeshClosedDoorInfo, size 0x8, 2 members
class NavMeshClosedDoorInfo
{
public:
    unsigned int DoorFormID; // src: XBOX_RETAIL_PDB +0x0 (old: m_uiDoorFormID)
    unsigned short iTriangleIndex; // src: XBOX_RETAIL_PDB +0x4 (old: m_usDoorTriangleIndex)
    unsigned char layoutPadding6[2];

    NavMeshClosedDoorInfo();
};
