#pragma once

class ConstraintData;

// pdb: class hkSerializableCinfo, size 0x1 (here 0x10), 0 members
class hkSerializableCinfo
{
public:
    ConstraintData* data;
    int references;
    int unkc;
    int unk10;

    __forceinline hkSerializableCinfo()
        : data(0), references(1), unkc(0), unk10(0)
    {}
};
