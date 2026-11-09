// fallout_shared/pathfinding/pathingrequestlos.cpp: PathingRequestLOS (10 functions)

#include <math.h>

#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/PathingRequestLOS.h"
#include "../../../include/BSSimpleArray.h"

extern void* g_PathingRequestLOS_vtable;

// @fnv 0x004b1480
// pdb: ClampAngle | GlobalFunc.obj | retail, call graph (shared callers), high
// pdb params: afAngle
float WrapAngle(float afAngle)
{
    if (afAngle < 0.0)
        afAngle = fmod((float)(afAngle + 6.2831854820251465), 6.2831854820251465f);
    else if (afAngle >= 6.2831854820251465)
        afAngle = fmod(afAngle, 6.2831854820251465f);
    return afAngle;
}

struct C006e39d0
{
    void FUN_006e39d0();
};
void __cdecl _delete(void*, unsigned int);
struct S006e3a50
{
    void* FUN_006e3a50(unsigned int);
};
// Calls FUN_006e39d0 on this, deletes this with size 24 when flags has bit 0 set, and returns this.
// @fnv 0x006e3a50
// pdb: BSSimpleArrayRefCounted<PathingAvoidNode,1024>::`scalar deleting destructor' | PathingRequest.obj | debug, vtable slot, medium
void* S006e3a50::FUN_006e3a50(unsigned int flags)
{
    reinterpret_cast<C006e39d0*>(this)->FUN_006e39d0();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

// @fnv 0x006e5890
// pdb: PathingRequestLOS::`scalar deleting destructor' | PathingRequestLOS.obj | retail, vtable slot, high
void* PathingRequestLOS::DestroyAndFree(unsigned int flags)
{
    this->PathingRequestLOS::~PathingRequestLOS();
    if (flags & 1)
        PathingRequestLOS::operator delete(this, 0xd8);
    return this;
}

// @fnv 0x006e5c00
// pdb: PathingRequestLOS::LoadGame | PathingRequestLOS.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
// pdb locals: isaveGameCount, i, ignoreLoc
void PathingRequestLOS::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    unsigned int count = apLoadGameBuffer->ReadElementCount();
    m_b4.SetSize(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        ParentSpaceNode& node = m_b4.GetAt((int)i);
        apLoadGameBuffer->ReadTypedData(&node, 12);
    }
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_c4), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_c8), 12u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_d4), 4u);
}

// @fnv 0x006e5a40
// src: COMMUNITY 0x006e5a40
// pdb: PathingRequestLOS::operator= | PathingRequestLOS.obj | debug, object-file gap fill, medium
// pdb params: aRequest
void PathingRequestLOS::SetSearchCenter(NiPoint3 v, float w)
{
    m_c8 = v;
    m_d4 = w;
}

// @fnv 0x006e5a80
// pdb: PathingRequestLOS::CopyTo | PathingRequestLOS.obj | retail, upstream name already matches, high
// pdb params: apDest
// pdb locals: pdest
void PathingRequestLOS::CopyTo(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    static_cast<PathingRequestLOS*>(pdest)->m_b0 = m_b0;
    m_b4.CopyTo(&static_cast<PathingRequestLOS*>(pdest)->m_b4);
    static_cast<PathingRequestLOS*>(pdest)->m_c4 = m_c4;
    static_cast<PathingRequestLOS*>(pdest)->SetSearchCenter(m_c8, m_d4);
}

// @fnv 0x006e5b20
// pdb: PathingRequestLOS::SaveGame | PathingRequestLOS.obj | retail, upstream name already matches, high
// pdb params: apSaveGameBuffer
// pdb locals: isaveGameCount, i, ignoreLoc
void PathingRequestLOS::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::PathingRequest_SaveGame(apSaveGameBuffer);

    unsigned int isaveGameCount =
        (reinterpret_cast<unsigned int>(this) + 0xB4) != 0
            ? m_b4.GetSize()
            : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->SaveVariableSizedValue(isaveGameCount);

    {
        unsigned int i;
        for (i = 0; i < isaveGameCount; ++i)
        {
            ParentSpaceNode& node = m_b4.GetAt((int)i);
            apSaveGameBuffer->SaveData(&node, 0xC, 0);
        }
    }

    apSaveGameBuffer->SaveData(&m_c4, 4, 0);
    apSaveGameBuffer->SaveData(&m_c8, 0xC, 0);
    apSaveGameBuffer->SaveData(&m_d4, 4, 0);
}

extern float g_fFUN006e57e0_c4;

// @fnv 0x006e57e0
// pdb: PathingRequestLOS::PathingRequestLOS | PathingRequestLOS.obj | debug, call graph, medium
PathingRequestLOS::PathingRequestLOS()
    : PathingRequest(),
      m_b0(((*reinterpret_cast<void**>(this) = &g_PathingRequestLOS_vtable), 0)),
      m_b4(), m_c8()
{
    m_c4 = g_fFUN006e57e0_c4;
    m_d4 = 0.0f;
}

// @fnv 0x006e58d0
// pdb: PathingRequestLOS::~PathingRequestLOS | PathingRequestLOS.obj | retail, upstream name already matches, high
PathingRequestLOS::~PathingRequestLOS()
{}

// @fnv 0x006e5940
// pdb: PathingRequestLOS::PathingRequestLOS | PathingRequestLOS.obj | retail, object-file run extension, high
PathingRequestLOS::PathingRequestLOS(const PathingRequestLOS& aRequest)
    : PathingRequest(const_cast<PathingRequestLOS*>(&aRequest)),
      m_b0(((*reinterpret_cast<void**>(this) = &g_PathingRequestLOS_vtable), aRequest.m_b0)),
      m_c4(aRequest.m_c4)
{
    aRequest.m_b4.CopyTo(&m_b4);
    float kPos[3];
    Place(aRequest.GetPosition(*reinterpret_cast<NiPoint3*>(kPos)), aRequest.GetRadius());
}
