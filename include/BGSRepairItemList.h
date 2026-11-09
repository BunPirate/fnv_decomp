#pragma once

#include "BaseFormComponent.h"

class BGSListForm;
class TESForm;

// pdb: class BGSRepairItemList, size 0x8, bases: BaseFormComponent, 1 members
class BGSRepairItemList : public BaseFormComponent
{
public:
    BGSRepairItemList();
    ~BGSRepairItemList();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    void InitializeComponent();
    void InitItem(TESForm* apOwner);
    void SetRepairList(BGSListForm* list);
    void SetRepairItemList(BGSListForm* list);

    BGSListForm* pListForm;
};
