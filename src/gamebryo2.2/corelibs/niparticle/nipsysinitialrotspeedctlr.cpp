#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* NiPSysInitialRotSpeedCtlr_ms_RTTI; // src: XBOX_RETAIL_PDB 0x012026e0 (old: g_012026e0)

// @fnv 0x00c29f90
// src: COMMUNITY 0x00c29f90
void* __cdecl NiPSysInitialRotSpeedCtlr_GetRTTI()
{
    return &NiPSysInitialRotSpeedCtlr_ms_RTTI;
}

void* __cdecl NiViewerStrings_NiGetViewerString_Title(const void*);
extern void* NiPSysInitialRotSpeedCtlr_ms_RTTI; // src: XBOX_RETAIL_PDB 0x012026e0 (old: g_012026e0)
// pdb: class NiPSysInitialRotSpeedCtlr, size 0x40 (here 0x1), bases: NiPSysModifierFloatCtlr, 0 members
struct NiPSysInitialRotSpeedCtlr
{
    void __thiscall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
    void __thiscall AppendString(StrArr* pkStrings);
};
// Appends a string obtained from FUN_00a7d330(g_012026e0) to pkStrings, growing the array by its growth step when full.
// @fnv 0x00c2a000
// pdb: NiPSysInitialRotSpeedCtlr::GetViewerStrings | NiPSysInitialRotSpeedCtlr.obj | retail, object-file run extension, low
// pdb params: pkStrings
void __thiscall NiPSysInitialRotSpeedCtlr::AppendString(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* p = (char*)NiViewerStrings_NiGetViewerString_Title(NiPSysInitialRotSpeedCtlr_ms_RTTI);
    unsigned int nCount = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int nMax = *(unsigned short*)((char*)pkStrings + 8);
    if (nCount >= nMax)
        pkStrings->SetSize(nCount + *(unsigned short*)((char*)pkStrings + 14));
    pkStrings->SetAt(nCount, p);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern char DAT_010bedbc[];

struct CtorBase_cls
{
    void ctorBase();
};

struct FUN_00c29fb0_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00c32de0(void* obj, unsigned int a1);
    void* NiPSysInitialRotSpeedCtlr_CreateClone(unsigned int kCloning);
};

// Allocates a 0x40-byte object, runs its base constructor, sets its vtable, passes it to FUN_00c32de0 with a1, and returns it.
// @fnv 0x00c29fb0
// src: XBOX_PDB 0x00c29fb0
// pdb: NiPSysInitialRotSpeedCtlr::CreateClone | NiPSysInitialRotSpeedCtlr.obj | retail, upstream name already matches, high
// pdb params: kCloning
// pdb locals: pkObject
void* FUN_00c29fb0_cls::NiPSysInitialRotSpeedCtlr_CreateClone(unsigned int kCloning)
{
    FUN_00c29fb0_cls* p = (FUN_00c29fb0_cls*)Object_DispatchCommandFour(0x40);
    if (p != 0)
    {
        ((CtorBase_cls*)p)->ctorBase();
        p->m_vtbl = (void*)&DAT_010bedbc;
    }
    else
    {
        p = 0;
    }
    this->FUN_00c32de0(p, kCloning);
    return p;
}
