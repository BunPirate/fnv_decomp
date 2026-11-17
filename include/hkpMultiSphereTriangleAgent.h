#pragma once

#include "hkpIterativeLinearCastAgent.h"

class hkpCdBody;
class hkpCdBodyPairCollector;
class hkpSimpleClosestContactCollector;
class hkpCdPointCollector;
class ShapeSweepParameters;

// pdb: class hkpMultiSphereTriangleAgent, size 0x2c, bases: hkpIterativeLinearCastAgent, 2 members
class hkpMultiSphereTriangleAgent : public hkpIterativeLinearCastAgent
{
public:
    struct TriangleNormal
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0C;
    };

    TriangleNormal m_closestPointTriangleCache; // src: XBOX_RETAIL_PDB +0xc (old: m_kTriangleNormal)
    unsigned short m_contactPointId[8]; // src: XBOX_RETAIL_PDB +0x1c (old: m_ids)

    hkpMultiSphereTriangleAgent(const hkpCdBody& bodyA, void* mgr);

    virtual ~hkpMultiSphereTriangleAgent() throw();
    virtual void slot3();
    virtual void CastImpl(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                          const void* input, hkpSimpleClosestContactCollector* collector);
    virtual void vf05(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                      const ShapeSweepParameters* input, hkpCdPointCollector* castCollector,
                      hkpCdPointCollector* startCollector);
    virtual void vf06();
    virtual void vf07(int constraintOwner);
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    void getPenetrations_00d37ed0(const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                      const void* input, hkpCdBodyPairCollector& collector);
};
