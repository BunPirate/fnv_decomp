#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "CaravanDeckData.h"

class TESCaravanCard;

// pdb: class TESCaravanDeck, size 0x2c, bases: TESForm, TESFullName, 2 members
class TESCaravanDeck : public TESForm, public TESFullName
{
public:
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;
    CaravanDeckData data;

    TESCaravanDeck();

    virtual bool Compare(TESForm* apCompare);

    void ResetFormData();
    bool Load(TESFile* apFile);
    BSSimpleList<TESCaravanCard*>* GetCardList();
    CaravanDeckData* GetDeckData();
};
