#pragma once

// pdb: class BSExtraData, size 0xc, 2 members
class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual bool Compare(BSExtraData* extra);

    BSExtraData(unsigned char type);
    void* __thiscall FUN_0040ecd0(unsigned int flags);

    unsigned char cEtype; // src: XBOX_RETAIL_PDB +0x4 (old: type)
    unsigned char unknown05;
    unsigned char unknown06;
    unsigned char unknown07;
    BSExtraData* pNext; // src: XBOX_RETAIL_PDB +0x8 (old: next)
};
