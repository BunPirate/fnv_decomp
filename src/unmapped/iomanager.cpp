
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/IOTask.h"
#include "../../include/QueuedFile.h"
#include "../../include/QueuedFileLoad.h"
#include "../../include/QueuedMagicItem.h"

// @fnv 0x0043daa0
// pdb: QueuedFileLoad::Finish | ModelLoader.obj | debug, upstream name already matches, high
void QueuedFileLoad::Finish()
{
    QueuedFile::Finish();
}

// @fnv 0x0043db30
// pdb: QueuedMagicItem::QueuedMagicItem | ModelLoader.obj | debug, upstream name already matches, high
// pdb params: apMagicItem, apAVEffectSetting, aePriority
QueuedMagicItem::QueuedMagicItem(MagicItem* apMagicItem, EffectSetting* apAVEffectSetting, IO_TASK_PRIORITY aePriority) : QueuedFile(aePriority)
{
    pMagicItem = apMagicItem;
    pEffectSetting = apAVEffectSetting;
}

struct QHeadPtr
{
    IOTask* pHead;
    QHeadPtr(IOTask* pHead);
    ~QHeadPtr();
};
struct C_00449210
{
    void LockFreePriorityQueue_NiPointer_IOTask_Push(int, QHeadPtr*);
};
struct FUN_0043d6b0_shell
{
    void __thiscall IOManager_AddPostProcessTask(IOTask* apTask);
};
// Wraps aHead in a QHeadPtr and passes its priority and the wrapper to the object at this+0x64 via FUN_00449210.
// @fnv 0x0043d6b0
// src: XBOX_PDB 0x0043d6b0
// pdb: IOManager::AddPostProcessTask | ModelLoader.obj | retail, upstream name already matches, high
// pdb params: apTask
void FUN_0043d6b0_shell::IOManager_AddPostProcessTask(IOTask* apTask)
{
    QHeadPtr head(apTask);
    (*(C_00449210**)((char*)this + 0x64))->LockFreePriorityQueue_NiPointer_IOTask_Push(apTask->GetPriority(), &head);
}
