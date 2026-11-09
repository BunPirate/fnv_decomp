#pragma once

#include "NiPSysModifier.h"

class NiPSysCollider;
struct StrArr;

// pdb: class NiPSysColliderManager, size 0x1c, bases: NiPSysModifier, 1 members
class NiPSysColliderManager : public NiPSysModifier
{
public:
    virtual ~NiPSysColliderManager();

    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(float fTime, NiPSysData* pkData);

    void CloneCollider(NiPSysColliderManager* destination, CloningProcess& process);
    void* ReleaseCollider(unsigned int flags);
    using NiPSysModifier::GetViewerStrings;

    NiPSysCollider* m_spColliders;
};
