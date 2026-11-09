// fallout_shared/tempeffects/bstempeffect.cpp: SandBoxActorPackageData, BSTempEffect (14 functions)

#include "../../../include/BSTempEffect.h"
#include "../../../include/SandBoxActorPackageData.h"
#include "bstempeffect_decls.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESSaveLoadGame.h"

// @fnv 0x009f3a30
PTYPE SandBoxActorPackageData::GetPackageType()
{
    return PTYPE_SANDBOX;
}

// @fnv 0x006827b0
// pdb: BSTempEffect::BSTempEffect | BSTempEffect.obj | retail, upstream name already matches, high
// pdb params: apCell, afLifetime
BSTempEffect::BSTempEffect(TESObjectCELL* apCell, float afLifetime)
{
    pCell = apCell;
    m_fParticleParameter5 = afLifetime;
    fAge = 0.0f;
    bInitialized = false;
}

// @fnv 0x00682860
// pdb: BSTempEffect::~BSTempEffect | BSTempEffect.obj | debug, upstream name already matches, high
BSTempEffect::~BSTempEffect()
{
    pCell = 0;
    m_fParticleParameter5 = 0.0f;
    fAge = 0.0f;
    bInitialized = false;
}

// @fnv 0x009cbb10
int BSTempEffect::GetType()
{
    return 3;
}

extern const char* const g_011d6a90_arg1;

// @fnv 0x00682800
const NiRTTI* BSTempEffect::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011d6a90_arg1);
}

// @fnv 0x006828e0
unsigned short BSTempEffect::GetSaveSize()
{
    unsigned short usSize = 0;
    usSize += 4;
    usSize += 4;
    usSize += 4;
    return usSize;
}

// @fnv 0x00682a80
// pdb: BSTempEffect::LoadGame | BSTempEffect.obj | debug, call graph, low
// pdb params: apLoadGameBuffer
void BSTempEffect::LoadGame(BGSLoadGameBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((void*)&m_fParticleParameter5, 4u);
    apLoadGameBuffer->ReadTypedData((void*)&fAge, 4u);
    apLoadGameBuffer->ReadTypedData((void*)&bInitialized, 1u);
}

// @fnv 0x00682810
void BSTempEffect::Initialize()
{
    bInitialized = true;
}

// @fnv 0x006828a0
bool BSTempEffect::Update(float afTimeDelta)
{
    fAge += afTimeDelta;
    if (fAge > m_fParticleParameter5)
        return false;
    return true;
}

// @fnv 0x00682a30
// pdb: BSTempEffect::SaveGame | BSTempEffect.obj | debug, call graph, low
// pdb params: apSaveGameBuffer
void BSTempEffect::SaveGame(BGSSaveGameBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((void*)&m_fParticleParameter5, 4, 0);
    apSaveGameBuffer->SaveData((void*)&fAge, 4, 0);
    apSaveGameBuffer->SaveData((void*)&bInitialized, 1, 0);
}

struct SoundH
{
    void* pBase;
    unsigned int m_uiReadOffset;
    void* pCell;
    void* Deallocate();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x00682920
// pdb: BSTempEffect::SaveGame | BSTempEffect.obj | debug, object-file run extension, low
// pdb locals: icellID
void BSTempEffect::SaveGame()
{
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&m_fParticleParameter5, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&fAge, 4);
    SoundH* apSaveGameBuffer = 0;
    if (pCell)
    {
        apSaveGameBuffer = (SoundH*)((SoundH*)pCell)->Deallocate();
    }
    g_TESSaveLoadGame->TESSaveLoadGame_SaveNumericID((int)&apSaveGameBuffer, 4);
}

TESForm* TESForm_GetFormByNumericID(unsigned int);

// @fnv 0x00682990
// pdb: BSTempEffect::LoadGame | BSTempEffect.obj | debug, object-file run extension, low
// pdb locals: bvalid, icellID
bool BSTempEffect::LoadGame()
{
    bool result = true;
    unsigned int formID;

    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&m_fParticleParameter5, 4);
    g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&fAge, 4);
    g_TESSaveLoadGame->FUN_00857aa0(&formID, 4);

    pCell = dynamic_cast<TESObjectCELL*>(TESForm_GetFormByNumericID(formID));

    if (!pCell || !pCell->Get3D_00545cb0())
        result = false;

    return result;
}
