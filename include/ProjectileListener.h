#pragma once

#include "bhkCharacterController.h"

// pdb: class ProjectileListener, size 0x660 (here 0x4d0), bases: bhkCharacterController, 1 members
class ProjectileListener : public bhkCharacterController
{
public:
    virtual ~ProjectileListener() throw();

    void bhkSerializable_Kill();

    int m4;
    int m8;
};
