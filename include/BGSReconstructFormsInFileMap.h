#pragma once

#include "BGSReconstructCellsMap.h"

class BGSReconstructCellBlocksMap;
class BGSReconstructWorldSpacesMap;
class TESFile;
class FormChangeMap;

// pdb: class BGSReconstructFormsInFileMap, size 0x1c, bases: NiTMap<unsigned int, 3 members
class BGSReconstructFormsInFileMap : public NiTMap<unsigned int, BGSReconstructFormsMap*>
{
public:
    BGSReconstructCellBlocksMap* pInteriorCells;
    BGSReconstructWorldSpacesMap* pWorldSpaces;
    int iCount;

    BGSReconstructFormsInFileMap();
    ~BGSReconstructFormsInFileMap();
    void* ScalarDeletingDestructor(unsigned int flags);
    void ReconstructForms(TESFile* apFile, FormChangeMap* apReconstructedForms);
};
