#pragma once

#include "BSWin32TaskletData.h"
#include "NiAVObject.h"
#include "PathingSolution.h"
#include "ActorPathingMessageQueue.h"

class PathingRequest;

// pdb: class PathingTaskData, size 0x50 (here 0x64), bases: BSXenonTaskletData, 7 members
class PathingTaskData : public BSWin32TaskletData
{
public:
    virtual ~PathingTaskData();
    virtual void Process();

    bool AllRayCastPathComputed();
    void SetTaskYielded();
    bool GetByteAtOffset64();

    NiPointer<PathingRequest> m_pPathingRequest;
    NiPointer<PathingSolution> m_pPathingSolution;
    char pad20[0x40];
    NiPointer<ActorPathingMessageQueue> spQueue;
};
