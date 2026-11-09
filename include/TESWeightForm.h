#pragma once

#include "BaseFormComponent.h"

class TESForm;

// pdb: class TESWeightForm, size 0x8, bases: BaseFormComponent, 1 members
class TESWeightForm : public BaseFormComponent
{
public:
    TESWeightForm();
    ~TESWeightForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    static float GetWeightForForm(TESForm* apForm, bool abIsHardcore);
    float GetWeightForForm();
    float GetWeightForForm() const;
    void SetFormWeight(float weight);

    float fWeight;
};
