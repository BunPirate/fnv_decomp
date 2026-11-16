#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class NiCell3DNode;

// pdb: class ExtraCell3D, size 0x10, bases: BSExtraData, 1 members
class ExtraCell3D : public BSExtraData
{
public:
    virtual ~ExtraCell3D();

    NiPointer<NiCell3DNode> spCellNode; // src: XBOX_RETAIL_PDB +0xc (old: m_pController)
};
