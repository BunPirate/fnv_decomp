#pragma once

#include "hkpIterativeLinearCastAgent.h"
#include "hkVector4.h"
#include "hkBool.h"

class hkpCdBody;
class hkpCdBodyPairCollector;
class hkpCdPointCollector;
class hkpConstraintOwner;
class hkpContactMgr;
class CollisionAgentContext;
class ShapeSweepParameters;
struct GskAgentInput;
struct GskAgentData;
class WorldOperationEntry;
class ConvexShapePairCache;
class ConvexFeaturePairCache;
class hkTransform;

typedef float hkReal;
typedef hkReal hkTime;
typedef unsigned short hkContactPointId;

// pdb: class hkpGskBaseAgent, size 0x30, bases: hkpIterativeLinearCastAgent, 4 members
class hkpGskBaseAgent : public hkpIterativeLinearCastAgent
{
public:
    virtual ~hkpGskBaseAgent() throw();
    virtual void getPenetrations(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdBodyPairCollector& kCollector);
    virtual void getClosestPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdPointCollector& kCollector);
    virtual void linearCast(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const ShapeSweepParameters& kInput, hkpCdPointCollector& kCastCollector, hkpCdPointCollector* pStartCollector);
    virtual void ProcessAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const GskAgentInput& kInput, WorldOperationEntry& kResult);
    virtual void cleanup(hkpConstraintOwner& kConstraintOwner);
    virtual void ProcessContactPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpConstraintOwner& kConstraintOwner);
    virtual void RemovePoint(const CollisionAgentContext& kInput);
    virtual void WarpTime(hkTime kOldTime, hkTime kNewTime, const CollisionAgentContext& kInput);
    virtual void removePoint(hkContactPointId kToRemove);
    virtual void CommitPotentialContactPoint(hkContactPointId kContactPointId);
    virtual void MarkContactPointAsZombie(hkContactPointId kTobecomeZombie);

    hkpGskBaseAgent(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, hkpContactMgr* pMgr);

    static void __cdecl m_pVirtualFunction1(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdBodyPairCollector& kCollector);
    static void __cdecl m_pVirtualFunction2(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, hkpCdPointCollector& kCollector);

private:
public:
    unsigned char m_cache[0x0C];      // the agent's convex feature-pair cache // src: XBOX_RETAIL_PDB +0xc (old: m_pAccess)
    float m_timeOfSeparatingNormal; // src: XBOX_RETAIL_PDB +0x18 (old: m_fFloatValue)
    float m_allowedPenetration; // src: XBOX_RETAIL_PDB +0x1c (old: m_fSeparationDistance)
    hkVector4 m_separatingNormal; // src: XBOX_RETAIL_PDB +0x20 (old: m_vSeparatingNormal)

    friend class hkpConvexListAgent;
    hkpGskBaseAgent(hkpContactMgr* pMgr);

protected:
    hkBool getClosestPoint(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, GskAgentData& kOutput);
    static void __cdecl ComputeClosestPoint(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, hkReal fEarlyOutTolerance, ConvexShapePairCache& kGsk, hkVector4& kSeparatingNormalOut);
    hkBool ComputeClosestPoints(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const CollisionAgentContext& kInput, GskAgentData& kOutput);
    static hkBool staticGetClosestPoint(const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const hkTransform& kTb, const CollisionAgentContext& kInput, ConvexFeaturePairCache& kCache, GskAgentData& kOutput);
};
