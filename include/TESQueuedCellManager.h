#pragma once

class TESObjectCELL;

// pdb: class ExteriorCellLoader, size 0x1c (here 0x1), 1 members
class ExteriorCellLoader // src: XBOX_RETAIL_PDB (old: TESQueuedCellManager)
{
public:
    void ExteriorCellLoader_CancelAllCellLoads();
    void ExteriorCellLoader_ClearData();
    void ExteriorCellLoader_QueueCellLoad(TESObjectCELL*);
    int QueuedCellCount();
    void PostProcessCompletedTasks();
    int TryCancelTasks();
    void WaitForTasks();
};
