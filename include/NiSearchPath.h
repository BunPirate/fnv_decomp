#pragma once

// pdb: class NiSearchPath, size 0x210, 3 members
class NiSearchPath
{
public:
    NiSearchPath();
    virtual ~NiSearchPath();
    virtual void Reset_00aa2500();
    virtual bool ResolveSearchPath(char* pcPath, unsigned int uiStringLen);

    unsigned int m_uiNextPath;
    char m_acFilePath[260];
    char m_acReferencePath[260];

    void SetPath(const char* pcFilePath);
    static void operator delete(void* p);
};
