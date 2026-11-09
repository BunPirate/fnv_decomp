#pragma once
#include "NiRefObject.h"
#include "DummyPointerMap.h"

class NavMeshCollection;
class NavMeshPtr;
class NiSortAdjustNode;
class SpawnedTarget;

// pdb: class PathingLOSMap, size 0x50, bases: NiRefObject, 11 members
class PathingLOSMap : public NiRefObject
{
public:
    struct Shell1c
    {
        unsigned int unk00;

        void AppendValue(NavMeshPtr& ptr);
        void ReleaseMember();
    };

    DummyPointerMap NavMeshToOffsetMap;
    union
    {
        char* pTriangleScores;
        char* m_pData;
    };
    Shell1c NavMeshes;
    unsigned char unk20[0x0C];
    unsigned int iTotalTriangleCount;
    unsigned char iTotalTrianglesSeen[0x0C];
    float Center;
    float f40;
    float f44;
    float fRadius;
    unsigned int fSightRadius;

    virtual ~PathingLOSMap();

    void* DestroyAndFree(unsigned int flags);
    bool BuildNavMeshMap(NavMeshCollection* pNavMeshArray);
    char* GetTriangleScore(unsigned int aNavMeshID);
    void GetMapValue(unsigned int uiKey, unsigned int& ruiValue);
    char GetLOSValue(unsigned int aiOffset, unsigned short aOffset);
    char GetNavMeshAndTriangleForIndex(unsigned int aiIndex, SpawnedTarget* aRetNavMesh, unsigned short* aRetTriangle);
    bool GetUnseenNavMeshAndTriangle(unsigned int aRetNavMesh, unsigned int aRetTriangle);
    NiSortAdjustNode* CreateSortAdjustNode();
    void ClampNonPositiveTextChars();
    bool HasNavMeshEntry(unsigned int aiNavMeshID);
};
