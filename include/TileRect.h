#pragma once

#include "Tile.h"

class NiAVObject;

// pdb: class TileRect, size 0x3c, bases: Tile, 1 members
class TileRect : public Tile
{
  public:
    TileRect();
    virtual ~TileRect();
    virtual void Init(Tile* apParent, const char* apName, Tile* apReplacedTile);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);

    const char* GetTypeName();
    NiNode* GetAttachModel() const;
    NiAVObject* GetExtraDataModel() const;
    const char* FUN_00709970();

    bool bIsScissor;
    unsigned char layoutPadding39[3];
};
