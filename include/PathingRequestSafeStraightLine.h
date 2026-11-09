#pragma once

#include "PathingRequestClosePoint.h"

// pdb: class PathingRequestSafeStraightLine, size 0xbc, bases: PathingRequestClosePoint, 1 members
class PathingRequestSafeStraightLine : public PathingRequestClosePoint
{
public:
    PathingRequestSafeStraightLine(int ai);
    virtual ~PathingRequestSafeStraightLine();
    virtual void CopyTo(PathingRequest*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void InitLoadGame(BGSLoadFormBuffer*);

    int TES_QPlaceableWaterCount();
    void* FUN_006e5fd0(unsigned int flags);
    void __thiscall CopyTo_006e6080(PathingRequest* apDest);
    void __thiscall SetTarget_006e60c0(int a1);
    void __thiscall SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_006e6110(BGSLoadFormBuffer* apLoadGameBuffer);
    void __thiscall ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer);

    int pTarget;
};
