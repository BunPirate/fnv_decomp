#pragma once

#include "NiExtraData.h"
#include "BSSoundHandle.h"

// pdb: class BGSAddonNodeSoundHandleExtra, size 0x18, bases: NiExtraData, 1 members
class BGSAddonNodeSoundHandleExtra : public NiExtraData
{
public:
    BGSAddonNodeSoundHandleExtra();
    virtual ~BGSAddonNodeSoundHandleExtra();

    virtual const NiRTTI* GetRTTI() const;
    virtual void vf37();

    void FUN_004f9270();
    void* FUN_004f9240(unsigned int flags);

    BSSoundHandle SoundHandle; // src: XBOX_RETAIL_PDB +0xc (old: m_kData)
};
