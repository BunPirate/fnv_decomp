#pragma once
class TESFile;

// src: XBOX_PDB (DecalData, 36 bytes); ctor 0x00593240.
// pdb: class DecalData, size 0x24, 1 members
class DecalData
{
public:
    // Exe ctor 0x00593240 and Load 0x00593450 use a 36-byte packed decal record.
    class DataRecordView
{
public:
    float m_fDecalMinWidth;
    float m_fDecalMaxWidth;
    float m_fDecalMinHeight;
    float m_fDecalMaxHeight;
    float m_fProjectionDepth;
    float m_fShininess;
    float m_fParallaxScale;
    unsigned char m_ucParallaxPasses;
    unsigned char cFlags;
    unsigned char layoutPadding1E[2];
    unsigned int iColor;
};
    DataRecordView Data;

    DecalData();
    ~DecalData();
    DataRecordView* GetData();
    void Load(TESFile* apFile);
    void Copy(DecalData* apCopy);
    void DECAL_DATA_DATA_Endian();
};
