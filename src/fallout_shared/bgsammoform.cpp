
// src/fallout_shared/bgsammoform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsammoform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSAmmoForm.h"
#include "../../include/BaseFormComponent.h"

// @fnv 0x00474b70
// pdb: BGSAmmoForm::CompareComponent | BGSAmmoForm.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pcompare
bool BGSAmmoForm::CompareWithBase(BaseFormComponent* apCompareFC)
{
    BGSAmmoForm* pcompare = dynamic_cast<BGSAmmoForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (m_pAmmo != pcompare->m_pAmmo)
        return true;
    return false;
}

void __cdecl _FUN_00485910(unsigned int, unsigned int);
struct DeallocHolder
{
    unsigned int __thiscall _ref_0084e3a0();
};
// @fnv 0x00474af0
// pdb: BGSAmmoForm::Save | BGSAmmoForm.obj | debug, call graph, high
// pdb locals: itempint
void BGSAmmoForm::Free()
{
    if (m_pAmmo != 0)
    {
        unsigned int uiRet = ((DeallocHolder*)m_pAmmo)->_ref_0084e3a0();
        _FUN_00485910(0x304D414E, uiRet);
    }
}

// @fnv 0x00474b30
// pdb: BGSAmmoForm::CopyComponent | BGSAmmoForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pcopy
void BGSAmmoForm::CopyFromBase(BaseFormComponent* apCopyFC)
{
    BGSAmmoForm* pcopy = dynamic_cast<BGSAmmoForm*>(apCopyFC);
    if (!pcopy)
        return;
    m_pAmmo = pcopy->m_pAmmo;
}

extern char DAT_01183028;
extern char DAT_011840c4;
extern int __cdecl FUN_00ec43fb(int target, int zero, const char* first, const char* second, int finalValue);
struct RangeHolder
{
    int* FUN_006815c0();
};
struct GroupHolder
{
    RangeHolder* FUN_00500940();
};
// The shared class does not yet declare the scripted-ammo queries.
GroupHolder* __fastcall GetAmmoScript(BGSAmmoForm* ammoForm);
// @fnv 0x00474a80
// src: XBOX_RETAIL_PDB 0x00474a80
// pdb: BGSAmmoForm::IsRockItLauncher | BGSAmmoForm.obj | retail, call graph, high
// pdb locals: testform, testammo
bool __fastcall BGSAmmoForm_IsRockItLauncher(BGSAmmoForm* ammoForm)
{
    if (GetAmmoScript(ammoForm))
    {
        int value = *GetAmmoScript(ammoForm)->FUN_00500940()->FUN_006815c0();
        if (value != 0)
        {
            int result = FUN_00ec43fb(value, 0, &DAT_01183028, &DAT_011840c4, 0);
            if (result == 0)
                return true;
        }
    }
    return false;
}

struct AmmoRecord
{
    int __thiscall FUN_00401170();
};
struct ComparisonInfo
{
    int __thiscall FUN_00484e60(int);
    int __thiscall GetFormEditorIDLength();
    unsigned int __thiscall GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
void __cdecl ResolveFormID(void**, int);
void* __cdecl TESForm_GetFormByNumericID(void*);
void __cdecl Warning_005b5e40(const char*, ...);
extern const char str_0101a3c8[];
extern const char str_0101a404[];
extern const char str_0101a444[];

// @fnv 0x00474bc0
// pdb: BGSAmmoForm::InitItem | BGSAmmoForm.obj | retail, string-set bridge, high
// pdb params: apOwner
// pdb locals: itempint
void BGSAmmoForm::InitItem(TESForm* apOwner)
{
    if (m_pAmmo)
    {
        void* oldAmmo = m_pAmmo;
        ResolveFormID(&oldAmmo, reinterpret_cast<ComparisonInfo*>(apOwner)->FUN_00484e60(-1));
        m_pAmmo = static_cast<TESForm*>(TESForm_GetFormByNumericID(oldAmmo));
        if (m_pAmmo && reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x29 &&
            reinterpret_cast<AmmoRecord*>(m_pAmmo)->FUN_00401170() != 0x55)
        {
            m_pAmmo = 0;
        }
        if (!m_pAmmo)
        {
            if (apOwner)
            {
                if (reinterpret_cast<ComparisonInfo*>(apOwner)->GetFormEditorIDLength())
                {
                    Warning_005b5e40(str_0101a444, oldAmmo,
                                 (reinterpret_cast<int(__thiscall*)(TESForm*)>(
                                     (*reinterpret_cast<void***>(apOwner))[0x130 / 4]))(apOwner));
                }
                else
                {
                    Warning_005b5e40(str_0101a404, oldAmmo, reinterpret_cast<DeallocHolder*>(apOwner)->_ref_0084e3a0());
                }
            }
            else
            {
                Warning_005b5e40(str_0101a3c8, oldAmmo);
            }
        }
    }
}
