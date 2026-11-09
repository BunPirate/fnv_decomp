#pragma once

#include "hkpPhantom.h"
#include "hkMotionState.h"

class hkTransform;
class hkpRigidBody;

// pdb: class hkpShapePhantom, size 0x160, bases: hkpPhantom, 1 members
class hkpShapePhantom : public hkpPhantom
{
public:
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();

    void hkpShapePhantom_setTransform(const hkTransform& transform);
    void __thiscall SetWorldPosition(void* position, float extraTolerance);
    void __thiscall SetWorldPosition(hkpRigidBody* position, float extraTolerance);

    char padA4[0xC];
    hkMotionState m_motionState;
};
