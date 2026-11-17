// bsshader/bsshadersdm.cpp: BSShaderInitializer (3 functions)

#include "../../include/BSFadeNode.h"
#include "bsshadersdm_decls.h"
// BSShaderRenderUtility_bsshadersdm: local type (was include/BSShaderRenderUtility.h, which had no evidence of one real class); its methods are 0x00469860 TESDataHandler::IsFormIDCreated, 0x00b6ba70 BSShaderUtil::InitSDM, 0x00b6bb30 BSShaderUtil::RecursiveSetPropertyFadeAlpha, 0x00b6c0d0 BSShaderUtil::RenderScene
class AnimIdle;
class BSShaderAccumulator;
class NiCamera;

class BSShaderRenderUtility_bsshadersdm
{
public:
    bool IsRenderTargetId(unsigned int value);
    static void InitSDM();
    static void SetRenderCamera(NiCamera* camera, BSShaderAccumulator* accumulator, bool unused);
    static void SetRenderCamera(AnimIdle* camera, AnimIdle* accumulator, bool unused);
    static void SetRenderCamera(void* camera, unsigned int accumulator, bool unused);
    static void SetAlphaOnNode(NiNode* node, float alpha);
};
#include "../../include/StrArr.h"

// @fnv 0x00bc2940
void BSShaderInitializer::InitializeMultiBounds()
{
    if (!DAT_01201f70)
    {
        BSFadeNode::InitializeMultiBounds();
        BSShaderRenderUtility_bsshadersdm::InitSDM();
        DAT_01201f70 = true;
    }
}

void __stdcall BoltShaderProperty_ExtendBolt(float, float);
void __stdcall BoltShaderProperty_CleanupBolt(float, float);
// Calls FUN_00bc2660 with a and b when flag is false, otherwise calls FUN_00bc1cc0 with a and c.
// @fnv 0x00bc28b0
// pdb: BoltShaderProperty::UpdateBolt | BoltShaderProperty.obj | debug, call graph (shared callers), medium
// pdb params: afTimeDelta, afDesiredBoltDistance, afSpeed, abCleanup
void __stdcall DispatchFloatPair(float afFirst, float afSecond, float afThird, bool abUseThird)
{
    if (!abUseThird)
    {
        BoltShaderProperty_ExtendBolt(afFirst, afSecond);
        return;
    }
    BoltShaderProperty_CleanupBolt(afFirst, afThird);
}

void __stdcall WriteToSettingArray(StrArr*);
char* _FUN_00a7d330(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 BoltShaderProperty_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01201f68 (old: g_01201f68/g_target_00bc1f90)
// @fnv 0x00bc28f0
// src: XBOX_PDB 0x00bc28f0
// pdb: BoltShaderProperty::GetViewerStrings | BoltShaderProperty.obj | retail, upstream name already matches, high
// pdb params: apStrings
void __stdcall BoltShaderProperty_GetViewerStrings(StrArr* apStrings)
{
    WriteToSettingArray(apStrings);
    char* pStr = _FUN_00a7d330(BoltShaderProperty_ms_RTTI.f0);
    unsigned int uiIndex = apStrings->m_usSize;
    unsigned int cnt = apStrings->m_usMaxSize;
    if (uiIndex >= cnt)
    {
        apStrings->SetSize(apStrings->m_usGrowBy + uiIndex);
    }
    apStrings->SetAt(uiIndex, pStr);
}
