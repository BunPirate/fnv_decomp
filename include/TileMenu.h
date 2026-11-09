#pragma once

#include "TileRect.h"

class Menu;

// pdb: class TileMenu, size 0x40, bases: TileRect, 1 members
class TileMenu : public TileRect
{
  public:
    TileMenu();
    virtual ~TileMenu();
    virtual void Init(Tile* apParent, const char* apName, Tile* apReplacedTile);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int aiTrait, float afValue, const char* axString);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    TileMenu* __thiscall TileMenuConstructor(int aiUnused1, int aiUnused2);
    float GetTraitFloat(int id);
    void SetSourceTexture(int apTexture);

    union
    {
        Menu* unk3c;
        Menu* pMenu;
        Menu* menu;
    };
};
