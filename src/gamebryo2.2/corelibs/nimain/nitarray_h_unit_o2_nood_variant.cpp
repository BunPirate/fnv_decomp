
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "../../../../include/StrArr.h"
#include "nitarray.inl"
void NiTArray_UnitReference()
{
    NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >* pGroups = 0;
    ActorCombatGroup* pGroup = 0;
    pGroups->SetAt(0, pGroup);
    pGroups->SetSize(0);
    pGroups->SetAtGrow(0, pGroup);
}
struct Arr
{
    unsigned int GetSize();
};
struct FUN_0096aca0_shell : Arr
{
    void ResizeAndClear(int b);
};

extern __declspec(thread) int g_tlsMemContext;
extern void* bhkDashpotAction_ms_RTTI;
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);

struct PrimitiveStringArray
{
    virtual ~PrimitiveStringArray();
    void** data_at_04;
    unsigned short capacity_at_08, size_at_0a, used_at_0c, growth_at_0e;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void*&);
};
struct MemoryContextScope
{
    int previous;
    __forceinline MemoryContextScope() : previous(g_tlsMemContext)
    {
        g_tlsMemContext = 16;
    }
    __forceinline ~MemoryContextScope()
    {
        g_tlsMemContext = previous;
    }
};
struct __declspec(align(16)) ScalarVector4
{
    float x, y, z, w;
};
struct OperationParameters
{
    void* field_at_00;
    void* field_at_04;
    void* field_at_08;
    ScalarVector4 vector_at_10;
    ScalarVector4 vector_at_20;
    float value_at_30;
    float value_at_34;
};
struct HavokOperation
{
    void bhkBinaryAction_GetViewerStrings(PrimitiveStringArray*);
    void bhkDashpotAction_CopyCinfo(const OperationParameters*);
    void bhkDashpotAction_GetViewerStrings(PrimitiveStringArray*);
};
// @fnv 0x00cc4070
// src: XBOX_PDB 0x00cc4070
// pdb: bhkDashpotAction::GetViewerStrings | bhkDashpotAction.obj | retail, upstream name already matches, high
// pdb params: apStrings
// pdb locals: tempMemContext, ci
void HavokOperation::bhkDashpotAction_GetViewerStrings(PrimitiveStringArray* apStrings)
{
    MemoryContextScope context;
    bhkBinaryAction_GetViewerStrings(apStrings);
    void* entry = NiViewerStrings_NiGetViewerString_Title(bhkDashpotAction_ms_RTTI);
    unsigned int index = apStrings->size_at_0a;
    if (index >= apStrings->capacity_at_08)
        apStrings->FUN_0096ad30(index + apStrings->growth_at_0e);
    apStrings->FUN_0096ae90(index, entry);
    OperationParameters parameters = {0, 0, 0, {0, 0, 0, 0}, {0, 0, 0, 0}, 0.1f, 0.01f};
    bhkDashpotAction_CopyCinfo(&parameters);
}
