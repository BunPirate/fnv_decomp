#pragma once

class hkpCdBody;
class hkpContactMgr;
class hkpLinkedCollidable;

// pdb: structure hkpAgentNnEntry, size 0x18, bases: hkpAgentEntry, 6 members
class hkpAgentNnEntry
{
public:
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
    unsigned short m_agentIndexOnCollidable[2];
    hkpContactMgr* m_contactMgr;
    unsigned char m_collisionQualityIndex;
    unsigned char m_forceCollideOntoPpu;
    unsigned char m_padding;
    unsigned char m_usHeaderWord;
    hkpLinkedCollidable* m_collidable[2];

    inline hkpCdBody* getCollidableA()
    {
        return reinterpret_cast<hkpCdBody*>(m_collidable[0]);
    }

    inline hkpCdBody* getCollidableB()
    {
        return reinterpret_cast<hkpCdBody*>(m_collidable[1]);
    }
};
