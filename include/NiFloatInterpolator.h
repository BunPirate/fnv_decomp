#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiAVObject.h"
#include "NiFloatData.h"

// pdb: class NiFloatInterpolator, size 0x18, bases: NiKeyBasedInterpolator, 3 members
class NiFloatInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiFloatInterpolator();
    NiFloatInterpolator(NiFloatData* pkFloatData);
    virtual ~NiFloatInterpolator();
    NiFloatInterpolator& operator=(const NiFloatInterpolator&);

    virtual void DeleteThis();
    virtual void LoadBinary(NiStream& kStream);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& result);
    virtual void Collapse();

    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short channel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short channel) const;
    virtual unsigned char GetColorKeySize(unsigned short channel) const;
    virtual void vf61(unsigned short channel);

    void IncRefCount();
    void DecRefCount();
    bool Update(float time, NiObjectNET* target, float& result);
    NiFloatInterpolator* FUN_00a3c390(float value);
    void SetFloatValue(float value);
    void FUN_007fc2b0(NiFloatData* data);
    void SetKeyData(void* pkKeys, unsigned int uiNumKeys, unsigned int eType);
    void SetAnimationKeys(TimedAnimationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType);
    void SetAnimationKeys(void* keys, unsigned int count, unsigned int type);

    float m_fFloatValue; // src: XBOX_RETAIL_PDB +0xc (old: value)
    NiPointer<NiFloatData> m_spFloatData; // src: XBOX_RETAIL_PDB +0x10 (old: data)
    unsigned int m_uiLastIdx; // src: XBOX_RETAIL_PDB +0x14 (old: lastIndex)
};
