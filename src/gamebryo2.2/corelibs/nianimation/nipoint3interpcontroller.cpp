
// gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller.cpp: free functions (6 functions)
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/NiPoint3Interpolator.h"
#include "../../../../include/NiRTTI.h"
#include "nipoint3interpcontroller_decls.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"

typedef void(__thiscall* GetPoint3Fn)(void*, NiPoint3*);

// @fnv 0x00a57c20
// src: XBOX_PDB 0x00a57c20
// pdb: NiPoint3InterpController::CreatePoseInterpolator | NiPoint3InterpController.obj | retail, upstream name already matches, high
// pdb params: usIndex
// pdb locals: kValue
void* __fastcall NiPoint3InterpController_CreatePoseInterpolator(void* self, int, unsigned short usIndex)
{
    NiPoint3 kValue;
    (*(GetPoint3Fn**)self)[0xec / 4](self, &kValue);
    void* pMemory = BSFadeNode::operator new(0x20);
    if (pMemory)
        return new (pMemory) NiPoint3Interpolator(kValue);
    return 0;
}

extern const char* const g_011f3f88_arg1;
// @fnv 0x00a57ca0
// src: COMMUNITY 0x00a57ca0
const char* const* NiPoint3InterpController_GetRTTI()
{
    return &g_011f3f88_arg1;
}

namespace fnv_00a57cb0 {
extern const NiRTTI g_011f3f70;
typedef void(__thiscall* GetPoint3Fn)(void*, NiPoint3*);

// Casts pkInterp to a NiPoint3 interpolator, reads a NiPoint3 from self via a virtual call, and passes it to the interpolator.
// @fnv 0x00a57cb0
// src: XBOX_PDB 0x00a57cb0
// pdb: NiPoint3InterpController::SynchronizePoseInterpolator | NiPoint3InterpController.obj | retail, upstream name already matches, high
// pdb params: pkInterp, usIndex
// pdb locals: kValue, pkPoint3Interp
void __fastcall NiPoint3InterpController_SynchronizePoseInterpolator(void* self, int, NiObject* pkInterp, int)
{
    NiPoint3Interpolator* pkPoint3Interp =
        !pkInterp ? 0 : (NiPoint3Interpolator*)pkInterp->DynamicCast(&g_011f3f70);
    NiPoint3 kValue;
    (*(GetPoint3Fn**)self)[0xec / 4](self, &kValue);
    pkPoint3Interp->SetPoseValue(kValue);
}
}  // namespace fnv_00a57cb0

struct ActorCombatGroup;
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTArray.h"
typedef NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> > CombatGroupArray;
extern const char* const g_011f3f88_arg1;
void __stdcall FUN_00a390a0(CombatGroupArray* a);
ActorCombatGroup* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);

// @fnv 0x00a57d10
// src: XBOX_PDB 0x00a57d10
// pdb: NiPoint3InterpController::GetViewerStrings | NiPoint3InterpController.obj | retail, upstream name already matches, high
// pdb params: pkStrings
void __stdcall NiPoint3InterpController_GetViewerStrings(CombatGroupArray* pkStrings)
{
    FUN_00a390a0(pkStrings);
    ActorCombatGroup* pGroup = NiViewerStrings_NiGetViewerString_Title(g_011f3f88_arg1);
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + uiIndex);
    pkStrings->SetAt(uiIndex, pGroup);
}

extern unsigned int DAT_011f404c;

// @fnv 0x00a532c0
// src: COMMUNITY 0x00a532c0
unsigned int* __cdecl NiBoolInterpolator_GetRTTI()
{
    return &DAT_011f404c;
}

struct S_00a53280_Foo
{
    void* unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    void* unk10;
    int unk14;

    void FUN_00a3ca10();
    void* NiBoolInterpolator_NiBoolInterpolator(void* pkBoolData);
};

extern void(__stdcall* FUN_00fdf1c0)(void*);

// @fnv 0x00a53280
// src: GAMEBRYO_LIB 0x00a53280
// pdb: NiBoolInterpolator::NiBoolInterpolator | NiBoolInterpolator.obj | retail, call graph (shared callers), high
// pdb params: pkBoolData
void* S_00a53280_Foo::NiBoolInterpolator_NiBoolInterpolator(void* pkBoolData)
{
    FUN_00a3ca10();

    unk00 = (void*)&DAT_0109a0b4;
    unk0c = DAT_0109a914;
    unk10 = pkBoolData;

    if (pkBoolData)
    {
        FUN_00fdf1c0((void*)((unsigned char*)pkBoolData + 4));
    }

    unk14 = 0;
    return this;
}
