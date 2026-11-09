#pragma once

// pdb: class InterfacedClass, size 0x4, 0 members
class InterfacedClass
{
public:
    InterfacedClass();
    virtual ~InterfacedClass();
    virtual void* AllocateInterface(unsigned int auiThread) = 0;
};
