#pragma once

// pdb: class NiObjectGroup, size 0x10, bases: NiMemObject, 4 members
class NiObjectGroup
{
public:
    unsigned int m_uiSize;
    void* m_pvBuffer; // src: XBOX_RETAIL_PDB +0x4 (old: pvContextData)
    void* m_pvFree; // src: XBOX_RETAIL_PDB +0x8 (old: m_pBeforeRefCount)
    unsigned int m_uiRefCount;

    void ForwardCall_00a8a670();
    void* Allocate(unsigned int);
    void DecRefCount();
    void SetSize(unsigned int);
    unsigned int GetSize();
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
};
