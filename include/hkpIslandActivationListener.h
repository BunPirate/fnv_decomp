#pragma once

// pdb: class hkpIslandActivationListener, size 0x4, 0 members
class hkpIslandActivationListener
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void vf01() = 0;
    virtual void vf02() = 0;

    void InitPtr();
};
