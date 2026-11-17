#pragma once

#include "PathingLocation.h"
#include "NiPoint3.h"

class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
class BGSSaveFormBuffer;
class BGSSaveGameBuffer;

// pdb: class PathingCoverLocation, size 0x54, bases: PathingLocation, 10 members
class PathingCoverLocation : public PathingLocation
{
public:
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);

    NiPoint3 LeftVertex; // src: XBOX_RETAIL_PDB +0x28 (old: a)
    NiPoint3 RightVertex; // src: XBOX_RETAIL_PDB +0x34 (old: b)
    NiPoint3 EdgeDirection; // src: XBOX_RETAIL_PDB +0x40 (old: c)
    unsigned char cCoverHeight; // src: XBOX_RETAIL_PDB +0x4c (old: f04c)
    unsigned char bStandCover; // src: XBOX_RETAIL_PDB +0x4d (old: f04d)
    unsigned char bHigherThanCrouch; // src: XBOX_RETAIL_PDB +0x4e (old: f04e)
    unsigned char bLeftEdgeOpen; // src: XBOX_RETAIL_PDB +0x4f (old: f04f)
    unsigned char bRightEdgeOpen; // src: XBOX_RETAIL_PDB +0x50 (old: f050)
    unsigned char cEdge; // src: XBOX_RETAIL_PDB +0x51 (old: f051)
    unsigned char cState; // src: XBOX_RETAIL_PDB +0x52 (old: f052)

    void SetCoverData(unsigned short a, unsigned short b, unsigned short c, char e, char f, char g);
    unsigned char* GetKey_006e4570();
    bool IsLedgeCover_006e4820();
    bool IsLeftSideClosest(const NiPoint3& arPoint);

    PathingCoverLocation& operator=(const PathingCoverLocation&);
    void Load(BGSLoadGameBuffer*);
    void SaveToBuffer(BGSSaveFormBuffer*);
};
