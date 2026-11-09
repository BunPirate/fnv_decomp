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
    Actor* pActor;
    BSSimpleList<DetectionViewData*>* pWitnesses;
    NiPoint3 kOrigin;
    union
    {
        unsigned int m_14;
        int m_iFadeIndex;
    };
    int iRefCount;

    ActorCause(Actor* actor);
    ~ActorCause();

    void IncRefCount();
    unsigned int DecRefCount();
    unsigned short GetCount();
    void ActorCause_InitLoadGame(int apLoadGameBuffer);
    unsigned short GetRefCount_0047d3d0();
    ActorCause* UpdateState_0066e010(Actor* actor);

    static void ClearActorCauseList(BGSLoadGameBuffer* buffer);
    static void SaveActorCauses(BGSLoadGameBuffer* buffer);
    static void LoadReferencesFromBuffer(BGSLoadGameBuffer* buffer);

    static BSSimpleList<ActorCause*> ms_kActorCauseList;
};
