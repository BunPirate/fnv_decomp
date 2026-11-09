// gamebryo2.2/corelibs/nianimation/nisingleinterpcontroller.cpp: single-interpolator controllers (20 functions)

#include "../../../../include/BSMultiTargetTreadTransfController.h"
#include "../../../../include/NiSingleInterpController.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// Base implementations not yet declared by the shared NiInterpController header.
void __cdecl NiInterpController_RegisterStreamables(int arg);
void NiInterpController_SaveBinary();
unsigned short __cdecl NiInterpController_IsEqual(void*, void*);
void FUN_00a2f980();

// Calls the base NiTimeController::ProcessClone, then forwards the clone process to the interpolator if one is set.
// @fnv 0x00a38f50
// pdb: NiSingleInterpController::ProcessClone | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: kCloning
void NiSingleInterpController::ProcessClone(CloningProcess& kCloning)
{
    NiTimeController::ProcessClone(kCloning);
    NiInterpolator* pInterpolator = m_spInterpolator.m_pObject;
    if (pInterpolator)
        pInterpolator->ProcessClone(kCloning);
}
// @fnv 0x00a38f80
// pdb: NiSingleInterpController::LoadBinary | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiSingleInterpController::LoadBinary(NiStream& kStream)
{
    NiInterpController::LoadBinary(kStream);
    if (kStream.m_uiNifFileVersion >= 0x0a010068)
    {
        NiInterpolator* value = (NiInterpolator*)kStream.DeserializeObject();
        NiInterpolator* old = m_spInterpolator.m_pObject;
        if (old != value)
        {
            if (old && InterlockedDecrement(reinterpret_cast<long*>(&old->m_uiRefCount)) == 0)
                old->DeleteThis();
            m_spInterpolator.m_pObject = value;
            if (value)
                InterlockedIncrement(reinterpret_cast<long*>(&value->m_uiRefCount));
        }
    }
}

extern int DAT_0109632c;
void __fastcall FUN_00a6d220(void*);

// @fnv 0x00a2f8c0
// src: XBOX_RETAIL_PDB 0x00a2f8c0
// pdb: NiInterpController::NiInterpController | NiInterpController.obj | retail, upstream name already matches, high
void* __fastcall NiInterpController_ctor(void* pThis)
{
    FUN_00a6d220(pThis);
    *((unsigned short*)pThis + 4) &= 0xffdf;
    *(int**)pThis = &DAT_0109632c;
    return pThis;
}

extern const char* const g_011f36ec_arg1;

// @fnv 0x00a38e20
const NiRTTI* NiSingleInterpController::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f36ec_arg1);
}

// @fnv 0x00a38e30
// pdb: NiSingleInterpController::GetInterpolator | NiSingleInterpController.obj | debug, upstream name already matches, high
// pdb params: usIndex
NiInterpolator* NiSingleInterpController::GetInterpolator(unsigned short usIndex) const
{
    return m_spInterpolator.m_pObject;
}

extern const char* const g_011f36bc_arg1;

// @fnv 0x00a2f8e0
// src: COMMUNITY 0x00a2f8e0
const NiRTTI* __fastcall NiInterpController_GetRTTI(const NiInterpController*)
{
    return reinterpret_cast<const NiRTTI*>(&g_011f36bc_arg1);
}

// @fnv 0x00a38df0
// src: XBOX_PDB 0x00a38df0
// pdb: NiSingleInterpController::TargetIsRequiredType | NiSingleInterpController.obj | debug, upstream name already matches, high
void __fastcall NiSingleInterpController_TargetIsRequiredType(NiSingleInterpController* controller)
{
    controller->TargetIsRequired(controller->m_pkTarget);
}

// @fnv 0x00a38e90
void NiSingleInterpController::SetActiveTimeRange(float m_fStartTime, float m_fMaximumDistance)
{
    NiInterpolator* p = m_spInterpolator.m_pObject;
    if (p)
        p->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
}

// Calls FUN_00a2f8b0, then if the interpolator at offset 0x34 is set, registers its streamables with kStream; returns true unless the first call fails.
// @fnv 0x00a38fe0
// pdb: NiSingleInterpController::RegisterStreamables | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: kStream
bool NiSingleInterpController::RegisterStreamables(NiStream& kStream)
{
    if (!reinterpret_cast<bool(__thiscall*)(NiInterpController*, NiStream&)>(&NiInterpController_RegisterStreamables)(this, kStream))
        return false;
    NiInterpolator* pkInterp = m_spInterpolator.m_pObject;
    if (pkInterp)
        pkInterp->RegisterStreamables(kStream);
    return true;
}

// @fnv 0x00a39010
// pdb: NiSingleInterpController::SaveBinary | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiSingleInterpController::SaveBinary(NiStream& kStream)
{
    reinterpret_cast<void(__thiscall*)(NiInterpController*, NiStream&)>(&NiInterpController_SaveBinary)(this, kStream);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spInterpolator.m_pObject));
}

char* _FUN_00a7d330(char const*);
extern char const* const g_011f36ec_arg1;
// @fnv 0x00a390a0
// pdb: NiSingleInterpController::GetViewerStrings | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: pkStrings
void NiSingleInterpController::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    reinterpret_cast<void(__thiscall*)(NiInterpController*, StrArr*)>(&FUN_00a2f980)(this, pkStrings);
    char* psz = _FUN_00a7d330(g_011f36ec_arg1);
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIdx + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIdx, psz);
    NiInterpolator* pInterp = m_spInterpolator.m_pObject;
    if (pInterp)
        pInterp->GetViewerStrings(strings);
}

// Replaces the stored interpolator pointer, releasing the old one and incrementing the new one's reference count.
// @fnv 0x00a38e40
// pdb: NiSingleInterpController::SetInterpolator | NiSingleInterpController.obj | debug, upstream name already matches, high
// pdb params: pkInterpolator, usIndex
void NiSingleInterpController::SetInterpolator(NiInterpolator* pkInterpolator, unsigned short usIndex)
{
    NiInterpolator* pOld = m_spInterpolator.m_pObject;
    if (pOld == pkInterpolator)
    {
        return;
    }
    if (pOld != 0)
    {
        if (InterlockedDecrement(reinterpret_cast<long*>(&pOld->m_uiRefCount)) == 0)
        {
            pOld->DeleteThis();
        }
    }
    m_spInterpolator.m_pObject = pkInterpolator;
    if (pkInterpolator != 0)
    {
        InterlockedIncrement(reinterpret_cast<long*>(&pkInterpolator->m_uiRefCount));
    }
}

// @fnv 0x00a39030
// pdb: NiSingleInterpController::IsEqual | NiSingleInterpController.obj | retail, upstream name already matches, high
// pdb params: pkObject
// pdb locals: pkDest
bool NiSingleInterpController::IsEqual(NiObject* pkObject) const
{
    NiSingleInterpController* other = static_cast<NiSingleInterpController*>(pkObject);
    if (!reinterpret_cast<bool(__thiscall*)(const NiInterpController*, NiObject*)>(&NiInterpController_IsEqual)(this, pkObject))
        return false;
    if ((m_spInterpolator.m_pObject && !other->m_spInterpolator.m_pObject) ||
        (!m_spInterpolator.m_pObject && other->m_spInterpolator.m_pObject))
        return false;
    if (m_spInterpolator.m_pObject)
    {
        const NiInterpolator* p = m_spInterpolator.m_pObject;
        NiInterpolator* o = other->m_spInterpolator.m_pObject;
        if (!p->IsEqual(o))
            return false;
    }
    return true;
}

extern "C" short DAT_01096320;

// @fnv 0x00a39080
// pdb: NiSingleInterpController::GetInterpolatorIndexFx | NiSingleInterpController.obj | debug, vtable slot, medium
// pdb params: arName
unsigned short NiSingleInterpController::GetTargetIndex(const NiFixedString& id) const
{
    NiObjectNET* holder = m_pkTarget;
    if (holder->m_kName.m_kHandle == id.m_kHandle)
    {
        return 0;
    }
    return DAT_01096320;
}

static inline unsigned short GetControllerField(const NiTimeController* controller, unsigned short mask, unsigned short position)
{
    return (controller->m_uiObjectFlags & mask) >> position;
}

static inline bool IsManagerControlled(const NiTimeController* controller)
{
    return (bool)(GetControllerField(controller, NiTimeController::MANAGERCONTROLLED_MASK, 5) & 1);
}

// @fnv 0x00a38ec0
void NiSingleInterpController::AdvanceControllerTime()
{
    if (IsManagerControlled(this))
        return;
    NiInterpController::AdvanceControllerTime();
    NiInterpolator* interpolator = m_spInterpolator.m_pObject;
    if (interpolator)
        interpolator->GetInterpolatorTimeRange(m_fLoKeyTime, m_fHiKeyTime);
}

extern void FUN_00c9a6b0();

// @fnv 0x00a35850
// src: XBOX_PDB 0x00a35850
// pdb: BSMultiTargetTreadTransfController::LinkObject | BSMultiTargetTreadTransfController.obj | debug, upstream name already matches, high
// pdb params: arStream
void BSMultiTargetTreadTransfController_LinkObject()
{
    FUN_00c9a6b0();
}

// @fnv 0x00a35870
// src: XBOX_PDB 0x00a35870
// pdb: BSMultiTargetTreadTransfController::SaveBinary | BSMultiTargetTreadTransfController.obj | debug, upstream name already matches, high
// pdb params: arStream
void __fastcall BSMultiTargetTreadTransfController_SaveBinary(NiInterpController* controller, void*, NiStream& arStream)
{
    reinterpret_cast<void(__thiscall*)(NiInterpController*, NiStream&)>(&NiInterpController_SaveBinary)(controller, arStream);
}

// @fnv 0x00a35880
// src: XBOX_PDB 0x00a35880
// pdb: BSMultiTargetTreadTransfController::IsEqual | BSMultiTargetTreadTransfController.obj | debug, upstream name already matches, high
// pdb params: apObject
// pdb locals: bret
unsigned short __cdecl BSMultiTargetTreadTransfController_IsEqual(void* param1, void* param2)
{
    return NiInterpController_IsEqual(param1, param2);
}

// @fnv 0x00a35890
// src: XBOX_PDB 0x00a35890
unsigned short __fastcall BSMultiTargetTreadTransfController_GetInterpolatorCount(const BSMultiTargetTreadTransfController* controller)
{
    // The shared header does not yet name the target count following entries.
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const unsigned char*>(controller) + 0x38);
}

// @fnv 0x00a35860
// src: XBOX_PDB 0x00a35860
// pdb: BSMultiTargetTreadTransfController::RegisterStreamables | BSMultiTargetTreadTransfController.obj | debug, upstream name already matches, high
// pdb params: arStream
// pdb locals: bret
void __cdecl BSMultiTargetTreadTransfController_RegisterStreamables(int arStream)
{
    NiInterpController_RegisterStreamables(arStream);
}
