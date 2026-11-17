// bscore/bstimer.cpp: free functions (4 functions)

#include "../../include/GameTimerRecord.h"

// The engine tick-count helper lives outside this unit; the PC build resolves
unsigned int gm_GetTickCount();

// kernel32 tick count, reached directly through the import address table.
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

// Decrements the reference count and, when it reaches zero, records elapsed tick counts for two timestamps.
// @fnv 0x00aa5040
// pdb: BSTimer::Enable | BSTimer.obj | retail, object-file run extension, high
// pdb locals: itickCount
void GameTimerRecord::Enable()
{
    if (cDisableCounter)
    {
        if (--cDisableCounter == 0)
        {
            unsigned int uiTickCount = GetTickCount();
            iLastTime = uiTickCount - iLastTime;
            iFirstTime = uiTickCount - iFirstTime;
        }
    }
}

// @fnv 0x00771520
// pdb: BSTimer::Update | HUDMainMenu.obj | debug, call graph (shared callers), high
void GameTimerRecord::Update()
{
    Update(gm_GetTickCount());
}

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;

// @fnv 0x00aa4db0
// pdb: BSTimer::SetGlobalTimeMultiplier | BSTimer.obj | debug, call graph, high
// pdb params: afMult, abNow
void GameTimerRecord::SetGlobalTimeMultiplier(float afMult, bool abNow)
{
    bool bUseGlobal = bUseGlobalTimeMultiplierTarget;
    if (bUseGlobal)
    {
        DAT_011ac3a4 = afMult;
        if (abNow)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else
    {
        DAT_011ac3a4 = afMult;
        if (afMult == DAT_011ac3a0)
        {
            return;
        }
        fDelta /= DAT_011ac3a0;
        DAT_011ac3a0 = afMult;
        fDelta *= DAT_011ac3a0;
    }
}

extern float DAT_011ac3a0;
extern float DAT_011ac3a4;
extern float DAT_011ac3ac;

// Moves DAT_011ac3a0 toward DAT_011ac3a4 by a fraction of DAT_011ac3ac, clamping so it does not overshoot the target.
// @fnv 0x00aa4e40
// pdb: BSTimer::UpdateGlobalTimeMultiplier | BSTimer.obj | debug, object-file gap fill, medium
void GameTimerRecord::UpdateGlobalTimeMultiplier()
{
    if (DAT_011ac3a0 < DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f + DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 > DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
    else if (DAT_011ac3a0 > DAT_011ac3a4)
    {
        DAT_011ac3a0 = (1.0f - DAT_011ac3ac) * DAT_011ac3a0;
        if (DAT_011ac3a0 < DAT_011ac3a4)
        {
            DAT_011ac3a0 = DAT_011ac3a4;
        }
    }
}
