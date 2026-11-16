#pragma once

class TESObjectCELL;

// pdb: class ExteriorCellLoader, size 0x1c (here 0x1), 1 members
class ExteriorCellLoader // src: XBOX_RETAIL_PDB 0x00527eb0 (first of 4 high-tier linked methods; old: TESQueuedCellManager)
{
public:
    void ExteriorCellLoader_CancelAllCellLoads();
    void ExteriorCellLoader_ClearData();
    void ExteriorCellLoader_QueueCellLoad(TESObjectCELL*);
    int QueuedCellCount();
    void PostProcessCompletedTasks();
    int ExteriorCellLoader_TryCancelTasks();
    void ExteriorCellLoader_WaitForTasks();
};
