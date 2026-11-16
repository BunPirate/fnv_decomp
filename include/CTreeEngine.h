#pragma once

#include "CIdvCamera.h"

class ElementIterator;
class CTreeFileAccessImpl;
class TreeFileAccess;
class Reader;

// pdb: class CTreeEngine, size 0x110, bases: CIdvCamera, 22 members
class CTreeEngine : public CIdvCamera
{
public:
    struct SptFilename
    {
        int allocator;
        union Buffer
        {
            char buffer[16];
            char* data;
        } storage;
        unsigned int length;
        unsigned int capacity;

        SptFilename(const SptFilename& rhs);
        ~SptFilename();
        void fopen_0044a730(bool built, unsigned int n);
        SptFilename& AssignFromString(const SptFilename& rhs);
        SptFilename& EvaluateValue_00b2b910(const SptFilename& rhs);
        void operator=(const SptFilename& rhs);
    };

    struct Sub94
    {
        void SIdvLeafInfo_Parse(ElementIterator* cFile);
    };

    struct SubA4
    {
        void CTreeEngine_SetLeafTextures(SubA4* vTextures);
    };

    struct Sub10c
    {
        void SIdvWindInfo_Parse(ElementIterator* cFile);
    };

    float* m_fBillboardSize; // src: XBOX_RETAIL_PDB +0x10 (old: m_pfTreeSize)
    float* m_fLod; // src: XBOX_RETAIL_PDB +0x14 (old: m_pfTreeSizeVariance)
    float m_fOverrideTreeSize; // src: XBOX_RETAIL_PDB +0x18 (old: m_actualSize)
    float m_fOverrideTreeVariance; // src: XBOX_RETAIL_PDB +0x1c (old: m_actualVariance)
    int m_cRandom; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    SptFilename m_sTreeInfo; // src: XBOX_RETAIL_PDB +0x24 (old: m_pcFileName)
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int m_pBranch; // src: XBOX_RETAIL_PDB +0x58 (old: unk58)
    int m_pBranchGeometry; // src: XBOX_RETAIL_PDB +0x5c (old: unk5c)
    int m_vBranchInfo; // src: XBOX_RETAIL_PDB +0x60 (old: unk60)
    int unk64;
    int unk68;
    int unk6c;
    int m_nNumBranchLodLevels; // src: XBOX_RETAIL_PDB +0x70 (old: unk70)
    int m_vBillboardLeaves; // src: XBOX_RETAIL_PDB +0x74 (old: unk74)
    int unk78;
    int unk7c;
    int unk80;
    int m_sLeafInfo; // src: XBOX_RETAIL_PDB +0x84 (old: unk84)
    int unk88;
    int unk8c;
    int unk90;
    Sub94 m_sub94;
    int unk98;
    int unk9c;
    int unka0;
    SubA4 m_suba4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int m_vLeafLods; // src: XBOX_RETAIL_PDB +0xd4 (old: unkd4)
    int m_bParsedLeafLods; // src: XBOX_RETAIL_PDB +0xd8 (old: unkd8)
    int m_fMinBranchVolumePercent; // src: XBOX_RETAIL_PDB +0xdc (old: unkdc)
    int m_fMaxBranchVolumePercent; // src: XBOX_RETAIL_PDB +0xe0 (old: unke0)
    int m_fLeafReductionPercentage; // src: XBOX_RETAIL_PDB +0xe4 (old: unke4)
    int m_fBranchReductionFuzziness; // src: XBOX_RETAIL_PDB +0xe8 (old: unke8)
    int m_fLargeBranchPercent; // src: XBOX_RETAIL_PDB +0xec (old: unkec)
    int m_nBranchesWeightLevel; // src: XBOX_RETAIL_PDB +0xf0 (old: unkf0)
    float m_sWindInfo; // src: XBOX_RETAIL_PDB +0xf4 (old: unkF4)
    float unkF8;
    float unkFC;
    float unk100;
    float unk104;
    int unk108;
    Sub10c m_sub10c;

    CTreeEngine(int param);
    virtual ~CTreeEngine();

    void SetWind(float fStrength);
    void CTreeEngine_GetSize(float* a, float* b);
    void SetSize_00b2bd20(float fSize, float fVariance);
    float GetNormalizedValue();
    void UpdateFields_00b2bdc0(float a, float b);
    void InitSeed(unsigned int seed);
    void SetSeed(int nSeed);
    bool Parse_00b2b550(CTreeFileAccessImpl* cFile);
    void ParseTreeInfo(ElementIterator* cFile);
    void ParseLeafCluster(ElementIterator* cFile);
    void CTreeEngine_ParseFlareSeed(ElementIterator* a);
    void ParseLodInfo(ElementIterator* cFile);
    void ParseBranchInfo(ElementIterator* cFile);
    void BuildBranchLods();
    void ParseTextureControls(TreeFileAccess* cFile);
    void ParseFlareInfo(Reader* cFile);
};
