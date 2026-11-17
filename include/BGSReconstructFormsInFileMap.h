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
    BGSReconstructCellBlocksMap* pInteriorCells; // src: XBOX_RETAIL_PDB +0x10 (old: m_pInteriorMap)
    BGSReconstructWorldSpacesMap* pWorldSpaces; // src: XBOX_RETAIL_PDB +0x14 (old: m_pExteriorMap)
    int iCount;

    BGSReconstructFormsInFileMap();
    ~BGSReconstructFormsInFileMap();
    void* ScalarDeletingDestructor(unsigned int flags);
    void ReconstructForms(TESFile* apFile, FormChangeMap* apReconstructedForms);
};
