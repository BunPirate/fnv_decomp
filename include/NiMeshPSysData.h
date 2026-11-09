#pragma once

#include "NiPSysData.h"
#include "NiNode.h"

// pdb: class NiMeshPSysData, size 0x98, bases: NiPSysData, 4 members
class NiMeshPSysData : public NiPSysData
{
public:
    NiMeshPSysData() throw();
    virtual ~NiMeshPSysData();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void ProcessClone(CloningProcess&);
    virtual void vf35();
    virtual void vf41(unsigned short);
    virtual void vf43();

    void CopyMemberData(NiMeshPSysData* pkDest, CloningProcess& kCloning);
    void CloneTo(NiMeshPSysData* pkDest, CloningProcess& kCloning);
    void ReleaseSlotRef(unsigned int uiGeneration, NiPointer<NiAVObject> spParticle);
    void ReleaseSlotRef(unsigned int uiGeneration, NiRefObject* pkParticle);
    void ResizeChildren(unsigned int uiNumGenerations);
    void FillPools(bool uiNumGenerations);
    void WriteToStream(NiStream& kStream);

    void __thiscall SetActiveVertexCount_00c308d0(unsigned short usStartIndex);
    void __thiscall ProcessClone_00c30920(CloningProcess& kCloning);
    bool __thiscall RegisterStreamables_00c30940(NiStream& kStream);
    char __thiscall IsEqual_00c30970(NiMeshPSysData* pkOther);
    void __thiscall FUN_00c309d0();
    void __thiscall ResolveAddedParticles_00c30a90();
    void __thiscall LinkObject_00c30b70(NiStream& kStream);
    void* __thiscall FUN_00c30bd0(unsigned int);
    NiMeshPSysData* __thiscall FUN_00c30c00();
    NiObject* __thiscall CreateClone_00c30c50(CloningProcess& kCloning);
    void __thiscall RemoveParticle(unsigned short usParticle);
    void __thiscall LoadBinary_00c31090(NiStream& kStream);

    NiPointer<NiNode> m_spParticleMeshes;
    bool m_bFillPoolsOnLoad;
    unsigned char unk81[3];
    unsigned int m_uiDefaultPoolSize;
    NiTObjectArray<NiTObjectArray<NiPointer<NiAVObject> >*> m_kPools;
};
