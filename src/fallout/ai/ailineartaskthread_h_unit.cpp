
#include "../../../include/AILinearTaskThread.h"
#include "../../../include/BSLinearTaskThread.h"
#include "../../../include/BSThread.h"
#include "../../../include/CountingSemaphore.h"
#include "../../../include/hkMemoryRouter.h"

// @fnv 0x008c7630
// pdb: AILinearTaskThread::AILinearTaskThread | AILinearTaskThreadManager.obj | retail, upstream name already matches, high
// pdb params: apfnTaskFunc
AILinearTaskThread::AILinearTaskThread(void(__cdecl* apfnTaskFunc)())
{
    m_pTaskFunction = apfnTaskFunc;
}
