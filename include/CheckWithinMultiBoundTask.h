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

    TESObjectREFR* pBoundRef;
    NiPointer<NiAVObject> sp3D;
    NiPointer<NiAVObject> spBound;
    char bWithin;
};
