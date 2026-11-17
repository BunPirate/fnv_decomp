#pragma once

#include "NiBinaryStream.h"
#include <stdio.h>

// pdb: class NiFile, size 0x74 (here 0x30), bases: NiBinaryStream, 17 members
class NiFile : public NiBinaryStream
{
  public:
    enum OpenMode  // values: Xbox PDB NiFile::OpenMode
    {
        READ_ONLY = 0,
        WRITE_ONLY = 1,
        APPEND_ONLY = 2
    };

    virtual ~NiFile();
    virtual operator bool();
    using NiBinaryStream::Seek;
    virtual void Seek(int iOffset, int iWhence);
    virtual char* FileName();
    virtual unsigned int GetFileSize();

    bool IsGood();
    bool Open(bool, bool);
    bool Flush();
    unsigned int FileRead(void*, unsigned int);

    static NiFile* __cdecl GetFile(const char* pcName, OpenMode eMode, unsigned int uiSize);
    static NiFile* __cdecl GetFile(const char* pcName, int eMode, unsigned int uiSize);
    static unsigned int RequestFileAccess(const char*, unsigned int, unsigned int);
    static unsigned int __cdecl WriteBytesToFile(const void*, unsigned int, unsigned int, FILE*);

    // Members after the NiBinaryStream base (ctor 0x00aa14d0; FileRead 0x00aa1750 advances +0x1C).
    unsigned int m_uiBufferAllocSize; // +0x10
    unsigned int m_uiBufferReadSize;  // +0x14
    unsigned int m_uiPos;             // +0x18
    unsigned int m_uiFilePos;         // +0x1C
    char* m_pBuffer;                  // +0x20
    FILE* m_pFile;                    // +0x24
    OpenMode m_eMode;                 // +0x28
    bool m_bGood;                     // +0x2C
};
