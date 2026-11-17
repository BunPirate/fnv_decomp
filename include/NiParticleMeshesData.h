#pragma once

#include "NiParticlesData.h"
#include "NiAVObject.h"

// pdb: class NiParticleMeshesData, size 0x78, bases: NiParticlesData, 2 members
class NiParticleMeshesData : public NiParticlesData
{
  public:
    NiParticleMeshesData() throw();
    virtual ~NiParticleMeshesData() throw();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);
    virtual void vf35();
    virtual void vf41(unsigned short);

    void LoadBinary_00a98a10(NiStream&);
    void SetActiveVertexCount(unsigned short);
    bool RegisterStreamables_00a98a80(NiStream&);
    void SaveBinary_00a98ab0(NiStream&);
    void LinkObject_00a98d60(NiStream&);
    bool IsMeshNodeEqual(void*);
    void RemoveParticleMesh(unsigned short);
    void UpdateParticleMeshes();

    NiPointer<NiNode> m_spParticleMeshes; // src: XBOX_RETAIL_PDB +0x70 (old: m_spRootNode)
    bool m_bNeedsPropertyEffectUpdate; // src: XBOX_RETAIL_PDB +0x74 (old: m_bModifierActive)
    unsigned char unk75[3];
};
