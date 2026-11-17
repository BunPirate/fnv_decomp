// fallout/ai/combat/combattimer.cpp: free functions (4 functions)

#include "combattimer_decls.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/CombatTargetTimestamp.h"
#include "../../../../include/TimeoutTimer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
// Reads a 4-byte timestamp from the load buffer and, if it is within the relative range, offsets it by the current game time.
// @fnv 0x009a5ff0
// pdb: CombatTimeStamp::LoadGame | CombatTimer.obj | retail, call graph, high
// pdb params: apLoadGameBuffer
void CombatTargetTimestamp::LoadGame(BGSLoadGameBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fTimeStamp), 4u);
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
        fTimeStamp = Actor::GetActorScale() + fTimeStamp;
}
// @fnv 0x009a5f20
// pdb: CombatTimer::LoadGame | CombatTimer.obj | retail, call graph, high
// pdb params: apLoadGameBuffer
void TimeoutTimer::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fStartTime), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fTargetTime), 4u);
    if (fStartTime < DAT_0108e360 && fStartTime > -DAT_0108e360)
        fStartTime = fStartTime + DAT_011f1bf0;
}

// @fnv 0x009a5eb0
// pdb: CombatTimer::SaveGame | CombatTimer.obj | retail, call graph, high
// pdb params: apSaveGameBuffer
// pdb locals: foffsetStartTime
void TimeoutTimer::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float foffsetStartTime = this->fStartTime;
    if (this->fStartTime < DAT_0108e360 && -DAT_0108e360 < this->fStartTime)
        foffsetStartTime -= DAT_011f1bf0;
    apSaveGameBuffer->SaveData(&foffsetStartTime, 4, 0);
    apSaveGameBuffer->SaveData(&this->fTargetTime, 4, 0);
}

// @fnv 0x009a5f90
// pdb: CombatTimeStamp::SaveGame | CombatTimer.obj | retail, call graph, high
// pdb params: apSaveGameBuffer
// pdb locals: foffsetTimeStamp
void CombatTargetTimestamp::SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float fSavedTimeStamp = fTimeStamp;
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
    {
        fSavedTimeStamp -= Actor::GetActorScale();
    }
    apSaveGameBuffer->SaveData(&fSavedTimeStamp, 4, 0);
}
