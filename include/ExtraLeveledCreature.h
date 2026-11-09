#pragma once

#include "BSExtraData.h"

class TESActorBase;

// pdb: class ExtraLeveledCreature, size 0x14, bases: BSExtraData, 2 members
class ExtraLeveledCreature : public BSExtraData
{
public:
    virtual ~ExtraLeveledCreature();

    TESActorBase* m_pCreatureBase;
    TESActorBase* pTemplate;
};
