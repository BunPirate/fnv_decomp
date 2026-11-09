extern char DAT_0109e984;

// src/gamebryo2.2/corelibs/nimain/niscreenelements_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niscreenelements.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "niscreenelements_flags.h"
#include "../../../../include/NiScreenElements.h"
#include "../../../../include/StrArr.h"

extern "C" void* NiScreenElements_ms_RTTI;

// @fnv 0x00a87800
// src: COMMUNITY 0x00a87800
void* __cdecl NiScreenElements_GetRTTI()
{
    return &NiScreenElements_ms_RTTI;
}

extern "C" void _delete(void*, unsigned int);

// @fnv 0x00a87830
// pdb: NiScreenElements::`scalar deleting destructor' | NiScreenElements.obj | retail, object-file gap fill, high
NiScreenElements* __thiscall NiScreenElements::FUN_00a87830(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = (void*)&DAT_0109e984;
    FUN_00a89760();
    if (flags & 1)
        _delete(this, 0xc4);
    return this;
}

char* _FUN_00a7d330(char*);

// @fnv 0x00a878b0
// pdb: NiScreenElements::GetViewerStrings | NiScreenElements.obj | retail, upstream name already matches, high
// pdb params: pkStrings
void NiScreenElements::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    NiTriShape::GetViewerStrings(strings);
    char* tmp = _FUN_00a7d330(reinterpret_cast<char*>(NiScreenElements_ms_RTTI));
    unsigned int sz = pkStrings->m_usSize;
    if (sz >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(pkStrings->m_usGrowBy + sz);
    pkStrings->SetAt(sz, tmp);
}

extern char DAT_0109e984;
extern "C" void __cdecl NiTriShape_ctor();

// The shared base has no single-data-pointer constructor declaration.
// @fnv 0x00a87810
// src: XBOX_RETAIL_PDB 0x00a87810
// pdb: NiScreenElements::NiScreenElements | NiScreenElements.obj | retail, call graph, high
// pdb params: pkModelData
NiScreenElements* __fastcall NiScreenElements_ctor(NiScreenElements* self, void*, NiScreenElementsData* data)
{
    ((void (__thiscall*)(NiTriShape*, NiScreenElementsData*))&NiTriShape_ctor)(self, data);
    *reinterpret_cast<void**>(self) = &DAT_0109e984;
    return self;
}

extern "C" void __cdecl ScreenElementsBaseDefaultConstructor() throw();
extern "C" void __cdecl ScreenElementsBaseCopyMembers();

// The shared class has no default constructor or clone override declaration.
// @fnv 0x00a87860
// pdb: NiScreenElements::CreateClone | NiScreenElements.obj | retail, object-file gap fill, high
// pdb params: kCloning
// pdb locals: pkObject
NiObject* __fastcall CloneScreenElements(NiScreenElements* self, void*, CloningProcess& process)
{
    NiScreenElements* pChild = static_cast<NiScreenElements*>(NiScreenElements::operator new(sizeof(NiScreenElements)));
    if (pChild)
    {
        ((void (__thiscall*)(NiTriShape*) throw())&ScreenElementsBaseDefaultConstructor)(pChild);
        *reinterpret_cast<void**>(pChild) = &DAT_0109e984;
    }
    else
        pChild = 0;
    ((void (__thiscall*)(NiTriShape*, NiScreenElements*, CloningProcess&))&ScreenElementsBaseCopyMembers)(self, pChild, process);
    return pChild;
}
