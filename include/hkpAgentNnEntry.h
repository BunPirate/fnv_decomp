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
    unsigned short m_agentIndexOnCollidable[2]; // src: XBOX_RETAIL_PDB +0x4 (old: m_ausAgentData)
    hkpContactMgr* m_contactMgr; // src: XBOX_RETAIL_PDB +0x8 (old: m_pContactManager)
    unsigned char m_collisionQualityIndex; // src: XBOX_RETAIL_PDB +0xc (old: m_cAgentType)
    unsigned char m_forceCollideOntoPpu; // src: XBOX_RETAIL_PDB +0xd (old: m_uiForceCollideOntoPpu)
    unsigned char m_padding; // src: XBOX_RETAIL_PDB +0xe (old: m_ucHeaderByte)
    unsigned char m_usHeaderWord;
    hkpLinkedCollidable* m_collidable[2]; // src: XBOX_RETAIL_PDB +0x10 (old: m_kCollidable)

    inline hkpCdBody* getCollidableA()
    {
        return reinterpret_cast<hkpCdBody*>(m_collidable[0]);
    }

    inline hkpCdBody* getCollidableB()
    {
        return reinterpret_cast<hkpCdBody*>(m_collidable[1]);
    }
};
