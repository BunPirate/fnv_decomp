#pragma once

// pdb: class NiSearchPath, size 0x210, 3 members
class NiSearchPath
{
public:
    NiSearchPath();
    virtual ~NiSearchPath();
    virtual void Reset_00aa2500();
    virtual bool ResolveSearchPath(char* pcPath, unsigned int uiStringLen);

    unsigned int m_uiNextPath; // src: XBOX_RETAIL_PDB +0x4 (old: m_uiSearchPathValue)
    char m_acFilePath[260]; // src: XBOX_RETAIL_PDB +0x8 (old: m_acFilePathBuffer)
    char m_acReferencePath[260]; // src: XBOX_RETAIL_PDB +0x10c (old: m_acResolvedPath)

    void SetPath(const char* pcFilePath);
    static void operator delete(void* p);
};
