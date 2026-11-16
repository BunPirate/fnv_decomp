#pragma once

#include "FileEntryList.h"

class TESFile;
class TESModelList;

class FileEntryListCollection
{
public:
    unsigned int iTextureListCount; // src: XBOX_RETAIL_PDB +0x0 (old: m_uiFileEntryCount)
    FileEntryList** pTextureLists; // src: XBOX_RETAIL_PDB +0x4 (old: m_ppElementArray)

    ~FileEntryListCollection();
    FileEntryListCollection* ClearData(unsigned int flags);
    void ClearAndDeleteArray();
    void LoadFromTESFile(TESModelList* apModelList, TESFile* apFile);
};
