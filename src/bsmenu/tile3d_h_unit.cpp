#include "../../include/Tile3D.h"

// @fnv 0x00a0bdc0
int Tile3D::GetType()
{
    return 0x388;
}
// @fnv 0x00709860
// pdb: Tile::Tile | Interface.obj | retail, upstream name already matches, high
Tile::Tile() : xTraits(16, false), spModel(0)
{
    spModel = 0;
    pParent = 0;
    uiFlags = 0;
    bNeedsNiUpdate = false;
}
