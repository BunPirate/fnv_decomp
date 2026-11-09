#pragma once

#include "BaseFormComponent.h"

class BGSListForm;
class TESForm;

// pdb: class BGSBipedModelList, size 0x8, bases: BaseFormComponent, 1 members
class BGSBipedModelList : public BaseFormComponent
{
public:
    BGSBipedModelList();
    ~BGSBipedModelList();

    void Init() override;
    void Free() override;
    void CopyFromBase(BaseFormComponent* component) override;
    bool CompareWithBase(BaseFormComponent* component) override;

    void InitItem(TESForm* apOwner);
    void SetBipedModelList(BGSListForm* list);
    BGSListForm* GetList();
    static BGSBipedModelList* GetFormAsBipedModelList(TESForm* apForm);

    BGSListForm* pListForm;
};
