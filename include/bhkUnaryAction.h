#pragma once

#include "bhkAction.h"

class hkpUnaryAction;

// pdb: class bhkUnaryAction, size 0x10, bases: bhkAction, 0 members
class bhkUnaryAction : public bhkAction
{
public:
    bhkUnaryAction();
    virtual ~bhkUnaryAction();
    virtual void vf49();

    void Set(float x, float y, float z, float w);
    void __thiscall FUN_00c86720();
    void hkVector4_add4(void*);
    void ProcessEntity(hkpUnaryAction* apWorld); // 0x00c86940: adds the Havok action to the world (body in globalfunc_o2_variant.cpp)

    unsigned int unk0C;
};
