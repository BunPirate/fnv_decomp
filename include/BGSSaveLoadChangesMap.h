#pragma once

#include "FormChangeMask.h"
#include "NiTPointerMap.h"

class FormChangeRecord;

// RTTI: BGSSaveLoadChangesMap : NiTPointerMap<unsigned int, BGSFormChanges*> (FormChangeRecord here), vftable 0x0107ed68:
// only the destructor is its own (slots 1-6 are NiTPointerMap's, vftable 0x0107ed88). The base destructor 0x00845c00
// runs after Clear() in ~BGSSaveLoadChangesMap 0x008455b0.
// pdb: class BGSSaveLoadChangesMap, size 0x10, bases: NiTPointerMap<unsigned int, 0 members
class BGSSaveLoadChangesMap : public NiTPointerMap<unsigned int, FormChangeRecord*>
{
public:
    virtual ~BGSSaveLoadChangesMap();

    BGSSaveLoadChangesMap();
    void Initialize(unsigned int hashSize);
    void NiTPointerMap_unsigned_int_BGSFormChanges_NiTPointerMap(unsigned int hashSize);
    FormChangeRecord* GetChanges(unsigned int formID);
    FormChangeRecord* FUN_009a4250(unsigned int formID);
    bool CheckChangeFlags(unsigned int aiFormID, FormChangeMask aiChangeFlags);
    void AddChangeFlags(unsigned int aiFormID, FormChangeMask aiChangeFlags);
    void SetChangeFlags(unsigned int aiFormID, FormChangeMask aiChangeFlags);
    bool RemoveChanges(unsigned int aiFormID);
    bool RemoveChangeFlags(unsigned int aiFormID, FormChangeMask aiChangeFlags);
    void SetChangeBuffer(unsigned int aiFormID, unsigned int aiChangeFlags, unsigned int aUnloadedFormBuffer);
    bool RemoveAt(unsigned int formID);
    void SetAt(unsigned int formID, FormChangeRecord* changes);
    void Clear();
    void FUN_00845c00();
    void Deallocate(void* block);
};
