#pragma once

#include "hkpCdBodyPairCollector.h"

// pdb: class hkpAllCdBodyPairCollector, size 0x114, bases: hkpCdBodyPairCollector, 1 members
class hkpAllCdBodyPairCollector : public hkpCdBodyPairCollector
{
public:
    struct BodyPair
    {
        void* bodyA;
        void* bodyB;
        void* bodyC;
        void* bodyD;
    };

    struct PairArray
    {
        void* data;
        int size;
        int capacity;
        BodyPair pairs[16];

        PairArray(int a);
        ~PairArray();
    };

    int unk04;
    PairArray m_hits;

    hkpAllCdBodyPairCollector();
    virtual ~hkpAllCdBodyPairCollector();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    virtual void hkpCdBodyPairCollector_reset();

    void* FUN_0062d440(unsigned int flags);
    void reset_0062d310();
};
