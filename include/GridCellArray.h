#pragma once

#include "GridArray.h"

class GridCell;
class NiNode;
class Obj;
class TESObjectCELL;

// Exe GridCellArray helpers use an erased object reference with a Check(int) call; pointee identity is unproven.
struct GridCellObjectRefView
{
    Obj* p;

    GridCellObjectRefView(Obj*);
    ~GridCellObjectRefView();
    GridCellObjectRefView& operator=(Obj*);
    Obj* operator->() const;
    bool Check(int);
};

// pdb: class GridCellArray, size 0x28, bases: GridArray, 4 members
class GridCellArray : public GridArray
{
public:
    virtual ~GridCellArray();
    virtual void Init();
    virtual void AttachAllCells();
    virtual bool SetGridPosition(int x, int y);
    virtual void Detach(unsigned int aiX, unsigned int aiY);
    virtual void ClearTileExtraPair(unsigned int gridX, unsigned int gridY);
    virtual void MoveItem(unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void SwapTileExtraPair(unsigned int, unsigned int, unsigned int, unsigned int);

    GridCell* Get(unsigned int aiX, unsigned int aiY);
    void SetCellAtXY(unsigned int gridX, unsigned int gridY, GridCell* cell);
    void SetCellAt(unsigned int gridX, unsigned int gridY, TESObjectCELL* cell);
    bool IsOutdoorCell(unsigned int gridX, unsigned int gridY);
    void UpdateManagedNodes(float afTime);
    void Clear();
    void ReleaseGridCells();
    bool SetGridCellPosition(int x, int y);
    void SetFrom(unsigned int, unsigned int, unsigned int, unsigned int);
    void SwapCells(unsigned int, unsigned int, unsigned int, unsigned int);
    void KillAll();
    void AttachAllLand3D();
    void AttachToWorld(NiNode* root, unsigned int gridX, unsigned int gridY);
    void UpdateManagedNodeTransforms();
    void RunAnimations_004baba0();
    void UpdateRefSounds_004bac20();
    void ShowLandBorders(bool show);
    void ToggleCollisionGeometry_004bad40();
    void ShowPrimitives(bool abShow);
    void ClearCanopyShadowMaskTexture();
    void RecreateCanopyShadowMaskTexture();

    GridCell* pGridCellA; // src: XBOX_RETAIL_PDB +0x10 (old: m_pGridCells)
    float WorldCenter; // src: XBOX_RETAIL_PDB +0x14 (old: fX)
    float fY;
    int unk1c;
    int bLandAttached; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    GridCellObjectRefView spTexRendered; // src: XBOX_RETAIL_PDB +0x24 (old: spRT)
};
