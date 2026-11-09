#pragma once

#include "bhkConvexShape.h"
#include "NiRTTI.h"
#include "hkVector4.h"

// pdb: class bhkBoxShape, size 0x14, bases: bhkConvexShape, 0 members
class bhkBoxShape : public bhkConvexShape
{
public:

    virtual const NiRTTI* GetRTTI() const;

    void Init(const hkVector4& halfExtents);
    void bhkShape_Link(bool b);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI bhkBoxShape_ms_RTTI;
};
