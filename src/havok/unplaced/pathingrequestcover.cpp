#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPointer.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingCoverLocation.h"
#include "../../../include/PathingSolution.h"

// src/havok/unplaced/pathingrequestcover.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestcover.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006e4320_Class
{
    void PathingRequestCoveredMove_SetAttackerSneakHeight(float value);
};

// @fnv 0x006e4320
// src: XBOX_PDB 0x006e4320
void FUN_006e4320_Class::PathingRequestCoveredMove_SetAttackerSneakHeight(float value)
{
    *(float*)((char*)this + 0xbc) = value;
}

struct FUN_006e4340_Class
{
    void PathingRequestLOS_SetIgnoreLocationRadius(float value);
};

// @fnv 0x006e4340
// src: XBOX_PDB 0x006e4340
void FUN_006e4340_Class::PathingRequestLOS_SetIgnoreLocationRadius(float value)
{
    *(float*)((char*)this + 0xc4) = value;
}

struct FUN_006e4360_class
{
    void SetByteAtOffsetCD(char v);
};
// @fnv 0x006e4360
void FUN_006e4360_class::SetByteAtOffsetCD(char acValue)
{
    ((char*)this)[0xcd] = acValue;
}

struct FUN_006e4380_Class
{
    void __thiscall SetFlagCE(bool value);
};

// @fnv 0x006e4380
void __thiscall FUN_006e4380_Class::SetFlagCE(bool value)
{
    *(char*)((char*)this + 0xce) = (char)value;
}

struct FUN_006e43a0_class
{
    void _SetByteCF(int b);
};

// @fnv 0x006e43a0
// src: COMMUNITY 0x006e43a0
void FUN_006e43a0_class::_SetByteCF(int b)
{
    *(char*)((char*)this + 0xcf) = (char)b;
}

struct FUN_006e43c0_class
{
    void __thiscall SetByteAtOffsetD0(char param);
};

// @fnv 0x006e43c0
void __thiscall FUN_006e43c0_class::SetByteAtOffsetD0(char acValue)
{
    *(char*)((char*)this + 0xd0) = acValue;
}

struct FUN_006e43e0_class
{
    void SetFlag(bool value);
};

// @fnv 0x006e43e0
void FUN_006e43e0_class::SetFlag(bool value)
{
    ((char*)this)[0xd1] = value;
}


// pdb: class PathingRequestCover, size 0xec (here 0xe0), bases: PathingRequest, 13 members
struct PathingRequestCover
{
    unsigned int mPadding[0xd4 / 4];
    NiPoint3 mCover;
    void SetCover(const NiPoint3& point);
};

// Stores the given point into the mCover field of this PathingRequestCover.
// @fnv 0x006e4400
void PathingRequestCover::SetCover(const NiPoint3& point)
{
    mCover = point;
}

// @fnv 0x006e4630
// src: XBOX_PDB 0x006e4630
unsigned char* PathingCoverLocation_ComputeKey(int aiBase, unsigned short ausIndex, unsigned char aucOffset)
{
    return (unsigned char*)((aiBase << 0x10) + ausIndex * 4 + aucOffset);
}

// @fnv 0x006e4820
// src: XBOX_PDB 0x006e4820
bool PathingCoverLocation::IsLedgeCover_006e4820()
{
    return cCoverHeight == 2;
}

// @fnv 0x006e4500
// src: COMMUNITY 0x006e4500
void PathingCoverLocation::SetCoverData(unsigned short ausValue, unsigned short b, unsigned short c, char e, char f,
                                      char g)
{
    cCoverHeight = (char)ausValue;
    bStandCover = (char)(ausValue >= b ? 1 : 0);
    bHigherThanCrouch = (char)(ausValue > c ? 1 : 0);
    bLeftEdgeOpen = e;
    bRightEdgeOpen = f;
    cEdge = g;
    cState = 0;
}

// Copies the base PathingLocation, three NiPoint3 values and seven bytes from src into this object and returns *this.
// @fnv 0x006e4430
// pdb: PathingCoverLocation::operator= | PathingRequestCover.obj | retail, call graph (shared callers), medium
// pdb params: aLoc
PathingCoverLocation& PathingCoverLocation::operator=(const PathingCoverLocation& src)
{
    PathingLocation::operator=(src);
    LeftVertex = src.LeftVertex;
    RightVertex = src.RightVertex;
    EdgeDirection = src.EdgeDirection;
    cCoverHeight = src.cCoverHeight;
    bStandCover = src.bStandCover;
    bHigherThanCrouch = src.bHigherThanCrouch;
    bLeftEdgeOpen = src.bLeftEdgeOpen;
    bRightEdgeOpen = src.bRightEdgeOpen;
    cEdge = src.cEdge;
    cState = src.cState;
    return *this;
}

struct FUN_006def40_Class
{
    void FUN_006def40(BGSSaveFormBuffer* apSaveGameBuffer);
};
// Calls the base save routine, then writes three 12-byte blocks and seven single bytes from offsets 0x28 through 0x52 into the buffer.
// @fnv 0x006e48a0
// pdb: PathingCoverLocation::SaveGame | PathingRequestCover.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void PathingCoverLocation::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ((FUN_006def40_Class*)this)->FUN_006def40(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(&LeftVertex, 12, 0);
    apSaveGameBuffer->SaveData(&RightVertex, 12, 0);
    apSaveGameBuffer->SaveData(&EdgeDirection, 12, 0);
    apSaveGameBuffer->SaveData(&cCoverHeight, 1, 0);
    apSaveGameBuffer->SaveData(&bStandCover, 1, 0);
    apSaveGameBuffer->SaveData(&bHigherThanCrouch, 1, 0);
    apSaveGameBuffer->SaveData(&bLeftEdgeOpen, 1, 0);
    apSaveGameBuffer->SaveData(&bRightEdgeOpen, 1, 0);
    apSaveGameBuffer->SaveData(&cEdge, 1, 0);
    apSaveGameBuffer->SaveData(&cState, 1, 0);
}

// @fnv 0x006e4980
// pdb: PathingCoverLocation::LoadGame | PathingRequestCover.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void PathingCoverLocation::Load(BGSLoadGameBuffer* apLoadGameBuffer)
{
    PathingLocation::Load(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(&LeftVertex, 0xc);
    apLoadGameBuffer->ReadTypedData(&RightVertex, 0xc);
    apLoadGameBuffer->ReadTypedData(&EdgeDirection, 0xc);
    apLoadGameBuffer->ReadTypedData(&cCoverHeight, 1);
    apLoadGameBuffer->ReadTypedData(&bStandCover, 1);
    apLoadGameBuffer->ReadTypedData(&bHigherThanCrouch, 1);
    apLoadGameBuffer->ReadTypedData(&bLeftEdgeOpen, 1);
    apLoadGameBuffer->ReadTypedData(&bRightEdgeOpen, 1);
    apLoadGameBuffer->ReadTypedData(&cEdge, 1);
    apLoadGameBuffer->ReadTypedData(&cState, 1);
}

struct CoverPoint3
{
    float x;
    float y;
    float z;
};

struct CoverPathingRequest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;

    void CopyTo(CoverPathingRequest* apDest);
};

struct CoverPathingRequestCover : CoverPathingRequest
{
    CoverPoint3 m_kCoverPoint;
    float m_fUnkBC;
    float m_fUnkC0;
    float m_fUnkC4;
    void* m_pUnkC8;
    unsigned char unkCC;
    unsigned char m_cUnkCD;
    bool m_bUnkCE;
    unsigned char m_ucUnkCF;
    unsigned char m_cUnkD0;
    bool m_bUnkD1;
    unsigned char unkD2;
    unsigned char unkD3;
    CoverPoint3 m_kThreatPoint;

    void SetCoverPoint(const CoverPoint3& apRef);
    void SetUnkC0(float afValue);
    void SetUnkBC(float afValue);
    void SetUnkC4(float afValue);
    void SetUnkC8(void* apValue);
    void SetUnkCD(char acValue);
    void SetUnkCE(bool abValue);
    void SetUnkCF(int aiValue);
    void SetUnkD0(char acValue);
    void SetUnkD1(bool abValue);
    void SetThreatPoint(const CoverPoint3& arPoint);

    void CopyToCover(CoverPathingRequest* apDest);
};

// Copies the base request into apRequest and then sets its cover point, unkBC/C0/C4/C8/CD/CE/CF/D0/D1 values and threat point from this object.
// @fnv 0x006e4220
// pdb: PathingRequestCover::CopyTo | PathingRequestCover.obj | retail, vtable slot, high
// pdb params: apDest
// pdb locals: pdest
void CoverPathingRequestCover::CopyToCover(CoverPathingRequest* apDest)
{
    CoverPathingRequestCover* pCover = (CoverPathingRequestCover*)apDest;
    CoverPathingRequest::CopyTo(pCover);
    pCover->SetCoverPoint(m_kCoverPoint);
    pCover->SetUnkC0(m_fUnkC0);
    pCover->SetUnkBC(m_fUnkBC);
    pCover->SetUnkC4(m_fUnkC4);
    pCover->SetUnkC8(m_pUnkC8);
    pCover->SetUnkCD(m_cUnkCD);
    pCover->SetUnkCE(m_bUnkCE);
    pCover->SetUnkCF(m_ucUnkCF);
    pCover->SetUnkD0(m_cUnkD0);
    pCover->SetUnkD1(m_bUnkD1);
    pCover->SetThreatPoint(m_kThreatPoint);
}




struct FUN_006e4650_class
{
    bool FUN_006dd610(NavMeshPtr& aRetNavMesh);
    unsigned short GetShortValueAtOffset24(NiPointer<PathingSolution>& sol);
    bool PathingCoverLocation_CheckDynamicCoverValid(int aiLastMovedTime);
};

// @fnv 0x006e4650
// src: XBOX_PDB 0x006e4650
// pdb: PathingCoverLocation::CheckDynamicCoverValid | PathingRequestCover.obj | retail, upstream name already matches, high
// pdb params: aiLastMovedTime
// pdb locals: spnavMesh, spObstacle
bool FUN_006e4650_class::PathingCoverLocation_CheckDynamicCoverValid(int aiLastMovedTime)
{
    NavMeshPtr nm;
    if (FUN_006dd610(nm))
    {
        NiPointer<PathingSolution> sol(0);
        if (nm->GetObstacleForTriangle(GetShortValueAtOffset24(sol)) && *(int*)((char*)sol.operator->() + 0x70) == aiLastMovedTime)
            return true;
    }
    return false;
}

struct S_006e4570_NavMesh : NavMesh
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

// Looks up a navmesh triangle via FUN_006dd640 and returns FUN_006e4630's result for that triangle and unk51, or null if lookup fails.
// @fnv 0x006e4570
// src: XBOX_PDB 0x006e4570
// pdb: PathingCoverLocation::GetKey | PathingRequestCover.obj | debug, call graph, medium
// pdb locals: spnavMesh, striangle
unsigned char* PathingCoverLocation::GetKey_006e4570()
{
    NavMeshPtr navMesh;
    unsigned short triangleIndexA = 0;
    if (FUN_006dd640(&navMesh, &triangleIndexA))
    {
        return PathingCoverLocation_ComputeKey(((S_006e4570_NavMesh*)navMesh.operator->())->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), triangleIndexA, cEdge);
    }
    return 0;
}

struct S_006e4740
{
    bool FUN_006dd610(NavMeshPtr& aRetNavMesh);
    unsigned short GetShortValueAtOffset24(NiPointer<PathingSolution>& sol);
    int PathingCoverLocation_GetDynamicCoverObstacleTimeStamp();
};
// @fnv 0x006e4740
// src: XBOX_PDB 0x006e4740
// pdb: PathingCoverLocation::GetDynamicCoverObstacleTimeStamp | PathingRequestCover.obj | retail, upstream name already matches, high
// pdb locals: spnavMesh, spObstacle
int S_006e4740::PathingCoverLocation_GetDynamicCoverObstacleTimeStamp()
{
    NavMeshPtr nm;
    if (FUN_006dd610(nm))
    {
        NiPointer<PathingSolution> sol(0);
        if (nm->GetObstacleForTriangle(GetShortValueAtOffset24(sol)))
        {
            return *(int*)((char*)sol.operator->() + 0x70);
        }
    }
    return -1;
}

struct PointCalc : NiPoint3
{
    PointCalc SubtractIntoVector(const NiPoint3& other) const;
    double FUN_004a7290() const;
};
// @fnv 0x006e4840
// src: XBOX_PDB 0x006e4840
// pdb: PathingCoverLocation::IsLeftSideClosest | PathingRequestCover.obj | debug, upstream name already matches, high
// pdb params: arPoint
// pdb locals: leftEdgeVector, rightEdgeVector
bool PathingCoverLocation::IsLeftSideClosest(const NiPoint3& arPoint)
{
    PointCalc vecA = ((const PointCalc&)LeftVertex).SubtractIntoVector(arPoint);
    PointCalc vecB = ((const PointCalc&)RightVertex).SubtractIntoVector(arPoint);
    if (vecA.FUN_004a7290() < vecB.FUN_004a7290())
        return true;
    return false;
}

typedef unsigned int E41E0size_t;

struct FUN_006e41e0
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;

    FUN_006e41e0();
    virtual ~FUN_006e41e0();

    static void operator delete(void* pvMem, E41E0size_t uiSize);
};

// @fnv 0x006e41e0
// pdb: PathingRequestCover::`scalar deleting destructor' | PathingRequestCover.obj | retail, vtable slot, high
FUN_006e41e0::FUN_006e41e0()
{}
