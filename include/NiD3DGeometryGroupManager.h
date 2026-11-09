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

    unsigned int* m_kGroups;
    unsigned int m_08;
    unsigned int m_0c;
    Direct3DDeviceInterface* m_pkD3DDevice;
    VertexDeclarationLayout* m_pkVBManager;
    bool m_bHWSkinning;
};
