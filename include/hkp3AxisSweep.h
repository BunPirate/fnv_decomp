#pragma once

#include "hkpBroadPhase.h"

class SweepEntry;
class UnkHandle;
class FourIntegerBlock;
class UnsignedShortPair;
class OverlappingMarkerInfo;
class BroadPhasePairArray;
class PairVec;
class EventList;
class SweepRecord;
class SweepNodeX;
class SweepPairsX;
class Node16;
class Input;
class PairArr;
class ItemList;
class Blk;
class RemovedHandleList;

// pdb: class hkp3AxisSweep, size 0xe0, bases: hkpBroadPhase, 13 members
class hkp3AxisSweep : public hkpBroadPhase
{
public:
    struct NodeArray
    {
        FourIntegerBlock* m_data;
        int m_iElementCount;
        int m_iCapacityState;
    };

    struct Axis
    {
        UnsignedShortPair* m_data;
        int m_iElementCount;
        int m_iCapacityState;
    };

    struct Node
    {
        unsigned short m_usValue00;
        unsigned short m_usValue02;
        unsigned short m_usValue04;
        unsigned short m_usValue06;
        unsigned short m_usValue08;
        unsigned short m_usValue0A;
        unsigned int unk0C;
    };

    struct EndPoint
    {
        unsigned short m_uiFilterValue;
        unsigned short m_usIndex;
    };

    hkp3AxisSweep();
    hkp3AxisSweep(const int* worldMin, const int* worldMax, int numMarkers);
    virtual ~hkp3AxisSweep() throw();
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual BroadPhaseType getType() const;
    virtual void addObject(hkpBroadPhaseHandle* object, const hkAabbUint32& aabb, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void addObject(hkpBroadPhaseHandle* object, const hkAabb& aabb, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void UpdatePairs(const hkArrayBase<hkpBroadPhaseHandle*>& addObjectList, const hkArrayBase<hkAabb>& addAabbList, hkArray<BroadPhaseCastCollector>& newPairs);
    virtual void RemoveBroadPhaseObject(hkpBroadPhaseHandle* object, hkArray<BroadPhaseCastCollector>& pairsOut);
    virtual void RemoveObjectBatch(const hkArrayBase<hkpBroadPhaseHandle*>& removeObjectList, hkArray<BroadPhaseCastCollector>& delPairsOut);
    virtual int GetBroadphaseType() const;
    virtual void UpdateAabbs(hkpBroadPhaseHandle* objects[], const hkAabb* aabbs, int numObjects, hkArray<BroadPhaseCastCollector>& addedPairs, hkArray<BroadPhaseCastCollector>& removedPairs);
    virtual void UpdateAabbsUint32(hkpBroadPhaseHandle* objects[], const hkAabbUint32* aabbs, int numObjects, hkArray<BroadPhaseCastCollector>& addedPairs, hkArray<BroadPhaseCastCollector>& removedPairs);
    virtual void Defragment();
    virtual void ClearBroadPhase();
    virtual void GetAllAabbs(hkArray<hkAabb>& allAabbs) const;
    virtual void getAabb(const hkpBroadPhaseHandle* object, hkAabb& aabb) const;
    virtual void GetWorldExtents(hkVector4& worldMinOut, hkVector4& worldMaxOut) const;
    virtual void FindOverlappingPairs(const hkAabb& aabb, hkArray<BroadPhaseCastCollector>& pairs_out) const;
    virtual void ReQuerySingleObject(const hkpBroadPhaseHandle* object, hkArray<BroadPhaseCastCollector>& pairs_out) const;
    virtual bool AreAabbsOverlapping(const hkpBroadPhaseHandle* bhA, const hkpBroadPhaseHandle* bhB) const;
    virtual void ShiftAllObjects(const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& newCollisionPairs);
    virtual void ShiftBroadPhase(const hkVector4& shiftDistance, hkVector4& effectiveShiftDistanceOut, hkArray<BroadPhaseCastCollector>& newCollisionPairs);
    virtual void GetOffsetLowHigh32Bit(hkVector4& offsetLow32bit, hkVector4& offsetHigh32bit) const;
    virtual void RayCast(const RayCastBatchInput& input, hkpBroadPhaseCastCollector* collectorBase, int collectorStriding) const;
    virtual int GetAabbCacheSize() const;
    virtual void CalcAabbCache(const hkAabb& aabb, hkpBroadPhaseAabbCache* aabbCacheOut) const;
    virtual void CalcAabbCache(const hkArrayBase<hkpCollidable*>& overlappingCollidables, hkpBroadPhaseAabbCache* aabbCacheOut) const;
    virtual void CastSweptAabb(const AabbSweepInput& input, hkpBroadPhaseCastCollector& collector) const;
    virtual void Set32BitOffsetAndScale(const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale);
    virtual void CollectAabbCastResults(const hkAabb& aabb, hkpBroadPhaseCastCollector* collector) const;

    int getNumObjects();
    int getAabbCacheSize();
    void getAabb_00d119c0(UnkHandle* handle);
    void getAabbFromNode(const Node& node, hkAabb& aabb) const;
    void _fixDeterministicOrderAfterNodeIdWasDecreased(unsigned int nodeIndex);
    void _fixDeterministicOrderAfterNodeIdWasDecreased(int nodeIndex);
    void collide1Axis(Node* pa, int numA, Node* pb, int numB, int markerHandlingForNodesB, BroadPhasePairArray& pairsOut);
    void queryBatchAabbSub(unsigned int* bitFieldOfQueryNodes, PairVec* pairsOut, char addMode);
    void getExtents(__m128* worldMinOut, __m128* worldMaxOut);
    bool __thiscall areAabbsOverlapping(int* bhA, int* bhB);
    void defragment();
    void GetValues(__m128* out0, __m128* out1);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int numRecords, unsigned short x_value, SweepRecord* queryNode, int queryNodeIndex, void* bitField);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int count, int x_value, SweepNodeX* queryNode, unsigned int queryNodeIndex, unsigned int* bitField);
    void hkp3AxisSweep_setBitsBasedOnXInterval(int count, unsigned int x_value, Node16* queryNode, int queryNodeIndex, void* bitField);
    void hkp3AxisSweep_updateNodesAfterDelete(SweepNodeX* base, int numNodes, SweepNodeX* oldNode);
    void reQuerySingleObject(int* object, EventList* pairs_out);
    void removeObject(unsigned int* object, SweepPairsX* delPairsOut);
    void calcAabbCache(ItemList* overlappingCollidables, unsigned int AabbCacheOut);
    __declspec(noinline) void calcAabbCacheInternal(Blk* overlaps, unsigned int AabbCacheOut);
    __declspec(noinline) void Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(Node16* buf, int index, Node16* node);
    void addObject_00d142b0(int* object, Input* aabbIn, PairArr* newPairs);
    void removeObjectBatch(RemovedHandleList* removeObjectList, int delPairsOut);

    unsigned char unk10[0x10];
    int m_aabb[4]; // src: XBOX_RETAIL_PDB +0x20 (old: lowBound)
    int highBound[4];
    union { __m128 offset; __m128 m_negSrc; };
    __m128 m_offsetHigh; // src: XBOX_RETAIL_PDB +0x50 (old: offset2)
    union { __m128 scale; __m128 m_recipSrc; };
    __m128 m_offsetLow32bit; // src: XBOX_RETAIL_PDB +0x70 (old: m_v70)
    __m128 m_offsetHigh32bit; // src: XBOX_RETAIL_PDB +0x80 (old: m_v80)
    __m128 m_scale32bit; // src: XBOX_RETAIL_PDB +0x90 (old: unk90)
    union
    {
        NodeArray m_kNodeCollection;
        struct
        {
            union { SweepEntry* unkA0; Node* nodes; };
            union { int m_iA4; int nodeCount; int m_iArrayLength; };
            union { int unkA8; int nodeCapacity; };
        };
    };
    union
    {
        Axis m_kAxisEndPoints[3];
        struct
        {
            Axis m_axis0;
            Axis m_axis1;
            Axis m_axis2;
        };
        struct
        {
            EndPoint* axis0;
            int unkB0;
            int unkB4;
            EndPoint* axis1;
            int unkBC;
            int unkC0;
            EndPoint* axis2;
            int unkC8;
            int unkCC;
        };
    };
    union { int m_iMarkerCount; int m_numSubNodes; int markerCount; int m_iBase; int unkD0; };
    union
    {
        int unkD4;
        struct { unsigned short shiftBits; unsigned short unkD6; };
    };
    union { OverlappingMarkerInfo* m_pOverlappingMarkerInfo; void* unkD8; char* m_markerBase; };
    float m_intToFloatFloorCorrection; // src: XBOX_RETAIL_PDB +0xdc (old: correction)
};
