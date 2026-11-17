
#include "iomanager_decls.h"
// @fnv 0x0043d690
// pdb: IOTask::AddToPostProcessQueue | ModelLoader.obj | debug, call graph, medium
void IOManager::SubmitTask()
{
    DAT_01202d98->IOManager_AddPostProcessTask(this);
}
// @fnv 0x0043db70
// pdb: IOTask::GenerateKey | ModelLoader.obj | debug, upstream name already matches, high
void IOTask::GenerateKey()
{
    SetKey(3, InitScriptRunLockTask(), GetPriority(), IOTask_GetNextCounter());
}
