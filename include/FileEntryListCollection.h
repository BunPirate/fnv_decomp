#pragma once

#include "FileEntryList.h"

class TESFile;
class TESModelList;

class FileEntryListCollection
{
public:
    unsigned int iTextureListCount;
    FileEntryList** pTextureLists;

    ~FileEntryListCollection();
    FileEntryListCollection* ClearData(unsigned int flags);
    void ClearAndDeleteArray();
    void LoadFromTESFile(TESModelList* apModelList, TESFile* apFile);
};
