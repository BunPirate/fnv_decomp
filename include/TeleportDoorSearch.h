#pragma once

#include "AStarSearch.h"
#include "BSSimpleArray.h"
#include "PathingLocation.h"

class ParentSpaceNode;
class TeleportLink;
class TESWorldSpace;
class TESObjectCELL;
class TESObjectREFR;
class PathingActorData;

// pdb: class TeleportDoorSearch, size 0x20b8, bases: AStarSearch<ParentSpaceNode, 8 members
class TeleportDoorSearch : public AStarSearch<ParentSpaceNode, TeleportLink>
{
public:
    virtual ~TeleportDoorSearch();
    virtual bool CollectConnections(const AStarNode<ParentSpaceNode, TeleportLink>*,
        BSSimpleArray<AStarNode<ParentSpaceNode, TeleportLink>*, 1024>*);
    virtual bool HasReachedGoal(const AStarNode<ParentSpaceNode, TeleportLink>*);

    int InsertOrUpdateNode(void*, float, AStarNode<ParentSpaceNode, TeleportLink>*&);

    char prefix[0x205c - sizeof(void*)];
    TESWorldSpace* startWorld;
    int pad;
    PathingLocation StartLocation;
    bool GoalNode;
    TESWorldSpace* world;
    TESObjectCELL* cell;
    int Restrictions;
    float fMaxDist;
    const PathingActorData* pLockData;
    BSSimpleArray<TESObjectREFR*, 1024> DoorList;
    int DoorLockDisposition;
};
