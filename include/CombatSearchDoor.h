#pragma once

// pdb: class CombatSearchDoor, size 0xc, 5 members
class CombatSearchDoor
{
public:
    char pDoor[0x0A]; // src: XBOX_RETAIL_PDB +0x0 (old: pad)
    bool bReserved; // +0xa (0x0098c780)
    unsigned char pad0B; // 12 bytes: BSSimpleArray<CombatSearchDoor>::SetSize 0x0069cea0 scales by 0xc (src: XBOX_PDB size 12)
};
