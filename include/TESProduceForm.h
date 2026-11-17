#pragma once

#include "BaseFormComponent.h"

class IngredientItem;
class TESForm;

// pdb: class TESProduceForm, size 0xc, bases: BaseFormComponent, 2 members
class TESProduceForm : public BaseFormComponent
{
public:
    ~TESProduceForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void SetAllProductionChances(void* apiChances);
    void Save();
    unsigned int GetIngredient();
    void InitItem(TESForm* apOwner);

    IngredientItem* pFormIngredient; // src: XBOX_RETAIL_PDB +0x4 (old: pIngredient)
    unsigned char iProduceChance[4]; // src: XBOX_RETAIL_PDB +0x8 (old: cProdChance)
};
