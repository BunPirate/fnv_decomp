#pragma once

#include "hkpBroadPhaseCastCollector.h"
#include "hkKdTreeCastCollector.h"
#include "hkAabbTreeQueryUtils.h"
#include "hkVector4.h"

class hkpFixedBufferRayHitCollector;

class hkCpuWorldRayCastCollector
    : public hkpBroadPhaseCastCollector,
      public hkKdTreeCastCollector,
      public hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Collector,
      public hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb16, unsigned short>::Collector
{
public:
    int m_filter;
    float m_hitFraction;
    int m_hit;
    int m_command;
    int m_originalInput;
    int m_result;
    int m_nextFreeResult;
    int unk2c;
    hkVector4 m_workInput;
    hkVector4 m_workTo;
    int m_workFilter;
    int m_workCollection;
    int unk58;
    int unk5c;
    hkpFixedBufferRayHitCollector* m_fixedBufferRayHitCollector;
    int unk64;
    int unk68;
    int unk6c;
    hkVector4 m_earlyOutHitFraction;

    hkCpuWorldRayCastCollector();
    virtual float ReleaseCollector(const hkpBroadPhaseHandle*, int);
    virtual hkBool ReportHit(hkPrimitiveId);
    virtual hkBool DidHit();
    virtual hkReal GetHitFraction();
    virtual hkReal GetHitDistance(
        const hkAabbTree<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Node*);
    virtual hkReal GetHitDistance(
        const hkAabbTree<hkAabbTreeData::hkAabbTreeAabb16, unsigned short>::Node*);
};
