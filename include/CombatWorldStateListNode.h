#pragma once

class UnsignedIdHandle;

class CombatWorldStateListNode
{
public:
    UnsignedIdHandle* item;
    CombatWorldStateListNode* next;

    void CombatWorldStateList_AddWorldState(int, int);
    void CombatWorldStateList_RemoveWorldState(int);
    CombatWorldStateListNode* GetNext();
    CombatWorldStateListNode* operator->();
};
