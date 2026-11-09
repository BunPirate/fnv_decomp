#ifndef FNV_FALLOUT_SHARED_SKY_SKY_H
#define FNV_FALLOUT_SHARED_SKY_SKY_H

#include "sky_Dependencies.h"

// @fnv 0x0046dd00
// pdb: Sky::GetInstance | TESDataHandler.obj | retail, upstream name already matches, high
// pdb locals: tempMemContext
Sky* Sky::GetInstance()
{
    if (!pInstance)
    {
        AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true, "..\\Fallout Shared\\Sky\\Sky.h", 0x118);
        pInstance = new Sky;
    }
    return pInstance;
}

// @fnv 0x0059e950
// pdb: Sky::IsRaining | TESConditionFunctions.obj | debug, upstream name already matches, high
bool Sky::IsRaining()
{
    return (pCurrentWeather && pCurrentWeather->IsRainy() &&
            fCurrentWeatherPct > pCurrentWeather->GetWeatherData(6, 0.999f, 0.0f)) ||
           (pLastWeather && pLastWeather->IsRainy() &&
            fCurrentWeatherPct < pLastWeather->GetWeatherData(7, 1.0f, 0.001f));
}
#endif
