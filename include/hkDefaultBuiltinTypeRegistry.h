#pragma once

#include "hkBuiltinTypeRegistry.h"

// pdb: class hkDefaultBuiltinTypeRegistry, size 0x8 (here 0xc), bases: hkBuiltinTypeRegistry, 0 members
class hkDefaultBuiltinTypeRegistry : public hkBuiltinTypeRegistry
{
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual int vf03();
    virtual int vf04();
    virtual int vf05();
    virtual void vf06();
    virtual void InitGlobalObjects();

    int _pad;
    unsigned short _f;
    unsigned short unk0A;

    void RegisterBuiltinTypes();
    hkDefaultBuiltinTypeRegistry* Initialize();
};
