#pragma once

#include "MagicProjectile.h"

// pdb: class MagicBallProjectile, size 0xc4 (here 0x150), bases: MagicProjectile, 5 members
class MagicBallProjectile : public MagicProjectile
{
public:
    virtual ~MagicBallProjectile();

    void FUN_0080fb30();
    void* FUN_0080f7e0(unsigned int);
};
