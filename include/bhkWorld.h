#pragma once

#include "bhkSerializable.h"

class NiAVObject;
class TESObjectREFR;
class WorldExt;

// pdb: class bhkWorld, size 0xa0, bases: bhkSerializable, 25 members
class bhkWorld : public bhkSerializable
{
public:
    virtual ~bhkWorld();

    virtual void* v37(); // EAX pointer: bhkSerializable 0x00c87a40, bhkWorld 0x00d47a30
    virtual void vf49();
    virtual bool vf50(TESObjectREFR* refr);
    virtual void vf51();
    virtual void AddObject(NiAVObject* object, bool a, bool b, int c, bool d);
    virtual void vf53();
    virtual void vf54();

    WorldExt* GetHkpWorld() throw();
    void AddObject(NiAVObject* object, bool a, bool b, int c, int d);
    void AddBatchedConstraints() throw();
    void ReleaseBodies();
    void ClearReferences();
    void RemoveBatchedEntities();
    void FlushEntries() throw();
    void SetProcessEnabled(int arg) throw();
    void SetWorldActive(bool arg);
    void RefreshWorld();
    bool StepSimulation();
    static bool __cdecl QPickCountOverride();

    void bhkWorld_SaveSnapshot(const char* apFileName);
    void bhkWorld_AddEntities(void* p, unsigned int count) throw();
    void bhkWorld_AddBatchedActions() throw();
    void bhkWorld_UpdateActions(float f) throw();
    void bhkWorld_ScaleSolverInfo() throw();
    void bhkWorld_UpdateListeners(float f) throw();
    void bhkWorld_UpdateDebugger() throw();
    void bhkWorld_StopBatchingAdds(bool);
    void bhkWorld_StartBatchingRemovals();
    void bhkWorld_StartBatchingAdds();

    unsigned int unk0C;
    void* pDebugger;
    bool bAdded; // src: XBOX_RETAIL_PDB +0x14 (old: bStateChanged)
    bool bEnabled;
    bool bDebugDisplay; // src: XBOX_RETAIL_PDB +0x16 (old: m_bFlagAt16)
    char _pdbpad_17[1];
    unsigned int iBatchAdd; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiValueAt18)
    unsigned int iBatchRemove; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiReferenceCount)
    void* pTrapListener;
    void* pWaterListener; // src: XBOX_RETAIL_PDB +0x24 (old: m_pObjectAt24)
    void* pAcousticSpaceListener; // src: XBOX_RETAIL_PDB +0x28 (old: m_pObjectAt28)
    void* pEntityBatch; // src: XBOX_RETAIL_PDB +0x2c (old: m_pObjectAt2C)
    unsigned int iEntityBatchCount; // src: XBOX_RETAIL_PDB +0x30 (old: m_uiValueAt30)
    void* pPhantomBatch; // src: XBOX_RETAIL_PDB +0x34 (old: m_pObjectAt34)
    unsigned int iPhantomBatchCount; // src: XBOX_RETAIL_PDB +0x38 (old: m_uiValueAt38)
    void* pActionBatch; // src: XBOX_RETAIL_PDB +0x3c (old: m_pObjectAt3C)
    unsigned int iActionBatchCount; // src: XBOX_RETAIL_PDB +0x40 (old: m_uiValueAt40)
    void* pConstraintInstanceBatch; // src: XBOX_RETAIL_PDB +0x44 (old: m_pObjectAt44)
    unsigned int iConstraintInstanceBatchCount; // src: XBOX_RETAIL_PDB +0x48 (old: m_uiValueAt48)
    void* pEntityRemoveBatch; // src: XBOX_RETAIL_PDB +0x4c (old: m_pObjectAt4C)
    unsigned int iEntityRemoveBatchCount; // src: XBOX_RETAIL_PDB +0x50 (old: m_uiValueAt50)
    char _pdbpad_54[12];
    char Origin[16];
    char pEntityListenerA[12]; // src: XBOX_RETAIL_PDB +0x70 (old: m_achDataAt70)
    char DebugColorA[12]; // src: XBOX_RETAIL_PDB +0x7c (old: m_achDataAt7C)
    float fOriginalTau; // src: XBOX_RETAIL_PDB +0x88 (old: m_fValueAt88)
    float fOriginalDamping; // src: XBOX_RETAIL_PDB +0x8c (old: m_fValueAt8C)
    char ActionList[8]; // src: XBOX_RETAIL_PDB +0x90 (old: ActionEntryList)
    char _pdbpad_98[8];
};
