#pragma once

#include "NiTMap.h"
#include "FormChangeMap.h"

class TESFile;
class TESForm;
class BGSReconstructFormsInFileMap;
struct ChangedFormRecord;

// pdb: class BGSReconstructFormsInAllFilesMap, size 0x34, bases: NiTMap<TESFile *, 2 members
class BGSReconstructFormsInAllFilesMap : public NiTMap<TESFile*, BGSReconstructFormsInFileMap*>
{
public:
    FormChangeMap ReconstructedForms; // src: XBOX_RETAIL_PDB +0x10 (old: m_kFormChangeMap)
    unsigned int iCount;

    BGSReconstructFormsInAllFilesMap();
    virtual ~BGSReconstructFormsInAllFilesMap();
    void* GetFirstPos();
    void GetNext(void*& position, TESFile*& file, BGSReconstructFormsInFileMap*& map);
    void Clear();
    void BuildMap();
    void AddFormFlagEntry(ChangedFormRecord* data);
    unsigned int GetCount_00849c80();
    TESForm* GetAt_00849ca0(unsigned int);
};


