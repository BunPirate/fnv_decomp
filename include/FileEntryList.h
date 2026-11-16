#pragma once

class BSFileEntry;
class ContainerItemExtra;
class FileFormCollection;
class TESFile;
class TESForm;

class FileEntryList
{
public:
    FileEntryList();
    ~FileEntryList();

    bool ClearData();
    void SaveToBuffer(FileFormCollection*);
    void LoadFromBuffer(FileFormCollection*, unsigned int, TESForm*, char*);
    void Save(int, char*);
    void Load(TESFile*, TESForm*, char*);
    void Load(TESFile*, TESForm*, const char*);
    void Copy(FileEntryList*);
    void Copy(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    unsigned char GetTextureCount();
    BSFileEntry** GetTextureOffsetArray();
#if !defined(_MSC_VER)
    void* __vecDelDtor(unsigned int);
#endif

    unsigned char cTextureCount; // src: XBOX_RETAIL_PDB +0x0 (old: m_ucFileEntryCount)
    union
    {
        unsigned char layoutPadding1[3];
    };
    BSFileEntry** pTextureOffsetArray; // src: XBOX_RETAIL_PDB +0x4 (old: m_ppFileEntries)
};

