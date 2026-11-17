
#include "ailineartaskthread_decls.h"
// @fnv 0x008c7630
// pdb: AILinearTaskThread::AILinearTaskThread | AILinearTaskThreadManager.obj | retail, upstream name already matches, high
// pdb params: apfnTaskFunc
AILinearTaskThread::AILinearTaskThread(void(__cdecl* taskFunction)())
{
    m_pTaskFunction = taskFunction;
}
