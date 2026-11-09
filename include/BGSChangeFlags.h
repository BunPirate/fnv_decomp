#pragma once

class TESForm;

// pdb: class BGSChangeFlags, size 0x4, 1 members
struct BGSChangeFlags
{
public:
    unsigned int iFlags;

    BGSChangeFlags();
    BGSChangeFlags(unsigned int auiFlags);
    BGSChangeFlags(int v);
    BGSChangeFlags(const BGSChangeFlags& o);
    bool Test(unsigned int auiFlag);
    bool TestFormChangeFlags(TESForm* form);
    void AddFlags(int flags);
    unsigned int GetFlags();
};
