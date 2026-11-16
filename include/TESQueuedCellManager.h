#pragma once

class TESObjectCELL;

// pdb: class ExteriorCellLoader, size 0x1c (here 0x1), 1 members
class ExteriorCellLoader // src: XBOX_DEBUG_PDB 0x00527fc0 (first debug link of 3 high-tier links to its methods; old: TESQueuedCellManager)
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
