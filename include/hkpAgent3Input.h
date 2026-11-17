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
    hkPadSpu<const hkpCdBody*> m_bodyA; // src: XBOX_RETAIL_PDB +0x0 (old: m_pBodyA)
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_bodyB; // src: XBOX_RETAIL_PDB +0x4 (old: m_pBodyB)
    // src: COMMUNITY
    hkPadSpu<const hkpCdBody*> m_overrideBodyA; // src: XBOX_RETAIL_PDB +0x8 (old: m_pAdditionalCollidableBody)
    // src: COMMUNITY
    hkPadSpu<const hkpProcessCollisionInput*> m_input; // src: XBOX_RETAIL_PDB +0xc (old: m_pRayCastInput)
    // src: COMMUNITY
    hkPadSpu<hkpContactMgr*> m_contactMgr; // src: XBOX_RETAIL_PDB +0x10 (old: m_pContactManager)
    // src: COMMUNITY
    hkTransform m_aTb; // src: XBOX_RETAIL_PDB +0x20 (old: m_kTransform)
};
