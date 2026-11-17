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
    int m_filter; // src: XBOX_RETAIL_PDB +0x10 (old: m_iFilter)
    float m_hitFraction; // src: XBOX_RETAIL_PDB +0x14 (old: m_fHitFraction)
    int m_hit; // src: XBOX_RETAIL_PDB +0x18 (old: m_bHasHit)
    int m_command; // src: XBOX_RETAIL_PDB +0x1c (old: m_iFieldAfterHasHit)
    int m_originalInput; // src: XBOX_RETAIL_PDB +0x20 (old: m_iFieldBeforeResult)
    int m_result;
    int m_nextFreeResult; // src: XBOX_RETAIL_PDB +0x28 (old: m_iFieldAfterResult)
    int unk2c;
    hkVector4 m_workInput; // src: XBOX_RETAIL_PDB +0x30 (old: m_workFrom)
    hkVector4 m_workTo;
    int m_workFilter;
    int m_workCollection;
    int unk58;
    int unk5c;
    hkpFixedBufferRayHitCollector* m_fixedBufferRayHitCollector; // src: XBOX_RETAIL_PDB +0x60 (old: m_fixedBufferRayHitFilterCollector)
    int unk64;
    int unk68;
    int unk6c;
    hkVector4 m_earlyOutHitFraction; // src: XBOX_RETAIL_PDB +0x70 (old: m_fEarlyOutHitFraction)

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
