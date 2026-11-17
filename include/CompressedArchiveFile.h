#pragma once

#include "ArchiveFile.h"

// pdb: class CompressedArchiveFile, size 0x1c4 (here 0x178), bases: ArchiveFile, 7 members
class CompressedArchiveFile : public ArchiveFile
{
public:
    CompressedArchiveFile(const char* fileName, Archive* archive, unsigned int offset,
                          unsigned int size, int mode);
    CompressedArchiveFile(unsigned int fileName, Archive* archive, unsigned int offset,
                          unsigned int size, unsigned int mode);

    virtual ~CompressedArchiveFile();
    virtual void SetEndianSwap(bool bDoSwap);
    virtual void Seek(int aiByteCount, int aiSeekFlags);

    void DestroyCompressedArchiveFile();
    bool CompressedArchiveFile_Open(bool a1, bool a2);
    void FUN_00aa15a0();
    unsigned int ReadAtOffset(void* buffer, unsigned int size, int mode);
    unsigned int CompressedArchiveFile_ReadF(char* buffer, unsigned int size);
    void* FUN_00afc6c0(unsigned int flags);
    void* FUN_00afc6f0(unsigned int flags);

    void* m_pArchiveStream;
    char* m_pCompressedBuffer;
    unsigned int m_uiCompressedSize;
    unsigned int m_uiUncompressedSize;
    unsigned int m_uiCompressedPosition;
    unsigned int m_uiUncompressedPosition;
};
