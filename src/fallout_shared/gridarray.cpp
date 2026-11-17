// fallout_shared/gridarray.cpp: GridArray (7 functions)

#include "../../include/GridArray.h"

// @fnv 0x004b9e70
void GridArray::Init()
{
    iCenterPixelY = -10000;
    iHorizontalPixelCenterObj = -10000;
}

// @fnv 0x004b9eb0
// pdb: GridArray::DetachAll | GridArray.obj | retail, vtable slot, high
// pdb locals: x, y
void GridArray::DetachAllCells()
{
    for (unsigned int i = 0; i < iDimension; ++i)
    {
        for (unsigned int j = 0; j < iDimension; ++j)
        {
            Detach(i, j);
        }
    }
}

// @fnv 0x004b9e50
GridArray::~GridArray()
{
}

// @fnv 0x004b9e90
// pdb: GridArray::KillAll | GridArray.obj | debug, vtable slot, medium
void GridArray::AttachAllCells()
{
    DetachAllCells();
}

// Computes the offset from the current cell to (aiX, aiY), shifts by it, and returns whether the offset was non-zero.
// @fnv 0x004b9f10
// pdb: GridArray::SetCenter | GridArray.obj | retail, vtable slot, high
// pdb params: aiX, aiY
// pdb locals: ioffY, ioffX
bool GridArray::SetGridPosition(int aiX, int aiY)
{
    int ioffX = aiX - static_cast<const GridArray*>(this)->GetCenterX();
    int ioffY = aiY - m_fCenterY();
    Shift(ioffX, ioffY);
    if (ioffX || ioffY)
        return true;
    else
        return false;
}

int FUN_00ec7d40(int);
// @fnv 0x004b9f70
// pdb: GridArray::Shift | GridArray.obj | retail, upstream name already matches, high
// pdb params: aiCols, aiRows
// pdb locals: icol, irow
void GridArray::Shift(int aiCols, int aiRows)
{
    unsigned int j = 0;
    unsigned int i = 0;
    iHorizontalPixelCenterObj += aiCols;
    iCenterPixelY += aiRows;
    if ((unsigned int)FUN_00ec7d40(aiCols) >= iDimension || (unsigned int)FUN_00ec7d40(aiRows) >= iDimension)
    {
        DetachAllCells();
        return;
    }
    while (aiCols != 0)
    {
        if (aiCols < 0)
        {
            for (i = 0; i < iDimension; ++i)
            {
                j = iDimension - 1;
                Detach(j, i);
                for (; j > 0; --j)
                    MoveItem(j - 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiCols;
        }
        else
        {
            for (i = 0; i < iDimension; ++i)
            {
                j = 0;
                Detach(j, i);
                for (; j < iDimension - 1; ++j)
                    MoveItem(j + 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiCols;
        }
    }
    while (aiRows != 0)
    {
        if (aiRows < 0)
        {
            for (j = 0; j < iDimension; ++j)
            {
                i = iDimension - 1;
                Detach(j, i);
                for (; i > 0; --i)
                    MoveItem(j, i - 1, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiRows;
        }
        else
        {
            for (j = 0; j < iDimension; ++j)
            {
                i = 0;
                Detach(j, i);
                for (; i < iDimension - 1; ++i)
                    MoveItem(j, i + 1, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiRows;
        }
    }
}
