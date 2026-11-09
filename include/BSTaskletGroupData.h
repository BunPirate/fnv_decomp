#pragma once

// pdb: class BSTaskletGroupData, size 0x8 (here 0x4), 1 members
class BSTaskletGroupData
{
public:
    virtual void* DestroyIfFlagged(unsigned int flags);
    virtual void vf01();
    virtual void vf02();
};
