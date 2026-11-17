#ifndef IMAGESPACESHADERHDR_H
#define IMAGESPACESHADERHDR_H


#include "imagespaceshaderhdr_support.h"

// @fnv 0x00b90720
// pdb: ImageSpaceShaderHDRBrightPassFilter::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantFive::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "BRIGHTFILTER";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBRIGHTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "BRIGHTFILTER";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBRIGHT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b908a0
// pdb: ImageSpaceShaderHDRDownSample16::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantSix::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN16T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN16";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90590
// pdb: ImageSpaceShaderHDRBlur::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantFour::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "15";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBLURT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "15";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRBLUR";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90a30
// pdb: ImageSpaceShaderHDRDownSample9::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant4::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "9";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN9T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "9";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN9";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90bc0
// pdb: ImageSpaceShaderHDRDownSample4::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant1::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN4T";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRDOWN4";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90d50
// pdb: ImageSpaceShaderHDRLightAdapt::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant5::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "ADAPT";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "ADAPT";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90ee0
// pdb: ImageSpaceShaderHDRLumClamp::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant6::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "LUMCLAMP";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRLUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "LUMCLAMP";
        shader.kMacros[0].definition = "";
        shader.kMacros[1].name = 0;
        fnv_zlib_memset(&shader.kMacros[1].definition, 0, 0x3c);
        pixelShader = shader;
        shaderName = "HDRLUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91070
// pdb: ImageSpaceShaderHDRDownSample4LightAdapt::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant2::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4ADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4ADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91210
// pdb: ImageSpaceShaderHDRDownSample4LumClamp::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void HDRBaseImageSpaceShaderVariant3::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4LUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "4";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS4LUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b913b0
// pdb: ImageSpaceShaderHDRDownSample16LightAdapt::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantSeven::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16ADAPTT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "DOWNADAPT";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16ADAPT";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b91550
// pdb: ImageSpaceShaderHDRDownSample16LumClamp::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantEight::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[0].definition, 0, 0x44);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16LUMCLAMPT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "TEXTAP";
        shader.kMacros[0].definition = "16";
        shader.kMacros[1].name = "LUMCLAMP";
        shader.kMacros[1].definition = "";
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRDS16LUMCLAMP";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90060
// pdb: ImageSpaceShaderHDRBlendInShader::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantOne::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "SHBLEND";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "TONEMAP";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "SHBLEND";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "TONEMAP";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = 0;
        fnv_zlib_memset(&shader.kMacros[2].definition, 0, 0x34);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADER";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90200
// pdb: ImageSpaceShaderHDRBlendInShaderCinematic::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantTwo::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCIN";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b903a0
// pdb: ImageSpaceShaderHDRBlendInShaderCinematicAlphamask::ReloadShaders | ImageSpaceManager.obj | retail, string-set bridge, high
// pdb locals: vshader, pcvtarget, pcptarget, pshader, pcname, _pshader
void ImageSpaceShaderHDRVariantThree::SetupShader()
{
    ImageSpaceShaderHDRMacro vertexShader;
    vertexShader.pcPath = "imagespace\\2x\\v\\HDRbase.v.hlsl";
    vertexShader.kMacros[0].name = "TEX2";
    vertexShader.kMacros[0].definition = 0;
    vertexShader.kMacros[1].name = 0;
    fnv_zlib_memset(&vertexShader.kMacros[1].definition, 0, 0x3c);

    ImageSpaceShaderHDRMacro pixelShader;
    const char* shaderName;
    if (g_HDRDoTest)
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur_TEST.p.hlsl";
        shader.kMacros[0].name = "CINEMATIC";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "SHBLEND";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "TONEMAP";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = 0;
        fnv_zlib_memset(&shader.kMacros[3].definition, 0, 0x2c);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINT";
    }
    else
    {
        ImageSpaceShaderHDRMacro shader;
        shader.pcPath = "imagespace\\2x\\p\\HDRBlur.p.hlsl";
        shader.kMacros[0].name = "ALPHAMASK";
        shader.kMacros[0].definition = 0;
        shader.kMacros[1].name = "CINEMATIC";
        shader.kMacros[1].definition = 0;
        shader.kMacros[2].name = "SHBLEND";
        shader.kMacros[2].definition = 0;
        shader.kMacros[3].name = "TONEMAP";
        shader.kMacros[3].definition = 0;
        shader.kMacros[4].name = 0;
        memset(&shader.kMacros[4].definition, 0, 0x24);
        pixelShader = shader;
        shaderName = "HDRBLENDINSHADERCINAM";
    }

    CreateShader(&vertexShader, &pixelShader, shaderName, "vs_1_1", "ps_2_a");
    FinishShaderReload();
}

// @fnv 0x00b90190
// pdb: ImageSpaceShaderHDRBlendInShader::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRBlendInShaderCinematic::ImageSpaceShaderHDRBlendInShaderCinematic
ImageSpaceShaderHDRVariantTwo::ImageSpaceShaderHDRVariantTwo()
{
    textures.SetSize(4);
}

// @fnv 0x00b90330
// pdb: ImageSpaceShaderHDRBlendInShaderCinematic::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRBlendInShaderCinematicAlphamask::ImageSpaceShaderHDRBlendInShaderCinematicAlphamask
ImageSpaceShaderHDRVariantThree::ImageSpaceShaderHDRVariantThree()
{
    textures.SetSize(4);
}

// @fnv 0x00b90520
// pdb: ImageSpaceShaderHDRBlendInShaderCinematicAlphamask::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRBlur::ImageSpaceShaderHDRBlur
ImageSpaceShaderHDRVariantFour::ImageSpaceShaderHDRVariantFour()
{
    textures.SetSize(2);
}

// @fnv 0x00b906b0
// pdb: ImageSpaceShaderHDRBlur::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRBrightPassFilter::ImageSpaceShaderHDRBrightPassFilter
ImageSpaceShaderHDRVariantFive::ImageSpaceShaderHDRVariantFive()
{
    textures.SetSize(2);
}

// @fnv 0x00b90830
// pdb: ImageSpaceShaderHDRBrightPassFilter::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample16::ImageSpaceShaderHDRDownSample16
ImageSpaceShaderHDRVariantSix::ImageSpaceShaderHDRVariantSix()
{
    textures.SetSize(2);
}

// @fnv 0x00b909c0
// pdb: ImageSpaceShaderHDRDownSample16::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample9::ImageSpaceShaderHDRDownSample9
HDRBaseImageSpaceShaderVariant4::HDRBaseImageSpaceShaderVariant4()
{
    textures.SetSize(2);
}

// @fnv 0x00b90b50
// pdb: ImageSpaceShaderHDRDownSample9::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample4::ImageSpaceShaderHDRDownSample4
HDRBaseImageSpaceShaderVariant1::HDRBaseImageSpaceShaderVariant1()
{
    textures.SetSize(2);
}

// @fnv 0x00b91000
// pdb: ImageSpaceShaderHDRLumClamp::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample4LightAdapt::ImageSpaceShaderHDRDownSample4LightAdapt
HDRBaseImageSpaceShaderVariant2::HDRBaseImageSpaceShaderVariant2()
{
    textures.SetSize(3);
}

// @fnv 0x00b911a0
// pdb: ImageSpaceShaderHDRDownSample4LightAdapt::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample4LumClamp::ImageSpaceShaderHDRDownSample4LumClamp
HDRBaseImageSpaceShaderVariant3::HDRBaseImageSpaceShaderVariant3()
{
    textures.SetSize(2);
}

// @fnv 0x00b91340
// pdb: ImageSpaceShaderHDRDownSample4LumClamp::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample16LightAdapt::ImageSpaceShaderHDRDownSample16LightAdapt
ImageSpaceShaderHDRVariantSeven::ImageSpaceShaderHDRVariantSeven()
{
    textures.SetSize(3);
}

// @fnv 0x00b914e0
// pdb: ImageSpaceShaderHDRDownSample16LightAdapt::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRDownSample16LumClamp::ImageSpaceShaderHDRDownSample16LumClamp
ImageSpaceShaderHDRVariantEight::ImageSpaceShaderHDRVariantEight()
{
    textures.SetSize(2);
}

// @fnv 0x00b90ce0
// pdb: ImageSpaceShaderHDRDownSample4::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRLightAdapt::ImageSpaceShaderHDRLightAdapt
HDRBaseImageSpaceShaderVariant5::HDRBaseImageSpaceShaderVariant5()
{
    textures.SetSize(3);
}

// @fnv 0x00b90e70
// pdb: ImageSpaceShaderHDRLightAdapt::`scalar deleting destructor' | ImageSpaceManager.obj | retail, object-file run extension, low
// pdb note: debug build links it to ImageSpaceShaderHDRLumClamp::ImageSpaceShaderHDRLumClamp
HDRBaseImageSpaceShaderVariant6::HDRBaseImageSpaceShaderVariant6()
{
    textures.SetSize(2);
}

#endif
