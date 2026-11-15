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

    float* m_fBillboardSize;
    float* m_fLod;
    float m_fOverrideTreeSize;
    float m_fOverrideTreeVariance;
    int m_cRandom;
    SptFilename m_sTreeInfo;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int m_pBranch;
    int m_pBranchGeometry;
    int m_vBranchInfo;
    int unk64;
    int unk68;
    int unk6c;
    int m_nNumBranchLodLevels;
    int m_vBillboardLeaves;
    int unk78;
    int unk7c;
    int unk80;
    int m_sLeafInfo;
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
    int m_vLeafLods;
    int m_bParsedLeafLods;
    int m_fMinBranchVolumePercent;
    int m_fMaxBranchVolumePercent;
    int m_fLeafReductionPercentage;
    int m_fBranchReductionFuzziness;
    int m_fLargeBranchPercent;
    int m_nBranchesWeightLevel;
    float m_sWindInfo;
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
    void CTreeEngine_SetSeed(int nSeed);
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
