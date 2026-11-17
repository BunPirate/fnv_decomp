#include "../../include/IOManager.h"
#include "../../include/ExteriorCellLoaderTask.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiNode.h"
#include "../../include/TES.h"
#include "../../include/TESWorldSpace.h"
#include "../../include/TESObjectCELL.h"

// src/fallout_shared/exteriorcellloader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/exteriorcellloader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00527ce0
// src: XBOX_PDB 0x00527ce0
void __thiscall ExteriorCellLoaderTask::Finish_00527ce0()
{
    ((IOManager*)this)->SubmitTask();
}

struct IntPoint2D
{
    int iX;
    int iY;
};


extern "C" char* __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the cell coordinates of the task's cell into apDescription using _sprintf_s and returns true.
// @fnv 0x00527df0
// pdb: ExteriorCellLoaderTask::GetDescription | ExteriorCellLoader.obj | retail, string-set bridge, high
// pdb params: apDescription, aiBufferSize
bool ExteriorCellLoaderTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "ExteriorCellLoaderTask for cell ( %i, %i )",
               ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iY);
    return true;
}

// TES.h exposes the flag but does not declare this accessor.
// @fnv 0x00528790
char __fastcall GetTESRegionState(TES* tes)
{
    return (char)tes->bShowLANDborders;
}

struct FUN_005287e0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    bool BSTask_IsCompleted();
};

// @fnv 0x005287e0
// src: COMMUNITY 0x005287e0
bool FUN_005287e0_shell::BSTask_IsCompleted()
{
    return m_0c == 5;
}

extern int DAT_0102d078;

struct FUN_00528800_shell
{
    int m_val;
    void UpdateFields_00528800();
};

// @fnv 0x00528800
// src: GUESS 0x00528800 (confidence: low)
void FUN_00528800_shell::UpdateFields_00528800()
{
    m_val = (int)&DAT_0102d078;
}

struct FUN_00528820_shell
{
    void ClearField();
};

// @fnv 0x00528820
void FUN_00528820_shell::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = 0;
}

extern "C" void __cdecl _Deallocate(void*);

// @fnv 0x00527c70
// pdb: ExteriorCellLoaderTask::~ExteriorCellLoaderTask | ExteriorCellLoader.obj | retail, upstream name already matches, high
ExteriorCellLoaderTask::~ExteriorCellLoaderTask()
{
    char* p = *(char**)((char*)this + 0x1c);
    _Deallocate(p);
}

extern int g_TES;

struct FUN_005287b0_shell
{
    void ExteriorCellLoader_AttachLoadedCell(TESObjectCELL* apCell);
};

// If the cell has a node, add it to the TES cell buffer.
// @fnv 0x005287b0
// src: XBOX_PDB 0x005287b0
// pdb: ExteriorCellLoader::AttachLoadedCell | ExteriorCellLoader.obj | retail, upstream name already matches, high
// pdb params: apCell
void FUN_005287b0_shell::ExteriorCellLoader_AttachLoadedCell(TESObjectCELL* apCell)
{
    if (apCell)
    {
        if (apCell->Get3D_00545cb0())
        {
            ((TES*)g_TES)->AddToBuffer(apCell);
        }
    }
}

struct DH
{
    void DeleteObject(TESObjectCELL* apCell);
};
extern DH* g_dataHandler;
// @fnv 0x00527d80
// pdb: ExteriorCellLoaderTask::Cancel | ExteriorCellLoader.obj | retail, upstream name already matches, high
// pdb params: aePreviousState, apTaskOwner
void ExteriorCellLoaderTask::Cancel(BS_TASK_STATE, void*)
{
    if (*(int*)(*(char**)((char*)this + 0x1c) + 0xc) && ((TES*)g_TES)->IsCellBuffered((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc), false))
        g_dataHandler->DeleteObject((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc));
    (*(TESWorldSpace**)((char*)this + 0x18))->GetCellAtGridCoord(((IntPoint2D*)*(void**)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(void**)((char*)this + 0x1c))->iY);
}

struct FUN_00528840_shell : public FUN_00528800_shell
{
    void* FUN_00528840(unsigned int flags);
};

// Calls FUN_00528800, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00528840
// pdb: LockFreeMap<unsigned int,NiPointer<ExteriorCellLoaderTask> >::LockFreeMapIterator::`scalar deleting destructor' | ExteriorCellLoader.obj | retail, vtable slot, high
void* FUN_00528840_shell::FUN_00528840(unsigned int flags)
{
    UpdateFields_00528800();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LoaderDummy
{
    void ExteriorCellLoader_LoadCellData(IntPoint2D* apCellData);
};
struct MyCellEx
{
    char _pad[0xC];
    TESObjectCELL* pObj;
};
// @fnv 0x00527cb0
// pdb: ExteriorCellLoaderTask::Run | ExteriorCellLoader.obj | retail, upstream name already matches, high
void ExteriorCellLoaderTask::Run()
{
    (*(LoaderDummy**)((char*)this + 0x18))->ExteriorCellLoader_LoadCellData(*(IntPoint2D**)((char*)this + 0x1c));
    ((MyCellEx*)*(void**)((char*)this + 0x1c))->pObj->QueueReferences(1);
}

// @fnv 0x00527d00
// pdb: ExteriorCellLoaderTask::PostProcess | ExteriorCellLoader.obj | retail, vtable slot, high
void ExteriorCellLoaderTask::Finish()
{
    if (!IOTask::BSTask_int64_GetTaskCanceled())
    {
        if (*(int*)(*(char**)((char*)this + 0x1c) + 0xc) != 0)
        {
            if (*(unsigned char*)(*(char**)((char*)this + 0x1c) + 0x10) != 0)
            {
                (*(FUN_005287b0_shell**)((char*)this + 0x18))->ExteriorCellLoader_AttachLoadedCell((TESObjectCELL*)*(int*)(*(char**)((char*)this + 0x1c) + 0xc));
            }
        }
    }
    *(char*)(*(char**)((char*)this + 0x1c) + 0x10) = 0;
    (*(TESWorldSpace**)((char*)this + 0x18))->GetCellAtGridCoord(*(int*)*(void**)((char*)this + 0x1c), *(int*)(*(char**)((char*)this + 0x1c) + 4));
}

struct CellEffects;
struct WorldSpaceAccess : TESWorldSpace
{
    CellEffects* __thiscall TESWorldSpace_LoadCell(int aiX, int aiY);
};
// FUN_00546fb0 returns landscape data, not a scene node.
struct LandscapeEffects
{
    void __thiscall TESObjectLAND_LoadVertices(bool abLoad3D);
    void __thiscall TESObjectLAND_DrawLandBorder(unsigned char bShow);
    void __thiscall TESObjectLAND_GetMinMaxLandHeight();
};
// Supplemental method declarations absent from the shared TESObjectCELL header.
// This adds no fields or virtual functions to the shared cell layout.
struct CellEffects : TESObjectCELL
{
    void __thiscall GetOrCreateWidget();
    LandscapeEffects* __thiscall TESObjectCELL_GetLand();
    LandscapeEffects* __thiscall TESObjectCELL_GetLand(NiPoint2* outPosition);
    bool __thiscall TESClimate_GetVolatilityIndex();
    float __thiscall TESObjectCELL_GetWaterHeight();
    void __thiscall SetFlag2(bool value);
    bool __thiscall FUN_004518e0();
    void __thiscall SetByteAt54(bool value);
};
struct GameWorld : TES
{
    CellEffects* __thiscall FUN_00461330(int mode, int x, int y, WorldSpaceAccess* worldSpace);
};
extern GameWorld* DAT_011c3f2c;
extern TES* DAT_011dea10;
struct GlobalSettings
{
    unsigned char* __thiscall FUN_00408d60();
};
extern GlobalSettings DAT_011c7adc;
void __cdecl BGSAutoWater_GeneratePlaceableWaterForCell(CellEffects* apCell);
struct CellLoadData : IntPoint2D
{
    WorldSpaceAccess* worldSpace;
    CellEffects* cell;
    bool loaded;
};
struct CellLoader
{
    void __thiscall ExteriorCellLoader_LoadCellData(CellLoadData* apCellData);
};
// @fnv 0x00528620
// src: XBOX_PDB 0x00528620
// pdb: ExteriorCellLoader::LoadCellData | ExteriorCellLoader.obj | retail, upstream name already matches, high
// pdb params: apCellData
// pdb locals: pland, extents
void CellLoader::ExteriorCellLoader_LoadCellData(CellLoadData* apCellData)
{
    if (apCellData != 0)
    {
        if (apCellData->cell == 0)
            apCellData->cell = apCellData->worldSpace->TESWorldSpace_LoadCell(apCellData->iX, apCellData->iY);
        if (apCellData->cell == 0)
            apCellData->cell = DAT_011c3f2c->FUN_00461330(0, apCellData->iX, apCellData->iY, apCellData->worldSpace);
        apCellData->cell->GetOrCreateWidget();
        LandscapeEffects* pLandscape = apCellData->cell->TESObjectCELL_GetLand();
        if (pLandscape != 0)
        {
            pLandscape->TESObjectLAND_LoadVertices(true);
            pLandscape->TESObjectLAND_DrawLandBorder(GetTESRegionState(DAT_011dea10));
        }
        if (!apCellData->cell->TESClimate_GetVolatilityIndex())
        {
            // Avoid invoking NiPoint2's out-of-line default constructor.
            float position[2];
            apCellData->cell->TESObjectCELL_GetLand((NiPoint2*)position)->TESObjectLAND_GetMinMaxLandHeight();
            apCellData->cell->SetFlag2(position[0] < apCellData->cell->TESObjectCELL_GetWaterHeight());
            if (*DAT_011c7adc.FUN_00408d60() && apCellData->cell->FUN_004518e0() && !apCellData->cell->TESClimate_GetVolatilityIndex())
            {
                BGSAutoWater_GeneratePlaceableWaterForCell(apCellData->cell);
            }
            apCellData->cell->SetByteAt54(true);
        }
        apCellData->loaded = true;
    }
}

void BSSleep(unsigned long auiMSec);
struct QueuedTask
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Run(int eState, void* pArg);
    int m_04;
    int m_08;
    int m_eAnimationState;
    bool BSTask_int64_SwitchState(int eExpected, int eNew);
    void Model_IncManualRefCount();
    void BSTask_int64_DecRefCount();
};
struct FUN_00528870_shell
{
    void BSTaskManager_int64_RemoveTask(QueuedTask* pTask);
    bool BSTaskManager_int64_TryCancelTask(QueuedTask* apTask, void* apTaskOwner);
};

// @fnv 0x00528870
// src: XBOX_DEBUG_PDB 0x00528870
// pdb: BSTaskManager<__int64>::TryCancelTask | ExteriorCellLoader.obj | debug, call graph (shared callers), high
// pdb params: apTask, apTaskOwner
// pdb locals: estate
bool FUN_00528870_shell::BSTaskManager_int64_TryCancelTask(QueuedTask* apTask, void* apTaskOwner)
{
    while (true)
    {
        int eState = apTask->m_eAnimationState;
        switch (eState)
        {
        case 0:
            if (apTask->BSTask_int64_SwitchState(eState, 6))
            {
                apTask->Run(eState, apTaskOwner);
                return true;
            }
            break;
        case 1:
            if (apTask->BSTask_int64_SwitchState(eState, 6))
            {
                apTask->Model_IncManualRefCount();
                BSTaskManager_int64_RemoveTask(apTask);
                apTask->Run(eState, apTaskOwner);
                apTask->BSTask_int64_DecRefCount();
                return true;
            }
            break;
        case 2:
            while (apTask->m_eAnimationState == 3)
                BSSleep(0);
            break;
        case 3:
        case 4:
            return false;
        case 5:
            if (apTask->BSTask_int64_SwitchState(eState, 6))
            {
                apTask->Run(eState, apTaskOwner);
                return true;
            }
            break;
        case 6:
            return true;
        default:
            return true;
        }
    }
    return true;
}
