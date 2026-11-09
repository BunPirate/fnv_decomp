#pragma once

class CombatPair;
class ObjectName;
class CombatWriter;
class SavedCombatState;

// pdb: class CombatTarget, size 0x68, 16 members
class CombatTarget
{
public:
    char pActor[0x68];

    void SetValue(unsigned int key, unsigned int x, unsigned int y);
    bool Lookup(unsigned int key, CombatPair* val);
    ObjectName* FUN_00413f40();
    void SaveGame_009856e0(CombatWriter*, SavedCombatState*);
};
