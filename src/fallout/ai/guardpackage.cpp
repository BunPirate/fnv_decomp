// fallout/ai/guardpackage.cpp: GuardActorPackageData, std (6 functions)

#include "../../../include/Actor.h"
#include "../../../include/GuardActorPackageData.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/TESForm.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "guardpackage_decls.h"
// @fnv 0x00408840
double std::abs(float value)
{
    return fabsf_00408860(value);
}
// Reads eState, a second dword, iWarningCount and a trailing value from the load buffer.
// @fnv 0x009f28b0
// pdb: GuardActorPackageData::LoadGame | GuardPackage.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void GuardActorPackageData::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&eState), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fGuardTimer), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&iWarningCount), 4u);
    apLoadGameBuffer->ReadFormIdentifier(&pGuardWarnedActor);
}
// Resolves the stored form reference to an Actor and, if found, calls the reference helper with true.
// @fnv 0x009f2900
// pdb: GuardActorPackageData::InitLoadGame | GuardPackage.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void GuardActorPackageData::InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    pGuardWarnedActor =
        pGuardWarnedActor ? dynamic_cast<Actor*>(TESForm::GetFormByID((unsigned int)pGuardWarnedActor)) : 0;
    if (pGuardWarnedActor)
        ((TESObjectREFRHelper*)pGuardWarnedActor)->SetTargetingState(true);
}

// Saves the guard state, warning timer, warning count and warning target.
// @fnv 0x009f2850
// pdb: GuardActorPackageData::SaveGame | GuardPackage.obj | retail, upstream name already matches, high
// pdb params: apSaveGameBuffer
void GuardActorPackageData::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&eState, 4, 0);
    apSaveGameBuffer->SaveData(&fGuardTimer, 4, 0);
    apSaveGameBuffer->SaveData(&iWarningCount, 4, 0);
    apSaveGameBuffer->SerializeFormData(pGuardWarnedActor, 0);
}

void _Deallocate(void*);

// @fnv 0x009f2800
// pdb: GuardActorPackageData::`scalar deleting destructor' | GuardPackage.obj | debug, vtable slot, medium
void* GuardActorPackageData::DestroyIfFlagged(unsigned int flags)
{
    this->~GuardActorPackageData();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009f2830
// pdb: GuardActorPackageData::~GuardActorPackageData | GuardPackage.obj | debug, upstream name already matches, high
GuardActorPackageData::~GuardActorPackageData()
{
}
