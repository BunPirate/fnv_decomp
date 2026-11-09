#pragma once

#include "Projectile.h"

// pdb: class FlameProjectile, size 0x180 (here 0x150), bases: Projectile, 2 members
class FlameProjectile : public Projectile
{
public:
    FlameProjectile();
    virtual bool IsProximityDetonationTriggered();
    void LoadGame_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer);
    void RevertBGS_009b3f50(BGSLoadFormBuffer* apLoadGameBuffer);
};
