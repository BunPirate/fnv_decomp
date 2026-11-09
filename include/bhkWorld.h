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
    void bhkWorld_AddBatchedConstraints() throw();
    void ReleaseBodies();
    void ClearReferences();
    void bhkWorld_RemoveBatchedEntities();
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
    bool bAdded;
    bool bEnabled;
    bool bDebugDisplay;
    char _pdbpad_17[1];
    unsigned int iBatchAdd;
    unsigned int iBatchRemove;
    void* pTrapListener;
    void* pWaterListener;
    void* pAcousticSpaceListener;
    void* pEntityBatch;
    unsigned int iEntityBatchCount;
    void* pPhantomBatch;
    unsigned int iPhantomBatchCount;
    void* pActionBatch;
    unsigned int iActionBatchCount;
    void* pConstraintInstanceBatch;
    unsigned int iConstraintInstanceBatchCount;
    void* pEntityRemoveBatch;
    unsigned int iEntityRemoveBatchCount;
    char _pdbpad_54[12];
    char Origin[16];
    char pEntityListenerA[12];
    char DebugColorA[12];
    float fOriginalTau;
    float fOriginalDamping;
    char ActionList[8];
    char _pdbpad_98[8];
};
