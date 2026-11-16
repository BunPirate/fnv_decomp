#pragma once

#include "NiPoint3.h"

// BSAudioListener: abstract listener base, RTTI .?AVBSAudioListener@@, vftable 0x010a3bb4 (13 slots; slots 1, 2, 5
// and 8 are _purecall, 0x00aa7830 is the shared empty /Od body). BSWin32AudioListener (vftable 0x010a3b7c) derives
// from it. Layout from the /Od bodies: vptr at 0x00, position 0x04, velocity 0x10, forward 0x1C, up 0x28,
// flags 0x44 (written by slot 10, cleared by the slot-0 deleting destructor); size 0x48.
// pdb: class BSAudioListener, size 0x48, 9 members
class BSAudioListener
{
public:
    virtual void* Destroy(unsigned int auiFlags);           // 0x00 0x00aeabb0
    virtual void vfn_4() = 0;                               // 0x04
    virtual void vfn_8(NiPoint3* pos) = 0;                  // 0x08
    virtual NiPoint3& GetPosition_00aeaad0();                       // 0x0C
    virtual void vfn_10();                                  // 0x10 0x00aa7830
    virtual void vfn_14(NiPoint3* front, NiPoint3* top) = 0; // 0x14
    virtual NiPoint3* GetFrontOrientation();                       // 0x18
    virtual NiPoint3& GetTopOrientation();                       // 0x1C
    virtual void vfn_20(NiPoint3* velocity) = 0;            // 0x20
    virtual void SetGain(float afGain);                // 0x24
    virtual void SetListenerID(unsigned int);               // 0x28 0x00aeab50
    virtual unsigned int GetListenerID();                   // 0x2C 0x00aeab70
    virtual void SetRolloffFactor(float afRolloffFactor);   // 0x30 0x00aeab90

    NiPoint3 ListenerPosition;    // +0x04 // src: XBOX_RETAIL_PDB +0x4 (old: m_kListenerPosition)
    NiPoint3 FrontOrientation;    // +0x10 // src: XBOX_RETAIL_PDB +0x10 (old: m_kListenerVelocity)
    NiPoint3 TopOrientation;             // +0x1C // src: XBOX_RETAIL_PDB +0x1c (old: m_kForward)
    NiPoint3 vVelocity;                  // +0x28 // src: XBOX_RETAIL_PDB +0x28 (old: m_kUp)
    unsigned int dwTimeLastUpdated;     // +0x34 // src: XBOX_RETAIL_PDB +0x34 (old: m_uiListenerID)
    float fVelocity;                   // +0x38 // src: XBOX_RETAIL_PDB +0x38 (old: m_fGain)
    float fRolloffFactor;           // +0x3C // src: XBOX_RETAIL_PDB +0x3c (old: m_fDopplerScale)
    float fGain;          // +0x40 // src: XBOX_RETAIL_PDB +0x40 (old: m_fDistanceScale)
    unsigned int iEvironmentType;  // +0x44 // src: XBOX_RETAIL_PDB +0x44 (old: m_uiListenerFlags)
};
