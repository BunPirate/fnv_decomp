#pragma once

// pdb: structure NavMeshClosedDoorInfo, size 0x8, 2 members
class NavMeshClosedDoorInfo
{
public:
    unsigned int DoorFormID;
    unsigned short iTriangleIndex;
    unsigned char layoutPadding6[2];

    NavMeshClosedDoorInfo();
};
