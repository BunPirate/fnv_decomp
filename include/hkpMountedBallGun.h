#pragma once

#include "hkpBallGun.h"
#include "hkVector4.h"

// pdb: class hkpMountedBallGun, size 0x70, bases: hkpBallGun, 1 members
class hkpMountedBallGun : public hkpBallGun
{
public:
    hkVector4 m_position;
};
