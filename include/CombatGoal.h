#pragma once

#include "CombatWorldStateListNode.h"

class CombatStateValues;
class UnsignedIdHandle;
template <class T> class BSSimpleList;

// pdb: class CombatGoal, size 0x1c, 4 members
class CombatGoal
{
public:
    enum COMBAT_GOAL
    {
        COMBAT_GOAL_STAY_IN_COMBAT_AREA = 0,
        COMBAT_GOAL_USE_COMBAT_ITEM = 1,
        COMBAT_GOAL_FLEE = 2,
        COMBAT_GOAL_AVOID_THREATS = 3,
        COMBAT_GOAL_ACTIVATE_COMBAT_ITEM = 4,
        COMBAT_GOAL_REACH_DESTINATION = 5,
        COMBAT_GOAL_GUARD = 6,
        COMBAT_GOAL_CLUSTER = 7,
        COMBAT_GOAL_ADVANCE = 8,
        COMBAT_GOAL_AMBUSH = 9,
        COMBAT_GOAL_FALLBACK = 10,
        COMBAT_GOAL_FLANK = 11,
        COMBAT_GOAL_FIND_TARGET = 12,
        COMBAT_GOAL_FLUSH_TARGET = 13,
        COMBAT_GOAL_KILL_TARGET = 14,
        COMBAT_GOAL_HIDE_FROM_TARGET = 15,
        COMBAT_GOAL_COUNT = 16
    };

    virtual bool vf00(CombatStateValues* apWorldStateArray);
    virtual void vf01(int, int);

    CombatGoal(COMBAT_GOAL eType);
    CombatGoal(int eType);
    ~CombatGoal();

    void FUN_0097ade0(int state, int value);
    void FUN_00984390(int state, int value);
    void SetProcedureType(int type);
    void* DestroyIfFlagged(unsigned int flags);
    int DestroyIfFlagged(int flags);

    BSSimpleList<UnsignedIdHandle*>* GetWorldStateList();
    static CombatGoal* CreateCombatGoal(COMBAT_GOAL aeCombatGoal);

    CombatWorldStateListNode ActivationConditions;
    CombatWorldStateListNode GoalStates;
    COMBAT_GOAL eType;
    unsigned int iGroupStrategyAssignment;
};
