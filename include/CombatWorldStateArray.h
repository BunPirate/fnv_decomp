#pragma once

// CombatWorldStateArray: real name (was CombatStateArray). Its 3 bound methods are CombatWorldStateArray::* in the names DB; ctor 0x009aa470.

// pdb: class CombatWorldStateArray, size 0x5c, 2 members
class CombatWorldStateArray
{
public:
    char iValues[0x50];
    char iSpecifiedVariables[0x0C];

    void __thiscall CopyFrom(CombatWorldStateArray* apWorldStateArray);
    CombatWorldStateArray* CombatWorldStateArray_0(CombatWorldStateArray*);
    bool CombatWorldStateArray_IsTrue(unsigned int, int);
};
