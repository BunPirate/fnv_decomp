
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_008526d0_shell
{
    int m_iWordAt00;
    void* __thiscall Read(int a, int b, int c, int d);
    int __thiscall BSSystemFile_Read(int a, int b, int c, int d);
};

// @fnv 0x008526d0
// src: XBOX_DEBUG_PDB 0x008526d0
// pdb: BSSystemFile::Read | BGSSaveLoadManager.obj | debug, call graph (shared callers), high
// pdb params: apvBuffer, auiBytes, auiRead
int __thiscall FUN_008526d0_shell::BSSystemFile_Read(int a, int b, int c, int d)
{
    m_iWordAt00 = (int)Read(a, b, c, d);
    return m_iWordAt00;
}

struct FUN_00856350_shell
{
    void* m_p;
    void* BSSystemFile_DoWrite(void* a, void* b, void* c, void* d);
    void* SetAndReturnPointer(void* a, void* b, void* c, void* d);
};

// Stores the result of FUN_00afede0(a, b, c, d) in m_p and returns it.
// @fnv 0x00856350
// pdb: BSSystemFile::Write | TESSaveLoadGame.obj | debug, call graph, medium
// pdb params: apvBuffer, auiBytes, auiWrite
void* FUN_00856350_shell::SetAndReturnPointer(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    m_p = BSSystemFile_DoWrite(apArg1, apArg2, apArg3, apArg4);
    return m_p;
}

struct S_008785e0
{
    int field0;
    int SetAndGetField0(int a, int b, int c, int d);
    int BSSystemFile_DoSeek(int auiOffset, int aeWhence, int auiPos, int d);
};
// Stores the result of FUN_00afeef0(a, b, c, d) into field0 and returns it.
// @fnv 0x008785e0
// pdb: MemoryManagerFile::MemoryManagerFile | MemoryManagerFile.obj | retail, object-file run extension, low
// pdb note: debug build links it to BSSystemFile::Seek
// pdb params: apFileName
int S_008785e0::SetAndGetField0(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    field0 = BSSystemFile_DoSeek(aiArg1, aiArg2, aiArg3, aiArg4);
    return field0;
}

#include <windows.h>
struct FileSizeInfo
{
    unsigned int m_eErrorCode;
    unsigned int __thiscall GetValue(LARGE_INTEGER* liFileSize);
    unsigned int __thiscall BSSystemFile_GetSize(LARGE_INTEGER& auiSize);
};

// Stores the result of GetValue into m_eErrorCode and returns it.
// @fnv 0x0065c290
// src: COMMUNITY 0x0065c290
// pdb: BSSystemFile::DoGetSize | BSSystemFile_Xenon.obj | retail, call graph (shared callers), low
// pdb note: debug build links it to BSSystemFile::GetSize
// pdb params: auiSize
// pdb locals: iSize, eResult
unsigned int __thiscall FileSizeInfo::BSSystemFile_GetSize(LARGE_INTEGER& auiSize)
{
    m_eErrorCode = GetValue(&auiSize);
    return m_eErrorCode;
}

// @fnv 0x00aff0b0
// src: XBOX_PDB 0x00aff0b0
// pdb: BSSystemFile::DeleteFileA | BSSystemFile_Xenon.obj | retail, upstream name already matches, high
// pdb params: apcPath
int BSSystemFile_DeleteFileA(const char* apcPath)
{
    return DeleteFileA(apcPath) ? 0 : 4;
}
