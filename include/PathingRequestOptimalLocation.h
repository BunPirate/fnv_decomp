#pragma once

#pragma warning(push)
#pragma warning(disable: 4335)
#include "PathingRequest.h"
#pragma warning(pop)

// pdb: class PathingRequestOptimalLocation, size 0xc0, bases: PathingRequest, 4 members
class PathingRequestOptimalLocation : public PathingRequest
{
public:
    PathingRequestOptimalLocation();
    PathingRequestOptimalLocation(PathingRequestOptimalLocation* src);
    virtual ~PathingRequestOptimalLocation();
    virtual void CopyTo(PathingRequest* apDest);

    void* FUN_006e5d70(unsigned int flags);
    float GetFloatAtOffsetB0();
    float GetFieldB4Float();
    float GetFieldB8Float();
    float BSSceneGraph_GetCameraFOV();

    union
    {
        char extra[16];
        struct
        {
            float fPointHeight;
            float m_fUnknownValue2;
            float m_fUnknownValue3;
            float m_fUnknownValue4;
        };
    };
};
