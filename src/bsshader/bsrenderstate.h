
#include "bsrenderstate_packet_decls.h"
// @fnv 0x00b6b790
// pdb: BSRenderedTexture::StopOffscreen | BSRenderedTexture.obj | retail, call graph, medium
// pdb locals: pr
void BSRenderedTexture::EndAllAndResetRendererState()
{
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    EndAll();
    // NiRenderer.h does not yet declare the end-frame virtual at slot 96.
    typedef bool (__thiscall* EndFrameFunction)(NiRenderer*);
    if (renderer->m_eFrameState == 2 &&
        (*reinterpret_cast<EndFrameFunction**>(renderer))[96](renderer))
        renderer->m_eFrameState = 0;
}
// @fnv 0x00b97fa0
// pdb: BSRenderState::SetAlphaBlendEnable | BSRenderState_Xenon.obj | retail, call graph, high
// pdb params: abEnabled, aeLock
void BSRenderState::SetDepthBufferEnabled(bool abEnabled, BSRENDERSTATE_LOCK aeLock)
{
    unsigned int index = DAT_011ffa9c;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(27, abEnabled, 0, 0);
    DAT_011ff9d8[index] += aeLock;
}
// @fnv 0x00b98380
// pdb: BSRenderState::SetColorWriteEnable | BSRenderState_Xenon.obj | retail, call graph, high
// pdb params: auiMask, aeLock
void BSRenderState::SetColorWriteMask(unsigned int auiMask, BSRENDERSTATE_LOCK aeLock)
{
    unsigned int index = DAT_011ffcd0;
    if (DAT_011ff9d8[index] == 0)
        g_pkRenderer->device->SetRenderState(168, auiMask, 0, 0);
    DAT_011ff9d8[index] += aeLock;
}
