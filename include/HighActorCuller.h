#pragma once

#include "MobIterOperator.h"
#include "BSFadeNodeCuller.h"
#include "NiAVObject.h"

class BSMultiBoundNode;
class BSMultiBound;
class BSMultiBoundSphere;

// pdb: class HighActorCuller, size 0x140 (here 0xa4), bases: MobIterOperator, 4 members
class HighActorCuller : public MobIterOperator
{
public:
    virtual void Operate(MobileObject* apMob);

    BSFadeNodeCuller m_kFadeNodeCuller;
    NiPointer<BSMultiBoundNode> m_pMultiBoundNode;
    NiPointer<BSMultiBound> m_pMultiBound;
    NiPointer<BSMultiBoundSphere> m_spMultiBoundSphere;
};
