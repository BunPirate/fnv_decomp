// gamebryo2.2/corelibs/nimain/niscreenelements.cpp: TaskQueueInterface (1 function)
#include "niscreenelements_flags.h"

// @fnv 0x005467c0
// src: XBOX_DEBUG_PDB 0x005467c0
// pdb: NiAVObject::SetFixedBound | TESObjectCELL.obj | debug, call graph, high
// pdb params: abTF
void TaskQueueInterface::NiAVObject_SetFixedBound(bool abTF)
{
    SetTaskFlagDWord(abTF, 0x2000);
}
