#pragma once

class BSExtraData;

// pdb: class BaseExtraList, size 0x20, 2 members
class BaseExtraList
{
public:
    virtual void* vf00(unsigned int flags);

    BSExtraData* pHead;
    unsigned char iFlags[21];
    unsigned char layoutPadding1D;
    unsigned short layoutPadding1E;

    BSExtraData* GetExtraData(unsigned char type);
    BSExtraData* GetExtraData(unsigned char type) const;
    BSExtraData* AddExtra(BSExtraData* extra);
    bool HasExtraData(unsigned char type);
    void RemoveExtra(unsigned char acType);
    void RemoveExtra(unsigned int acType);
};
