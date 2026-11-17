#pragma once

#include "BSSimpleList.h"
#include "NiPoint3.h"

class Actor;
class BGSLoadGameBuffer;
class DetectionViewData;

// pdb: class ActorCause, size 0x1c, 5 members
class ActorCause
{
public:
    Actor* pActor; // src: XBOX_RETAIL_PDB +0x0 (old: m_00)
    BSSimpleList<DetectionViewData*>* pWitnesses; // src: XBOX_RETAIL_PDB +0x4 (old: m_04)
    NiPoint3 kOrigin; // src: XBOX_RETAIL_PDB +0x8 (old: m_08)
    union
    {
        unsigned int m_14;
        int m_iFadeIndex;
    };
    int iRefCount; // src: XBOX_RETAIL_PDB +0x18 (old: m_18)

    ActorCause(Actor* actor);
    ~ActorCause();

    void IncRefCount();
    unsigned int DecRefCount();
    unsigned short GetCount();
    void InitLoadGame(int apLoadGameBuffer);
    unsigned short GetRefCount_0047d3d0();
    ActorCause* UpdateState_0066e010(Actor* actor);

    static void ClearActorCauseList(BGSLoadGameBuffer* buffer);
    static void SaveActorCauses(BGSLoadGameBuffer* buffer);
    static void LoadReferencesFromBuffer(BGSLoadGameBuffer* buffer);

    static BSSimpleList<ActorCause*> ms_kActorCauseList;
};
