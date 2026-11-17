// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern unsigned int __cdecl __splitpath_s(const char* filename, char* drive, unsigned int driveMax, char* dir,
                                          unsigned int dirMax, char* fname, unsigned int fnameMax, char* ext,
                                          unsigned int extMax);

// Splits pcFilename into drive, directory, file name and extension buffers via __splitpath_s and returns true.
// @fnv 0x00e983f0
// src: COMMUNITY 0x00e983f0
// pdb: NiD3DUtility::GetSplitPath | NiD3DUtility.obj | retail, upstream name already matches, high
// pdb params: pcFilename, pcDrive, pcDir, pcFname, pcExt
bool __cdecl NiD3DUtility_GetSplitPath(const char* pcFilename, char* pcDrive, char* pcDir, char* pcFname, char* pcExt)
{
    __splitpath_s(pcFilename, pcDrive, 3, pcDir, 0x104, pcFname, 0x104, pcExt, 0x100);
    return true;
}

#include <string.h>

struct SplitPathOutputBuffers
{
    unsigned int driveStorage;
    char ext[0x100];
    char fname[0x100];
    char dir[0x104];
};

// Extracts the file extension from pcFilename via __splitpath_s and copies it into pcDest, returning true.
// @fnv 0x00e98430
// src: XBOX_PDB 0x00e98430
// pdb: NiD3DUtility::GetFileExtension | NiD3DUtility.obj | retail, upstream name already matches, high
// pdb params: pcFilename, pcExt, uiMaxLen
// pdb locals: acFileExt, acDir, acFileName, stExtLen, acDrive
bool __cdecl NiD3DUtility_GetFileExtension(const char* pcFilename, char* pcExt, unsigned int uiMaxLen)
{
    SplitPathOutputBuffers buffers;
    unsigned int uiLen;

    __splitpath_s(pcFilename, (char*)&buffers.driveStorage, 3, buffers.dir, 0x104, buffers.fname, 0x100, buffers.ext,
                  0x100);

    uiLen = strlen(buffers.ext);
    strncpy_s(pcExt, uiMaxLen, buffers.ext, uiLen);
    return true;
}
