// gamebryo2.2/corelibs/nianimation/nifloatextradatacontroller.cpp: NiFloatExtraDataController (9 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiColorInterpolator.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiFloatExtraDataController.h"
#include "../../../../include/NiFloatExtraData.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiStream.h"

extern const float NiInterpController_INVALID_TIME; // src: XBOX_RETAIL_PDB 0x01096324 (old: DAT_01096324/INVALID_TIME_A4F/g_fInvalidTimeBC3/kInvalidTime)
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

inline bool NiTimeController::GetManagerControlled() const
{
    return ((m_uiObjectFlags >> 5) & 1) != 0;
}

inline void NiInterpolator::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiInterpolator::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}


// @fnv 0x00a41300
// pdb: NiFloatExtraDataController::Update | NiFloatExtraDataController.obj | retail, upstream name already matches, high
// pdb params: UpdateData
// pdb locals: fValue
void NiFloatExtraDataController::Update(NiUpdateData& UpdateData)
{
    if (GetManagerControlled())
        m_fScaledTime = NiInterpController_INVALID_TIME;
    else if (AdvanceController(UpdateData.GetTime()))
    {
        if (!m_spInterpolator.m_pObject || !m_spInterpolator.m_pObject->AlwaysUpdate())
            return;
    }

    float value;
    if (m_spInterpolator.m_pObject &&
        m_spInterpolator.m_pObject->UpdateFloat(m_fScaledTime, m_pkTarget, value))
    {
        if (m_spExtraData.m_pObject)
            static_cast<NiFloatExtraData*>(m_spExtraData.m_pObject)->m_fValue = value;
    }
}

// @fnv 0x00a4fbd0
void __fastcall LoadBinaryWithVersionCheck(NiPSysModifierCtlr* pThis, int, NiStream& kStream)
{
    pThis->NiPSysModifierCtlr::LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xd8) < 0x0a010068)
    {
        kStream.ResetStreamState();
    }
}

extern int DAT_0109aa14;
extern int EmptyFS;

struct NiTimeController_Call
{
    void SetControllerActive();
};

// @fnv 0x00a572a0
// pdb: NiExtraDataController::NiExtraDataController | NiExtraDataController.obj | retail, call graph, medium
// pdb note: debug build links it to NiFloatExtraDataController::NiFloatExtraDataController
// pdb params: kExtraDataName
int* __fastcall InitTimeController(int* pThis)
{
    reinterpret_cast<NiTimeController_Call*>(pThis)->SetControllerActive();
    pThis[0] = reinterpret_cast<int>(&DAT_0109aa14);
    pThis[14] = EmptyFS;
    pThis[15] = 0;
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3e6c;

// @fnv 0x00a41230
// src: COMMUNITY 0x00a41230
const GlobalObjectO2_00a7b610* __cdecl NiFloatExtraDataController_GetRTTI()
{
    return &g_011f3e6c;
}

// The shared NiFloatInterpolator header does not yet declare its float constructor.
extern "C" void FUN_00a3c390();
struct FloatSrc
{
    char pad[0xc];
    float m_fFloatValue;
    float Get() const
    {
        float f = m_fFloatValue;
        return f;
    }
};

// Constructs a float pose interpolator from the float extra data at self+0x3c.
// @fnv 0x00a41240
// pdb: NiFloatExtraDataController::CreatePoseInterpolator | NiFloatExtraDataController.obj | retail, object-file run extension, low
// pdb params: usIndex
void* __fastcall CreateFadeNodeFromFloatSource(void* self, int edx, unsigned short usIndex)
{
    NiFloatInterpolator* p = static_cast<NiFloatInterpolator*>(BSFadeNode::operator new(sizeof(NiFloatInterpolator)));
    if (p)
        return reinterpret_cast<NiFloatInterpolator* (__thiscall*)(NiFloatInterpolator*, float)>(&FUN_00a3c390)(
            p, (*(FloatSrc**)((char*)self + 0x3c))->Get());
    return 0;
}

namespace fnv_00a41280 {
extern void* DAT_010975fc;
int* __fastcall InitTimeController(int*);
struct CopyHelper
{
    void CopyMemberData(CopyHelper* dest, void* process);
};

static void* Init(void* p)
{
    InitTimeController((int*)p);
    *(void**)p = &DAT_010975fc;
    return p;
}

// @fnv 0x00a41280
// src: XBOX_PDB 0x00a41280
// pdb: NiFloatExtraDataController::CreateClone | NiFloatExtraDataController.obj | retail, upstream name already matches, high
// pdb params: kCloning
// pdb locals: pkObject
void* __fastcall NiFloatExtraDataController_CreateClone(CopyHelper* self, int edx, void* kCloning)
{
    void* pMemory = BSFadeNode::operator new(0x40);
    void* pkObject = pMemory ? Init(pMemory) : 0;
    self->CopyMemberData((CopyHelper*)pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00a41280

class ActorCombatGroup;
namespace fnv_00a41380 {
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610* g_011f3e6c;
struct ArrHelper
{
    void* vt;
    unsigned int refs;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short pad;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, ActorCombatGroup*& v);
};
void __stdcall FUN_00a57420(ArrHelper* a);
ActorCombatGroup* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610* g);

// @fnv 0x00a41380
// pdb: NiFloatExtraDataController::GetViewerStrings | NiFloatExtraDataController.obj | retail, object-file run extension, low
// pdb params: pkStrings
void __stdcall AppendGlobalObject(ArrHelper* pkStrings)
{
    FUN_00a57420(pkStrings);
    ActorCombatGroup* v = NiViewerStrings_NiGetViewerString_Title(g_011f3e6c);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, v);
}
}  // namespace fnv_00a41380

namespace fnv_00a4fc00 {
// @fnv 0x00a4fc00
// pdb: NiColorExtraDataController::LinkObject | NiColorExtraDataController.obj | retail, object-file run extension, low
// pdb params: kStream
// pdb locals: pkColorData
void __fastcall LinkColorInterpolator(NiPSysModifierCtlr* self, int edx, NiStream* kStream)
{
    self->NiPSysModifierCtlr::LinkObject(*kStream);
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(kStream) + 0xd8) < 0x0a010068)
    {
        NiColorData* pkColorData = (NiColorData*)kStream->GetLoadedObject();
        NiColorInterpolator* p = new NiColorInterpolator(pkColorData);
        NiColorInterpolator** ppInterpolatorSlot = reinterpret_cast<NiColorInterpolator**>(&self->m_spInterpolator.m_pObject);
        if (*ppInterpolatorSlot != p)
        {
            if (*ppInterpolatorSlot)
                (*ppInterpolatorSlot)->DecRefCount();
            *ppInterpolatorSlot = p;
            if (p)
                p->IncRefCount();
        }
        (*ppInterpolatorSlot)->Collapse();
    }
}
}  // namespace fnv_00a4fc00

// NiFloatExtraDataController helper: push the controller's float extra-data value
// into the fade node that owns it (if the node is registered for this controller).
struct FadeNode
{
    FadeNode* LookupNode(void* pKey);
    void SetValue(float fValue);
};

extern int g_011f3738;

struct FUN_00a412d0_cls : public NiFloatExtraDataController
{
    void ApplyFadeValue(FadeNode* pkInterp, int usIndex);
};

// Looks up the fade node for g_011f3738 and sets its value from this controller's float extra data.
// @fnv 0x00a412d0
// pdb: NiFloatExtraDataController::SynchronizePoseInterpolator | NiFloatExtraDataController.obj | retail, object-file gap fill, high
// pdb params: pkInterp, usIndex
// pdb locals: pkFloatInterp
void FUN_00a412d0_cls::ApplyFadeValue(FadeNode* pkInterp, int usIndex)
{
    FadeNode* pTarget;
    if (pkInterp == 0)
        pTarget = 0;
    else
        pTarget = pkInterp->LookupNode(&g_011f3738);

    NiFloatExtraData* pExtraData = static_cast<NiFloatExtraData*>(this->m_spExtraData.m_pObject);
    pTarget->SetValue(pExtraData->m_fValue);
}
