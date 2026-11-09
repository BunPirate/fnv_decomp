#pragma once

#include "MobileObject.h"

class ArrowRenderer;
class ArrowWorldObj;
class B5F750Ref;

// pdb: class ArrowProjectile, size 0xc8 (here 0x150), bases: MobileObject, 17 members
class ArrowProjectile : public MobileObject
{
public:
    int FUN_008ce390();
    ArrowRenderer* GetRenderer();
    B5F750Ref* GetAttachedRef();
    void Detach();
    bool HandleType0(ArrowWorldObj* apArrowRB);
    bool HandleType1(ArrowWorldObj* apArrowRB);
    bool HandleType2(ArrowWorldObj* apArrowRB);
    bool HandleType3(ArrowWorldObj* obj);
    bool HandleType4(ArrowWorldObj* apArrowRB);
    bool ProcessImpact();

    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
    unsigned int : 32;
};
