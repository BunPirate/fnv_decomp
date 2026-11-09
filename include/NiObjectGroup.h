#pragma once

// pdb: class NiObjectGroup, size 0x10, bases: NiMemObject, 4 members
class NiObjectGroup
{
public:
    unsigned int m_uiSize;
    void* m_pvBuffer;
    void* m_pvFree;
    unsigned int m_uiRefCount;

    void ForwardCall_00a8a670();
    void* Allocate(unsigned int);
    void DecRefCount();
    void SetSize(unsigned int);
    unsigned int GetSize();
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
};
