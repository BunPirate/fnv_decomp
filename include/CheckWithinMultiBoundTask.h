#pragma once

#include "IOTask.h"
#include "NiAVObject.h"

class TESObjectREFR;

// pdb: class CheckWithinMultiBoundTask, size 0x28, bases: IOTask, 4 members
class CheckWithinMultiBoundTask : public IOTask
{
public:
    CheckWithinMultiBoundTask(TESObjectREFR* pSource, NiAVObject* pObject);
    virtual ~CheckWithinMultiBoundTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void __thiscall FUN_0054ab60();
    void* __thiscall FUN_0054ab30(unsigned int flags);

    TESObjectREFR* pBoundRef; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    NiPointer<NiAVObject> sp3D; // src: XBOX_RETAIL_PDB +0x1c (old: unk1c)
    NiPointer<NiAVObject> spBound; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    char bWithin; // src: XBOX_RETAIL_PDB +0x24 (old: unk24)
};
