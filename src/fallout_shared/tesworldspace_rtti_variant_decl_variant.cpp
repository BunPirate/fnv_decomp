
// src/fallout_shared/tesworldspace_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00584e60: the skeleton of src/fallout_shared/tesworldspace_rtti_variant.cpp
// with declarations corrected to what the original code does (tesworldspace_packet_rtti_variant.h: public: bool IsTemporary() const; bool GetHasSpok -> public: virtual void F01(); virtual void F02(); v; tesworldspace_packet_rtti_variant.h: class TESObjectCELL { public: virtual ~TESObje -> class TESObjectCELL : public TESForm { public:; tesworldspace_packet_rtt). Move the function to its real unit once
// that unit declares it this way.

// src/fallout_shared/tesworldspace_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESForm, TESObjectCELL, TESWorldSpace). The skeleton of src/fallout_shared/tesworldspace.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
#include "../../include/TESWorldSpace.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/NiTPointerMap.h"
// Extends the shared layout only with clone methods absent from TESWorldSpace.h.
struct WorldSpaceCloneMethods : TESWorldSpace
{
    TESForm* TESForm_CreateDuplicateForm(bool, TESFile*);
    void TESWorldSpace_AddPersistentReferences();
    TESWorldSpace* TESWorldSpace_CreateDuplicateForm(bool abCreateEditorID, TESFile* apCopyMap);
};
// @fnv 0x00584e60
// src: XBOX_PDB 0x00584e60
// pdb: TESWorldSpace::CreateDuplicateForm | TESWorldSpace.obj | retail, upstream name already matches, high
// pdb params: abCreateEditorID, apCopyMap
// pdb locals: pdupworld, pcell, it, key, pdupcell
TESWorldSpace* WorldSpaceCloneMethods::TESWorldSpace_CreateDuplicateForm(bool abCreateEditorID, TESFile* apCopyMap)
{
    TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(TESForm_CreateDuplicateForm(abCreateEditorID, apCopyMap));
    world->cellMap->RemoveAll();
    void* position = cellMap->GetFirstPos();
    while (position)
    {
        TESForm* form2 = 0;
        unsigned int key;
        cellMap->GetNext(position, key, reinterpret_cast<TESObjectREFR*&>(form2));
        if (form2)
        {
            TESObjectCELL* cell3 = dynamic_cast<TESObjectCELL*>(form2->CreateForm(0, apCopyMap));
            if (cell3)
            {
                cell3->SetAltered(true);
                world->AddCell(cell3);
            }
        }
    }
    TESObjectCELL* persistent3 = GetInteriorCell();
    if (persistent3)
    {
        TESObjectCELL* copy = dynamic_cast<TESObjectCELL*>(persistent3->CreateForm(0, apCopyMap));
        if (copy)
        {
            world->pPersistentCell = copy;
            copy->SetAltered(true);
        }
    }
    static_cast<WorldSpaceCloneMethods*>(world)->TESWorldSpace_AddPersistentReferences();
    return world;
}
