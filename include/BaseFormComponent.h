#pragma once

// pdb: class BaseFormComponent, size 0x4, 0 members
class BaseFormComponent
{
public:
    BaseFormComponent();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
