// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/MemoryManager.h"
#include "../../../include/NiPoint3.h"

#include "../../../include/BSAudioListener.h"

// @fnv 0x00aeaad0
// src: XBOX_PDB 0x00aeaad0
NiPoint3& BSAudioListener::GetPosition_00aeaad0()
{
    return ListenerPosition;
}

// @fnv 0x00aeaaf0
// src: XBOX_PDB 0x00aeaaf0
NiPoint3* BSAudioListener::GetFrontOrientation()
{
    return &FrontOrientation;
}

// @fnv 0x00aeab10
// src: XBOX_PDB 0x00aeab10
NiPoint3& BSAudioListener::GetTopOrientation()
{
    return TopOrientation;
}

// @fnv 0x00aeab30
// src: XBOX_PDB 0x00aeab30
void BSAudioListener::SetGain(float afGain)
{
    fGain = afGain;
}

// @fnv 0x00aeab90
void BSAudioListener::SetRolloffFactor(float afRolloffFactor)
{
    fRolloffFactor = afRolloffFactor;
}

extern MemoryManager g_memoryManager;
extern int DAT_010a3bb4;

// Sets the vtable pointer, clears the flags, and deallocates this when bit 0 is set; returns this.
// @fnv 0x00aeabb0
void* BSAudioListener::Destroy(unsigned int auiFlags)
{
    *reinterpret_cast<void**>(this) = &DAT_010a3bb4;
    iEvironmentType = 0;
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
