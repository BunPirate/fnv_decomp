#pragma once

// pdb: class NiImageReader, size 0x100, 1 members
class NiImageReader
{
public:
    virtual void vfn_0();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();

    unsigned char pad[124];
    unsigned char m_kReadCriticalSection[128]; // src: XBOX_RETAIL_PDB +0x80 (old: lock)

    NiImageReader();
};
