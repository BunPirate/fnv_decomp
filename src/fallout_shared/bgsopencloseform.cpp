#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/bgsopencloseform.cpp: BGSOpenCloseForm, AIThreadManager (8 functions)

#include "../../include/TESForm.h"
#include "../../include/ExtraDataList.h"
#include "../../include/LowProcess.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiUpdateData.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESObjectCONT.h"

// Form IDs used by this unit.
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/NavMeshObstacleManager.h"

// Private declarations for the remaining animation and event interfaces.
class NiProperty;
class SkyShaderProperty;
SkyShaderProperty* NiObject_DynamicCast(const NiRTTI*, NiProperty*);
extern NiRTTI DAT_011f36ac;
#include "../../include/OBJECT_ACTION.h"
class AIThreadManager
{
  public:
    static TESObjectREFR* IsConditionMet();
};
bool IsConditionMet();
// pdb: class TaskQueueInterface, size 0x10 (here 0x1), 4 members
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void TaskQueueInterface_QueueSetOpenState(TESObjectREFR*, bool, bool);
};

class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d7188;
extern const char DAT_01011f30[];
extern const char g_011d22b0_arg1[];
extern float DAT_0101ab70;
void bhkNiCollisionObject_ResetSim(NiNode*, bool);

// @fnv 0x0047a490
// pdb: BGSOpenCloseForm::IsOpenCloseForm | BGSOpenCloseForm.obj | debug, call graph (shared callers), medium
// pdb params: apForm
// pdb locals: bskipcheck, bretval, ptest
bool BGSOpenCloseForm::HasOpenCloseComponent(TESForm* apForm)
{
    bool bResult = false;
    bool bIsActivatorForm = false;
    if (apForm)
    {
        switch (static_cast<const TESForm*>(apForm)->GetFormType())
        {
        case ENUM_FORM_ID_ACTI_ID:
        case ENUM_FORM_ID_TERM_ID:
        case ENUM_FORM_ID_CONT_ID:
        case ENUM_FORM_ID_DOOR_ID:
            bResult = true;
            break;
        case ENUM_FORM_ID_TACT_ID:
        case ENUM_FORM_ID_FLOR_ID:
        case ENUM_FORM_ID_FURN_ID:
            bIsActivatorForm = true;
            break;
        default:
            break;
        }
    }
    return bResult;
}

// @fnv 0x0047b250
// pdb: BGSOpenCloseForm::GetOpenState | BGSOpenCloseForm.obj | retail, upstream name already matches, high
// pdb params: apRef
// pdb locals: eretval, bopen, ptopav, pmanager, po, popenseq, pcloseseq
int BGSOpenCloseForm::GetOpenState(TESObjectREFR* apRef)
{
    // Local names preserve MSVC9 stack allocation order.
    OPEN_STATE eState = CLOSED_UNKNOWN;
    if (apRef && HasOpenCloseComponent(apRef->GetObjectReference()))
    {
        bool pManager = apRef->GetAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);  // Saved open action flag.
        if (pManager)
            eState = OPEN;
        else
            eState = CLOSED;
        NiNode* pController = apRef->GetNiNode();                                   // Reference scene node.
        NiTimeController* pNode = pController ? pController->NiObjectNET::GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* bOpen = (NiControllerManager*)NiObject_DynamicCast(&DAT_011f36ac, (NiProperty*)pNode);
        if (bOpen)
        {
            NiControllerSequence* pOpenSequence = bOpen->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* pCloseSequence =
                bOpen->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (pOpenSequence && pCloseSequence)
            {
                if (((LowProcess*)pOpenSequence)->LowProcess::GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = OPENING;
                else if (((LowProcess*)pCloseSequence)->LowProcess::GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = CLOSING;
            }
        }
    }
    return eState;
}

// @fnv 0x0047aec0
// pdb: BGSOpenCloseForm::SetOpenState | BGSOpenCloseForm.obj | retail, upstream name already matches, high
// pdb params: apRef, abOpen, abSnap
// pdb locals: bplayedanims, ptopav, pmanager, po, popenseq, pseqtostop, pseqtoplay, pcloseseq, UpdateData
bool BGSOpenCloseForm::SetOpenState(TESObjectREFR* apRef, bool abOpen, bool abSnap)
{
    bool result = false;
    if (apRef && HasOpenCloseComponent(apRef->GetObjectReference()))
    {
        if (IsConditionMet() && apRef != AIThreadManager::IsConditionMet())
        {
            TaskQueueInterface::GetSingleton()->TaskQueueInterface_QueueSetOpenState(apRef, abOpen, abSnap);
            return true;
        }
        if (abOpen)
            apRef->PerformAction(OBJECT_ACTION_OBJECT_ACTION_OPEN);
        else
            apRef->CloseReference(OBJECT_ACTION_OBJECT_ACTION_OPEN);
        NiNode* node = apRef->GetNiNode();
        NiTimeController* manager = node ? node->NiObjectNET::GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* controller = (NiControllerManager*)NiObject_DynamicCast(&DAT_011f36ac, (NiProperty*)manager);
        if (controller)
        {
            NiControllerSequence* active = 0;
            NiControllerSequence* inactive = 0;
            NiControllerSequence* opening = controller->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* closing = controller->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (opening && closing)
            {
                if (abOpen)
                {
                    active = opening;
                    inactive = closing;
                }
                else
                {
                    active = closing;
                    inactive = opening;
                }
                controller->FUN_0047aa40(true);
                if (abSnap)
                {
                    apRef->GetExtraData()->ExtraDataList_SetRagDollData(0);
                    controller->StopSequence(active, 0.0f);
                    controller->ActivateControllerSequence(inactive, 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                    inactive->PathingLOSGridMap_SetSightRadius(-DAT_0101ab70);
                    NiUpdateData data(inactive->NiPSysSpawnModifier_GetLifeSpan(), true, false);
                    apRef->GetNiNode()->Update(static_cast<const NiUpdateData&>(data));
                    controller->StopSequence(inactive, 0.0f);
                    apRef->TESObjectREFR_SetLastFinishedSequence(static_cast<const NiControllerSequence*>(active)->GetName());
                    bhkNiCollisionObject_ResetSim(apRef->GetNiNode(), true);
                }
                else
                {
                    controller->StopSequence(inactive, 0.0f);
                    controller->ActivateControllerSequence(active, 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                    active->PathingLOSGridMap_SetSightRadius(-DAT_0101ab70);
                    NiUpdateData data(active->NiPSysSpawnModifier_GetLifeSpan(), true, false);
                    apRef->GetNiNode()->Update(static_cast<const NiUpdateData&>(data));
                }
                result = true;
            }
        }
        else
        {
            if (abOpen)
                apRef->TESObjectREFR_SetLastFinishedSequence(DAT_01011f30);
            else
                apRef->TESObjectREFR_SetLastFinishedSequence(g_011d22b0_arg1);
        }
        if (abSnap && *((Setting*)&g_011d7188)->FUN_00408d60() &&
            static_cast<const TESForm*>(apRef->GetObjectReference())->GetFormType() == ENUM_FORM_ID_DOOR_ID && apRef->GetNiNode() &&
            !apRef->GetExtraRadioData())
        {
            if (abOpen)
                NavMeshObstacleManager::GetSingleton()->RemoveObstacleReference(apRef);
            else
                NavMeshObstacleManager::GetSingleton()->AddObstacleReference(apRef);
        }
    }
    return result;
}

// @fnv 0x00759450
// src: XBOX_PDB 0x00759450
float NiControllerSequence::NiPSysSpawnModifier_GetLifeSpan()
{
    return m_fFirstKeyTime;
}

// @fnv 0x0098adb0
// src: XBOX_PDB 0x0098adb0
void NiControllerSequence::PathingLOSGridMap_SetSightRadius(float afValue)
{
    m_fSequenceOffset = afValue;
}

extern NiFixedString* DAT_011c61c4;

// @fnv 0x005c1490
// src: XBOX_PDB 0x005c1490
NiFixedString* __cdecl FixedStrings_QSpecialIdle_AreaEffect()
{
    return DAT_011c61c4;
}

// @fnv 0x0047a3a0
// pdb: BGSOpenCloseForm::GetAsOpenCloseForm | BGSOpenCloseForm.obj | debug, call graph (shared callers), high
// pdb params: apForm
// pdb locals: pretval, pform
BGSOpenCloseForm* GetOpenCloseForm(TESForm* apForm)
{
    BGSOpenCloseForm* pOpenCloseForm = 0;

    if (apForm && BGSOpenCloseForm::HasOpenCloseComponent(apForm))
    {
        switch (static_cast<const TESForm*>(apForm)->GetFormType())
        {
        case 0x15:
        case 0x17: {
            TESObjectACTI* pObject = reinterpret_cast<TESObjectACTI*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }

        case 0x1c: {
            TESObjectDOOR* pObject = reinterpret_cast<TESObjectDOOR*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }

        case 0x1b: {
            TESObjectCONT* pObject = reinterpret_cast<TESObjectCONT*>(apForm);
            pOpenCloseForm = static_cast<BGSOpenCloseForm*>(pObject);
            break;
        }
        }
    }

    return pOpenCloseForm;
}

struct EventString
{
    operator const char*() const;
};
struct SequenceEvent
{
    EventString& GetName();
};
struct Ref;
struct EventExtra
{
    Ref* GetTarget();
    void ExtraDataList_SetOpenCloseActivateRef(Ref*);
};
struct Ref
{
    EventExtra* Extra();
    TESForm* Base();
    void Reset(bool);
};
struct OpenCloseHandler
{
    virtual void Open(Ref*, Ref*);
    virtual void Close(Ref*, Ref*);
    virtual bool IsSpecial();
};
struct EventSetting
{
    unsigned char* Bool();
};
struct EventQueue
{
    void Open(Ref*);
    void Close(Ref*);
};
struct ObstacleManager
{
    static ObstacleManager* GetSingleton();
    void Open(Ref*);
    void Close(Ref*);
};
extern Ref* player;
extern EventSetting setting;
bool ProcessEvent(Ref*, SequenceEvent*);
int CompareEvent(const char*, const char*);
void SetEventFlags(Ref*, EventExtra*, unsigned int);
OpenCloseHandler* GetHandler(TESForm*);
bool ShouldQueue();
EventQueue* GetQueue();
// @fnv 0x0047ac70
// src: XBOX_RETAIL_PDB 0x0047ac70
// pdb: BGSOpenCloseForm::HandleAnimEnd | BGSOpenCloseForm.obj | retail, object-file run extension, high
// pdb params: apAnimRef, apEndSeq
// pdb locals: bwasOpenCloseAnim, pactionref, pocform
void __cdecl BGSOpenCloseForm_HandleAnimEnd(Ref* apAnimRef, SequenceEvent* apEndSeq)
{
    bool handled = false;
    if (apAnimRef && apEndSeq)
    {
        handled = ProcessEvent(apAnimRef, apEndSeq);
        if (!CompareEvent(apEndSeq->GetName(), "Open"))
        {
            handled = true;
            SetEventFlags(apAnimRef, apAnimRef->Extra(), 0x10000);
            Ref* openTarget = apAnimRef->Extra()->GetTarget();
            if (openTarget)
            {
                OpenCloseHandler* openHandler = GetHandler(apAnimRef->Base());
                if (openHandler)
                    openHandler->Open(apAnimRef, openTarget);
                apAnimRef->Extra()->ExtraDataList_SetOpenCloseActivateRef(0);
                if (openTarget == player && openHandler && openHandler->IsSpecial())
                    player->Reset(false);
            }
            if (*setting.Bool() && apAnimRef->Base()->GetFormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Open(apAnimRef);
                else
                    ObstacleManager::GetSingleton()->Open(apAnimRef);
            }
        }
        else if (!CompareEvent(apEndSeq->GetName(), "Close"))
        {
            handled = true;
            SetEventFlags(apAnimRef, apAnimRef->Extra(), 0x20000);
            Ref* closeTarget = apAnimRef->Extra()->GetTarget();
            if (closeTarget)
            {
                OpenCloseHandler* closeHandler = GetHandler(apAnimRef->Base());
                if (closeHandler)
                    closeHandler->Close(apAnimRef, closeTarget);
                apAnimRef->Extra()->ExtraDataList_SetOpenCloseActivateRef(0);
            }
            if (*setting.Bool() && apAnimRef->Base()->GetFormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Close(apAnimRef);
                else
                    ObstacleManager::GetSingleton()->Close(apAnimRef);
            }
        }
    }
}
