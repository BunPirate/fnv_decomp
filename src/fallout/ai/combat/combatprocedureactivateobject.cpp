// fallout/ai/combat/combatprocedureactivateobject.cpp: CombatProcedureActivateObject, CombatProcedure, ScriptableFormForward and more (14 functions)

#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureActivateObject.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESScriptableForm.h"

// @fnv 0x006ecd40
void CombatProcedure::Initialize(CombatController* apCombatController)
{
    ((CombatController**)this)[1] = apCombatController;
}

// @fnv 0x006e4ba0
// src: COMMUNITY 0x006e4ba0
int CombatProcedureActivateObject::Return8()
{
    return 8;
}

struct TESObjectREFRHelper
{
    void SetTargetingState(int);
};
// Stores both pointers, sets m_cValue24 to zero, and calls SetTargetingState(1) when m_pReference is non-null.
// @fnv 0x009ca5f0
// pdb: CombatProcedureActivateObject::CombatProcedureActivateObject | CombatProcedureActivateObject.obj | retail, upstream name already matches, high
// pdb params: apTargetRef, apBoundObject
CombatProcedureActivateObject::CombatProcedureActivateObject(TESObjectREFR* apTargetRef, TESBoundObject* apBoundObject)
{
    pTargetRef = apTargetRef;
    pBoundObject = apBoundObject;
    m_cValue24 = 0;
    if (pTargetRef)
        ((TESObjectREFRHelper*)pTargetRef)->SetTargetingState(1);
}

// @fnv 0x009ca740
// pdb: CombatProcedureActivateObject::~CombatProcedureActivateObject | CombatProcedureActivateObject.obj | debug, upstream name already matches, high
CombatProcedureActivateObject::~CombatProcedureActivateObject()
{
}

#include <string.h>
#include <stdlib.h>
#include "../../../../include/BGSLoadGameBuffer.h"
class S_BaseProcess;
class S_Idle;
class S_HY;
class S_FileEntry;
class S_FileSub;
class S_Tile;
class S_TileProv;


class S_BaseProcess
{
  public:
    int GetProcessLevel();
    bool FindSpecialIdletoPlay(Actor* apActor, unsigned int apObject, void* apRef);
};

class S_FileSub
{
  public:
    virtual const char* v0();
    virtual const char* v1();
    virtual const char* v2();
    virtual const char* v3();
    virtual const char* v4();
    virtual const char* v5();
};

class S_FileEntry
{
  public:
    char pad[0x18];
    S_FileSub sub;
};

class S_Idle
{
  public:
    bool Animation_SpecialIdleDonePlaying();
    bool HasIdleForm(void* form);
    bool Animation_SpecialIdleWorking();
    S_FileEntry* Animation_GetSpecialIdleForm();
    S_HY* Animation_GetSpecialIdleSequence();
    float FUN_00453700();
};

class S_HY
{
  public:
    float GetScaledTime(float v);
};

class S_Tile
{
  public:
    void* GetActionAtIndex(int i);
    void CombatState_PreActivateReference(int apRef);
    void EvaluateWeaponScores();
};

class S_TileProv
{
  public:
    S_Tile* CombatController_GetCombatState();
};

class S_REFR
{
  public:
    unsigned int GetRefID();
    int FUN_00575610(int obj);
    bool Activate(Actor* apActionRef, bool abIdFlag, void* apObjecttoGet, int count);
};

struct CombatProcedureActorAccess
{
    Actor* GetActor();
};

// Checks the target and actor idle state, updates status, activates the target reference, and may evaluate weapon scores.
// @fnv 0x009ca760
// src: XBOX_PDB 0x009ca760
// pdb: CombatProcedureActivateObject::Update | CombatProcedureActivateObject.obj | retail, unique string literal, high
// pdb locals: panim, pattacker, phighProcess, bspecialIdleFound, pidleForm, pfileName, fsequenceTime, punderscore, pseq, pcombatState, icount, pboundObjects, i, pcombatItem
void CombatProcedureActivateObject::Update_009ca760()
{
    if (((S_REFR*)this->pTargetRef) == 0)
    {
        this->CombatProcedure_SetFailed("Targeted reference is NULL for some reason");
        return;
    }
    Actor* actor = ((CombatProcedureActorAccess*)this)->GetActor();
    S_Idle* idle = (S_Idle*)actor->GetAnimData();
    if (((S_BaseProcess*)actor->GetProcess())->GetProcessLevel() == 0 && idle != 0)
    {
        if (this->status == 0)
        {
            if (idle && (!idle->Animation_SpecialIdleDonePlaying() || idle->HasIdleForm(0)))
                return;
            S_BaseProcess* proc = (S_BaseProcess*)actor->GetProcess();
            bool ok = proc->FindSpecialIdletoPlay(actor, ((S_REFR*)this->pTargetRef)->GetRefID(), ((S_REFR*)this->pTargetRef));
            if (ok)
            {
                this->status = 1;
                return;
            }
            else
            {
                this->status = -1;
            }
        }
        else if (this->status == 1 || this->status == 3)
        {
            if (idle && (!idle->Animation_SpecialIdleDonePlaying() || idle->Animation_SpecialIdleWorking()))
            {
                if (this->status == 1)
                {
                    S_FileEntry* fe = idle->Animation_GetSpecialIdleForm();
                    if (fe)
                    {
                        const char* str = fe->sub.v5();
                        if (str)
                        {
                            S_HY* hy;
                            float val = 0.0f;
                            const char* b = strrchr(str, '_');
                            if (b)
                                val = (float)atof(b + 1);
                            hy = idle->Animation_GetSpecialIdleSequence();
                            if (!hy || val < hy->GetScaledTime(idle->FUN_00453700()))
                                this->status = 2;
                        }
                    }
                }
                if (this->status != 2)
                    return;
            }
        }
    }
    if (this->status != 3)
    {
        S_Tile* tile = ((S_TileProv*)this->pCombatController)->CombatController_GetCombatState();
        if (((S_REFR*)this->pTargetRef)->GetRefID() != (unsigned int)this->pBoundObject)
        {
            unsigned int cnt;
            int arr[5];
            memset(arr, 0, sizeof(arr));
            cnt = 0;
            for (unsigned int i = 0; i < 5; i++)
            {
                int* item = (int*)tile->GetActionAtIndex(i);
                if (item && *item == (int)((S_REFR*)this->pTargetRef))
                {
                    arr[cnt] = item[1];
                    cnt++;
                }
            }
            tile->CombatState_PreActivateReference((int)((S_REFR*)this->pTargetRef));
            for (unsigned int j = 0; j < cnt; j++)
            {
                int c = ((S_REFR*)this->pTargetRef)->FUN_00575610(arr[j]);
                if (c)
                {
                    if (c < 0)
                        c = -c;
                    ((S_REFR*)this->pTargetRef)->Activate(actor, 1, (void*)arr[j], c);
                }
            }
        }
        else
        {
            tile->CombatState_PreActivateReference((int)((S_REFR*)this->pTargetRef));
            ((S_REFR*)this->pTargetRef)->Activate(actor, 1, 0, 1);
        }
        if (!actor->Actor_IsInCombat())
            return;
        tile->EvaluateWeaponScores();
    }
    if (this->status == 2)
    {
        this->status = 3;
        return;
    }
    this->SetState();
}

// @fnv 0x009caac0
// src: XBOX_PDB 0x009caac0
void __thiscall CombatProcedureActivateObject::CombatProcedure_SetFailed(int arg1)
{
    ((int*)this)[3] = arg1;
    ((int*)this)[2] = 1;
}

// @fnv 0x009caae0
void CombatProcedureActivateObject::SetState()
{
    ((int*)this)[2] = 2;
}

// If m_pReference matches apRef, clears it and passes a message string to FUN_009caac0.
// @fnv 0x009cab00
// src: XBOX_PDB 0x009cab00
// pdb: CombatProcedureActivateObject::ClearReferencePointers | CombatProcedureActivateObject.obj | debug, vtable slot, medium
// pdb params: apRef
void CombatProcedureActivateObject::ClearReferencePointers_009cab00(TESObjectREFR* apRef)
{
    if (pTargetRef == apRef)
    {
        pTargetRef = 0;
        CombatProcedure_SetFailed((int)"Targeted reference pointer was cleared");
    }
}

struct FUN_009cab30_TextOutput
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Print(int aiX, int aiY, const char* apFormat, ...);
};
// The shared class has no debug-print declaration; this extension uses its layout.
struct ActivateObjectDebugView : CombatProcedureActivateObject
{
    void PrintDebug(FUN_009cab30_TextOutput* apDebugText, int aeLocation, int aeJustify);
};
// Prints the current animation state and, if m_pReference is set, its name, form ID, and position to apOutput at aiX, aiY.
// @fnv 0x009cab30
// pdb: CombatProcedureActivateObject::DisplayDebugText | CombatProcedureActivateObject.obj | retail, string-set bridge, high
// pdb params: apDebugText, aeLocation, aeJustify
// pdb locals: loc
void ActivateObjectDebugView::PrintDebug(FUN_009cab30_TextOutput* apDebugText, int aeLocation, int aeJustify)
{
    switch (cAnimState)
    {
    case -1:
        apDebugText->Print(aeLocation, aeJustify, "NO ANIM");
        break;
    case 1:
        apDebugText->Print(aeLocation, aeJustify, "ANIM PLAYING");
        break;
    case 2:
        apDebugText->Print(aeLocation, aeJustify, "ANIM GRABBING");
        break;
    case 3:
        apDebugText->Print(aeLocation, aeJustify, "ANIM FINISHING PLAYING");
        break;
    }
    if (pTargetRef)
    {
        NiPoint3 kPos = *static_cast<const TESObjectREFR*>(pTargetRef)->GetPos();
        apDebugText->Print(aeLocation, aeJustify, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                        pTargetRef->GetFormEditorIDLength() ? pTargetRef->GetName() : pTargetRef->GetFullName(),
                        pTargetRef->GetFormID(), kPos.x, kPos.y, kPos.z);
    }
}

// Saves the combat procedure state by calling SaveGame, serializing m_pReference and m_pBaseObject, and saving bFlag.
// @fnv 0x009cacb0
// src: XBOX_PDB 0x009cacb0
// pdb: CombatProcedureActivateObject::SaveGame | CombatProcedureActivateObject.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void CombatProcedureActivateObject::SaveGame_009cacb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    CombatProcedure::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData(pTargetRef, 0);
    apSaveGameBuffer->SerializeFormData(pBoundObject, 0);
    apSaveGameBuffer->SaveData(&bFlag, 1, 0);
}

struct CPStandIn004534f0
{
    void FUN_004534f0(unsigned int);
};
struct CPStandIn00564db0
{
    void TESObjectREFR_SetTargeted(int);
};
extern "C" TESForm* __cdecl TESForm_GetFormByNumericID(TESObjectREFR*);

// Calls FUN_004534f0 with arg, assigns the cast result of FUN_004839c0 to m_pReference, then calls FUN_00564db0(1) if non-null.
// @fnv 0x009cad70
// src: XBOX_PDB 0x009cad70
// pdb: CombatProcedureActivateObject::InitLoadGame | CombatProcedureActivateObject.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void CombatProcedureActivateObject::InitLoadGame_009cad70(unsigned int apLoadGameBuffer)
{
    ((CPStandIn004534f0*)this)->FUN_004534f0(apLoadGameBuffer);
    pTargetRef = pTargetRef ? dynamic_cast<TESObjectREFR*>(TESForm_GetFormByNumericID(pTargetRef)) : 0;
    if (pTargetRef)
        ((CPStandIn00564db0*)pTargetRef)->TESObjectREFR_SetTargeted(1);
}


struct ScriptableFormForward : public TESScriptableForm
{
    void CombatProcedureAttackMelee_Initialize(unsigned int apCombatController);
};

// @fnv 0x009cc4b0
// src: XBOX_PDB 0x009cc4b0
// pdb: CombatProcedureAttackMelee::Initialize | CombatProcedureAttackMelee.obj | debug, upstream name already matches, high
// pdb params: apCombatController
void ScriptableFormForward::CombatProcedureAttackMelee_Initialize(unsigned int apCombatController)
{
    TESScriptableForm::Initialize(apCombatController);
}

::TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
// Reads the activate object load view from a form buffer, loading the reference, base object, and flag.
// @fnv 0x009cad00
// src: XBOX_PDB 0x009cad00
// pdb: CombatProcedureActivateObject::LoadGame | CombatProcedureActivateObject.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void CombatProcedureActivateObject::LoadGame_009cad00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    CombatProcedure::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadFormIdentifier(&pTargetRef);
    pBoundObject =
        dynamic_cast< ::TESBoundObject*>(TESForm_GetFormByNumericID(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData(&bFlag, 1);
}
