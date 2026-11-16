#pragma once

#include "hkArray.h"

class hkpAgentNnSector;

// pdb: structure hkpAgentNnTrack, size 0x14, 2 members
class hkpAgentNnTrack
{
public:
    unsigned int m_bytesUsedInLastSector; // src: XBOX_RETAIL_PDB +0x0 (old: m_iBytesUsedInLastSector)
    hkInplaceArray<hkpAgentNnSector*, 1> m_sectors; // src: XBOX_RETAIL_PDB +0x4 (old: m_kSectors)

    hkpAgentNnTrack()
    {
        m_bytesUsedInLastSector = 0x200;
    }
};
