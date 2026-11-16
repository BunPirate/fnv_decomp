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

    bool bYielding; // src: XBOX_RETAIL_PDB +0x4 (old: m_bTaskYielded)

    void TaskYield();
    void* DestroyIfFlagged(unsigned int flags);
};
