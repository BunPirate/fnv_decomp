#pragma once

// pdb: structure PerkData, size 0x5 (here 0x8), 5 members
class PerkData
{
public:
    bool m_bTrait;
    unsigned char cLevel;
    unsigned char m_ucRankCount;
    bool bPlayable;
    bool bHidden;
    unsigned char padding[3];

    int GetType();
    unsigned char GetEntryList();
};
