#pragma once

#include "hkArray.h"

class hkpAgentNnSector;

// pdb: structure hkpAgentNnTrack, size 0x14, 2 members
class hkpAgentNnTrack
{
public:
    unsigned int m_bytesUsedInLastSector;
    hkInplaceArray<hkpAgentNnSector*, 1> m_sectors;

    hkpAgentNnTrack()
    {
        m_bytesUsedInLastSector = 0x200;
    }
};
