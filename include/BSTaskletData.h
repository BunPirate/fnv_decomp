#pragma once

// pdb: class BSTaskletData, size 0x8, 1 members
class BSTaskletData
{
public:
    BSTaskletData();
    virtual ~BSTaskletData();
    virtual bool StartTaskThread();
    virtual void Process();
    virtual void OnComplete();

    bool bYielding;

    void TaskYield();
    void* DestroyIfFlagged(unsigned int flags);
};
