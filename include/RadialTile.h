#pragma once

#include "TileImage.h"

// pdb: class RadialTile, size 0x48, bases: TileImage, 0 members
class RadialTile : public TileImage
{
  public:
    float __thiscall GetValueFloat(unsigned int id);
};
