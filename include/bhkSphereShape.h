#pragma once

#include "bhkConvexShape.h"

class ArgB;

// pdb: class bhkSphereShape, size 0x14, bases: bhkConvexShape, 0 members
class bhkSphereShape : public bhkConvexShape
{
public:
    bhkSphereShape(float afRadius, bool abBS);
    virtual ~bhkSphereShape();

    virtual const NiRTTI* GetRTTI() const;
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void* GetHavokShape();
    void* Bipedanim_GetReferenceFlagsOrZero();
    void bhkSphereShape_Init(float radius);
    void bhkShape_CopyMembers(void* apDest, ArgB* arCloneData);
    void CopyMembers_00ca0740(void* apDest, ArgB* arCloneData);
    void bhkPackedNiTriStripsShape_CopyMembers(void* apDest, ArgB* arCloneData);
    void bhkMultiSphereShape_CopyMembers(void* apDest, ArgB* arCloneData);
    void ScaleTarget(void* apDest, ArgB* arCloneData);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI bhkSphereShape_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01268288 (old: DAT_01268288/g_01268288/ms_kRTTI)
};
