// bsshader/speedtreeshader.cpp: SpeedTreeLeafShaderConstantMapSetup (1 function)

#include "speedtreeshader_decls.h"
// Registers the TreeData and WindMatrices shader constants on the map, incrementing index for the second entry.
// @fnv 0x00bb2f50
// src: XBOX_RETAIL_PDB 0x00bb2f50
// pdb: SpeedTreeShader::SetShaderConstants | SpeedTreeShader.obj | retail, string-set bridge, high
// pdb params: apVertexConstantMap, aiStartRegister
// pdb locals: iconstantFloat4Flags, iconstantMatrix4Flags, icurrentRegister
void SpeedTreeLeafShaderConstantMapSetup::SpeedTreeShader_SetShaderConstants(NiD3DShaderConstantMap* apVertexConstantMap, int aiStartRegister)
{
    apVertexConstantMap->SetConstant("TreeData", 0x10000007, 0, aiStartRegister, 1, "", 16, 4, DAT_01200678, false);
    apVertexConstantMap->SetConstant("WindMatrices", 0x10000009, 0, ++aiStartRegister, 16, "", 256, 4, DAT_01200688, false);
}
