#pragma once

#include "NiPlane.h"

// pdb: class NiFrustumPlanes, size 0x64, 2 members
class NiFrustumPlanes
{
public:
    NiPlane m_akCullingPlanes[6];
    unsigned int m_uiActivePlanes;

    NiFrustumPlanes() : m_uiActivePlanes(63) {}

    void Set(void*, void*);
    void Set(void*);
    void* GetPlane(unsigned int);
    void SetWaterColorParameter(unsigned int, void*);
    bool IsPlaneActive(unsigned int);
    bool IsAnyPlaneActive();
    bool AreAllPlanesActive();
    void EnablePlane(unsigned int);
    void DisablePlane(unsigned int);
    void EnableAllPlanes();
    void DisableAllPlanes();
    unsigned int GetActivePlaneState();
    void SetActivePlaneState(unsigned int);
};
