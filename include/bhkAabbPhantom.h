#pragma once

#include "bhkPhantom.h"

class WorldHolder;

// pdb: class bhkAabbPhantom, size 0x18 (here 0x1c), bases: bhkPhantom, 0 members
class bhkAabbPhantom : public bhkPhantom
{
public:
    virtual ~bhkAabbPhantom();
    virtual WorldHolder* GetWorld();

    void FUN_00c9f530();
    void* FUN_0056e5e0(unsigned int flags);
    void bhkPhantom_UpdateCFilter();
    static NiObject* __cdecl CreateObject();

    int m4;
    void* m8;
};
