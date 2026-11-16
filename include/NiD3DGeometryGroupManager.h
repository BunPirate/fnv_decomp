#pragma once

#include "NiGeometryGroupManager.h"

class Direct3DDeviceInterface;
class NiGeometryGroup;
class VertexDeclarationLayout;

// pdb: class NiD3DGeometryGroupManager, size 0x1c, bases: NiGeometryGroupManager, 4 members
class NiD3DGeometryGroupManager : public NiGeometryGroupManager
{
public:
    void Initialize();
    void SetFlag(bool flag);
    NiGeometryGroup* CreateGroup(NiGeometryGroupManager::RepackingBehavior);
    static NiD3DGeometryGroupManager* Create(Direct3DDeviceInterface*, VertexDeclarationLayout*);

    unsigned int* m_kGroups; // src: XBOX_RETAIL_PDB +0x4 (old: m_04)
    unsigned int m_08;
    unsigned int m_0c;
    Direct3DDeviceInterface* m_pkD3DDevice; // src: XBOX_RETAIL_PDB +0x10 (old: m_10)
    VertexDeclarationLayout* m_pkVBManager; // src: XBOX_RETAIL_PDB +0x14 (old: m_14)
    bool m_bHWSkinning; // src: XBOX_RETAIL_PDB +0x18 (old: m_18)
};
