#pragma once

#include "NiPSysModifier.h"
#include "NiBound.h"

// pdb: class NiPSysBoundUpdateModifier, size 0x20, bases: NiPSysModifier, 3 members
class NiPSysBoundUpdateModifier : public NiPSysModifier
{
public:
    NiPSysBoundUpdateModifier() throw();
    virtual ~NiPSysBoundUpdateModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* object) const;

    void SetUpdateSkipCounter(int iUpdateSkip);
    void* Destroy(unsigned int flags);

    static const NiRTTI ms_kRTTI;

    short m_usUpdateSkip;
    unsigned short m_usUpdateCount;
    NiBound* m_pkBounds;
};
