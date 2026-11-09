#pragma once

#include "PathingRequest.h"

// pdb: class PathingRequestCoveredMove, size 0x10c, bases: PathingRequest, 14 members
class PathingRequestCoveredMove : public PathingRequest
{
public:
    class AvoidanceItems
    {
    public:
        void FUN_007cb2e0();
    };

    PathingRequestCoveredMove();
    virtual ~PathingRequestCoveredMove();

    PathingRequestCoveredMove* FUN_006e4a50();

    void PathingRequestCoveredMove_SetAttackerHealth(float);
    void PathingRequestCoveredMove_SetTargetLocation(unsigned int);
    int GetOffsetF4();
    int PathingRequestCoveredMove_GetUnreachableCoverLocations();
    AvoidanceItems* PathingRequestCoveredMove_GetUnreachableCoverLocations(void*);

    union
    {
        char extra[44];
        void* unkB0;
    };
    unsigned int unkDC[12];
};
