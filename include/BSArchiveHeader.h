#pragma once

// The 0x24-byte BSA file header (the 'BSA\0' record at the start of every archive). In Archive it is the
// BSArchive base at +0x160; Archive's constructor (0x00af7eb0) reads 0x24 bytes into it after its
// constructor 0x00afd8b0 sets tag 'BSA', version 0x68, header size 0x24 and zeroes the rest.
// pdb: class BSArchiveHeader, size 0x24, 9 members
class BSArchiveHeader
{
public:
    BSArchiveHeader();  // 0x00afd8b0

    // Inline helpers of Archive's constructor (0x00af7eb0, /Ob1).
    unsigned int GetDirectoryCount()
    {
        return iDirectories;
    }
    unsigned int GetDirectoryNamesLength()
    {
        return iDirectoryNamesLength;
    }
    unsigned int GetFileNamesLength()
    {
        return iFileNamesLength;
    }
    unsigned int GetVersion()
    {
        return iVersion;
    }
    bool IsValid()
    {
        return iTag == 0x415342;
    }
    bool IsVersionSupported()
    {
        return iVersion <= 0x68;
    }
    bool HasArchiveFlag(unsigned int auiFlag)
    {
        return (oFlags & auiFlag) != 0;
    }
    static void SetFlag(unsigned int& auiField, unsigned int auiMask, bool abValue)
    {
        auiField = abValue ? auiField | auiMask : auiField & ~auiMask;
    }
    // Archives older than version 0x68 do not have archive flag 0x100.
    void ClearVersionFlag()
    {
        SetFlag(oFlags, 0x100, false);
    }

    unsigned int iTag;                   // +0x00 0x00415342 ('BSA')
    unsigned int iVersion;               // +0x04 (0x68 here; the loader accepts <= 0x68)
    unsigned int iHeaderSize;            // +0x08 (0x24)
    // +0x0c archive flags: 1 directory names, 2 file names, 8/0x10/0x20 per-type cache requests,
    // 0x80 always cache, 0x100 (version 0x68 only)
    unsigned int oFlags;
    unsigned int iDirectories;        // +0x10
    unsigned int iFiles;             // +0x14
    unsigned int iDirectoryNamesLength;  // +0x18
    unsigned int iFileNamesLength;       // +0x1c
    unsigned short iArchiveType;               // +0x20 archive type flags (1 << ARCHIVE_TYPE)
    unsigned short m_usReserved;            // +0x22
};
