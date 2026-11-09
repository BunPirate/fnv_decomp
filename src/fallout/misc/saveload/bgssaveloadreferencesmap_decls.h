// Private declarations for BGSSaveLoadReferencesMap.
#ifndef FNV_BGSSAVELOADREFERENCESMAP_DECLS_H
#define FNV_BGSSAVELOADREFERENCESMAP_DECLS_H


#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESWorldSpace.h"

#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/BGSCellNumericIDArrayMap.h"

#include "../../../../include/BSSimpleArray.h"

class BGSReconstructFormsInAllFilesMap;

// pdb: class BGSSaveLoadReferencesMap, size 0x30, 3 members
class BGSSaveLoadReferencesMap
{
  public:
    NiTPointerMap<unsigned int, unsigned int> MovedReferencesMap;
    BGSCellNumericIDArrayMap InteriorReferencesMap;
    NiTPointerMap<unsigned int, BGSCellNumericIDArrayMap*> WorldspaceReferencesMap;

    void Clear();
    void LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms);
    void ReconstructFormID(unsigned int aiRefID, BGSReconstructFormsInAllFilesMap* apReconstructForms);
};

typedef char bgssaveloadreferencesmap_cell_map_size[(sizeof(BGSCellNumericIDArrayMap) == 16) ? 1 : -1];
typedef char bgssaveloadreferencesmap_references_size[(sizeof(BGSSaveLoadReferencesMap) == 48) ? 1 : -1];

#endif
