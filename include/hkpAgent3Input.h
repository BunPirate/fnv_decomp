#pragma once

#include "hkPadSpu.h"
#include "hkTransform.h"

class hkpCdBody;
class hkpContactMgr;
class hkpProcessCollisionInput;

// src: COMMUNITY
// pdb: structure hkpAgent3Input, size 0x60, 6 members
class hkpAgent3Input
{
public:
    // src: COMMUNITY
    hkpAgent3Input() : m_overrideBodyA(0) {}

    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_bodyA;
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_bodyB;
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_overrideBodyA;
    // src: COMMUNITY
    hkPadSpu<const hkpProcessCollisionInput*> m_input;
    // src: COMMUNITY
    hkPadSpu<hkpContactMgr*> m_contactMgr;
    // src: COMMUNITY
    hkTransform m_aTb;
};
