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

    NiPoint3 LeftVertex;
    NiPoint3 RightVertex;
    NiPoint3 EdgeDirection;
    unsigned char cCoverHeight;
    unsigned char bStandCover;
    unsigned char bHigherThanCrouch;
    unsigned char bLeftEdgeOpen;
    unsigned char bRightEdgeOpen;
    unsigned char cEdge;
    unsigned char cState;

    void SetCoverData(unsigned short a, unsigned short b, unsigned short c, char e, char f, char g);
    unsigned char* GetKey_006e4570();
    bool IsLedgeCover_006e4820();
    bool IsLeftSideClosest(const NiPoint3& arPoint);

    PathingCoverLocation& operator=(const PathingCoverLocation&);
    void Load(BGSLoadGameBuffer*);
    void SaveToBuffer(BGSSaveFormBuffer*);
};
