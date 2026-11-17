
// src/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysemitterlifespanctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPSysModifierFloatCtlr.h"
#include "../../../../include/StrArr.h"

extern "C" void* NiPSysEmitterLifeSpanCtlr_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01202740 (old: g_01202740)

// @fnv 0x00c2b650
// src: COMMUNITY 0x00c2b650
void* __cdecl NiPSysEmitterLifeSpanCtlr_GetRTTI()
{
    return &NiPSysEmitterLifeSpanCtlr_ms_RTTI;
}

// pdb: class NiPSysEmitterLifeSpanCtlr, size 0x40, bases: NiPSysModifierFloatCtlr, 0 members
class NiPSysEmitterLifeSpanCtlr : public NiPSysModifierFloatCtlr
{
public:
    NiPSysEmitterLifeSpanCtlr() throw()
    {}
    virtual ~NiPSysEmitterLifeSpanCtlr();

    void __thiscall GetTargetFloatValue(float& fValue);
    void SetTargetFloatValue_00c2b670(float fValue);
    void CopyMemberData(NiPSysEmitterLifeSpanCtlr* pkDest, void* pvCloning);
    NiPSysEmitterLifeSpanCtlr* CreateClone_00c2b680(void* pvCloning);
};

// @fnv 0x00c2b660
// src: XBOX_PDB 0x00c2b660
// pdb: NiPSysEmitterLifeSpanCtlr::GetTargetFloatValue | NiPSysEmitterLifeSpanCtlr.obj | debug, upstream name already matches, high
// pdb params: fValue
void __thiscall NiPSysEmitterLifeSpanCtlr::GetTargetFloatValue(float& fValue)
{
    NiPSysModifier* p = m_pkModifier;
    fValue = *(float*)((char*)p + 0x48);
}

// @fnv 0x00c2b670
// src: XBOX_PDB 0x00c2b670
void NiPSysEmitterLifeSpanCtlr::SetTargetFloatValue_00c2b670(float fValue)
{
    NiPSysModifier* p = m_pkModifier;
    float* f = (float*)((char*)p + 0x48);
    *f = fValue;
}
void __stdcall NiPSysModifierFloatCtlr_GetViewerStrings(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
// Appends the string returned by _FUN_00a7d330(g_01202740) to pkStrings, growing the array by its growth step when it is full.
// @fnv 0x00c2b6d0
// src: XBOX_PDB 0x00c2b6d0
// pdb: NiPSysEmitterLifeSpanCtlr::GetViewerStrings | NiPSysEmitterLifeSpanCtlr.obj | retail, upstream name already matches, high
// pdb params: pkStrings
void __stdcall NiPSysEmitterLifeSpanCtlr_GetViewerStrings(StrArr* pkStrings)
{
    NiPSysModifierFloatCtlr_GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330(NiPSysEmitterLifeSpanCtlr_ms_RTTI);
    unsigned int uSize = pkStrings->m_usSize;
    unsigned int uCap = pkStrings->m_usMaxSize;
    if (uSize >= uCap)
    {
        pkStrings->SetSize(uSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uSize, pszStr);
}

// @fnv 0x00c2b680
// src: XBOX_PDB 0x00c2b680
// pdb: NiPSysEmitterLifeSpanCtlr::CreateClone | NiPSysEmitterLifeSpanCtlr.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiPSysEmitterLifeSpanCtlr::IsEqual
// pdb params: kCloning
// pdb locals: pkObject
NiPSysEmitterLifeSpanCtlr* NiPSysEmitterLifeSpanCtlr::CreateClone_00c2b680(void* pvCloning)
{
    NiPSysEmitterLifeSpanCtlr* pkClone = new NiPSysEmitterLifeSpanCtlr;
    CopyMemberData(pkClone, pvCloning);
    return pkClone;
}
