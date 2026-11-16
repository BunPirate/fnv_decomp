#pragma once

#include "QueuedFile.h"

class BSFile;
class BSFileEntry;

// pdb: class QueuedFileEntry, size 0x30, bases: QueuedFile, 2 members
class QueuedFileEntry : public QueuedFile
{
public:
    QueuedFileEntry(int priority);
    virtual ~QueuedFileEntry();
    virtual void GenerateKey();
    virtual unsigned char GetFileIndex();

    QueuedFileEntry& operator=(const QueuedFileEntry& other);
    char* GetFileName();
    void SetFileName(char* name);
    void SetFileName(const char* name);
    BSFileEntry* GetFileEntry();
    void SetFileEntry(BSFileEntry* entry);
    void LookupFileEntry(int aeArchiveTypeIndex);
    void LookupFileEntryByArchive(int aeArchiveTypeIndex);
    BSFile* GetFile(int archive, int flags);
    void GetLookupFileName(int aeArchiveTypeIndex, char* apLookupFileName);
    bool GetDescription(char* apDescription, unsigned int aiBufferSize, char* apFileEntryTypeDescription);
    void SetFileName_00c3cee0(const char* apFileName);

    char* pFileName;
    BSFileEntry* pFileEntry; // src: XBOX_RETAIL_PDB +0x2c (old: m_pFileEntry)
};
