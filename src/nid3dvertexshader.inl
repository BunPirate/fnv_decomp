// @fnv 0x00be0b30
// pdb: NiD3DVertexShader::NiD3DVertexShader | NiD3DShaderProgramCreatorHLSL.obj | retail, upstream name already matches, high
// pdb params: pkRenderer
NiD3DVertexShader::NiD3DVertexShader(GraphicsRenderer *const pkRenderer) :
    NiD3DShaderProgram(pkRenderer, false)
{
    m_bSoftwareVP = false;
    m_uiUsage = 0;
    m_hShader = 0;
    m_hDecl = 0;
}

// @fnv 0x00be0b60
const NiRTTI* NiD3DVertexShader::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x00be0bb0
void NiD3DVertexShader::SetD3DPixelShader(RenderableGeometry *const hShader)
{
    m_hShader = hShader;
}

// @fnv 0x00be0bc0
// pdb: NiPSysModifierCtlr::GetCtlrID | NiPSysModifierCtlr.obj | debug, vtable slot, medium
COMUnknownInterface* NiD3DVertexShader::GetShaderDeclaration() const
{
    return m_hDecl;
}