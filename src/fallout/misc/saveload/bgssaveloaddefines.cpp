// fallout/misc/saveload/bgssaveloaddefines.cpp: SaveGameSizeState (15 functions)

#include "../../../../include/TESForm.h"
#include "../../../../include/BGSSaveLoadGame.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/SIZE_TYPE.h"
#include <string.h>

void LogWarning(const char* message, ...);

class TESObjectCELL;
class TESWorldSpace;

class SaveGameSizeState
{
  public:
    virtual void UnknownSlot();
    virtual unsigned int Write(unsigned int size);
    unsigned int iSize;
    unsigned int iPosition;
    unsigned int iDataLength;
    void RecordSizeAndLength(unsigned int size, unsigned int length);
    void RecordRequestedSize(unsigned int requested, unsigned int savedSize);
};

class SaveLoadFile
{
  public:
    unsigned int Read(void* apBuffer, unsigned int aiBytes);
};

// @fnv 0x008453a0
void SaveGameSizeState::RecordRequestedSize(unsigned int requested, unsigned int savedSize)
{
    iSize = 0;
    iPosition = 0;
    iDataLength = 0;
    if (savedSize > requested)
    {
        requested = savedSize;
    }
    if (requested > 0)
    {
        iSize = Write(requested);
        iDataLength = requested;
    }
    if (savedSize > 0)
    {
        RecordSizeAndLength(iSize, savedSize);
        iPosition = savedSize;
    }
}

// @fnv 0x00845e50
// src: XBOX_RETAIL_PDB 0x00845e50
// pdb: LoadGameSizeFromFile | BGSSaveLoadDefines.obj | retail, call graph (shared callers), high
// pdb params: apFile, ariSize, aeSizeType
// pdb locals: csize, ssize
unsigned int LoadGameSizeFromFile(SaveLoadFile* apFile, unsigned int& ariSize, SIZE_TYPE aeSizeType)
{
    switch (aeSizeType)
    {
    case SIZE_TYPE_SIZE_CHAR: {
        unsigned char ucByte = 0;
        apFile->Read(&ucByte, 1);
        ariSize = ucByte;
        return 1;
    }
    case SIZE_TYPE_SIZE_SHORT: {
        unsigned short usShort = 0;
        apFile->Read(&usShort, 2);
        ariSize = usShort;
        return 2;
    }
    case SIZE_TYPE_SIZE_INT:
        apFile->Read(&ariSize, 4);
        return 4;
    default:
        return 0;
    }
}

// @fnv 0x00845f70
unsigned int GetEncodedIntegerSize(unsigned int value)
{
    unsigned int type = 0;
    if (value < 0x40)
    {
        type = 1;
    }
    else if (value < 0x4000)
    {
        type = 2;
    }
    else if (value < 0x40000000)
    {
        type = 4;
    }
    type += 1;
    return type;
}

// Checks the form type: stores the form as world if type 0x41, as cell if type 0x39, and returns whether either matched.
// @fnv 0x00846190
// pdb: GetLocationCellOrWorld | BGSSaveLoadDefines.obj | debug, call graph, medium
// pdb params: apLocation, arpCell, arpWorld
bool GetCellAndWorldspaceForForm(TESForm* form, TESObjectCELL*& cell, TESWorldSpace*& world)
{
    if (!form)
    {
        return false;
    }
    if (static_cast<const TESForm*>(form)->GetFormType() == 0x41)
    {
        world = (TESWorldSpace*)form;
        return true;
    }
    else if (static_cast<const TESForm*>(form)->GetFormType() == 0x39)
    {
        cell = (TESObjectCELL*)form;
        return true;
    }
    return false;
}

#include <string.h>

void LogWarning(const char* message, ...);

class TESObjectCELL;
class TESWorldSpace;

// Encodes value into buffer using 1, 2 or 4 bytes depending on its magnitude, logs an error if too large, then appends '|'.
// @fnv 0x00845fc0
// pdb: SaveVariableSizedValueToBuffer | BGSSaveLoadDefines.obj | debug, object-file run extension, low
// pdb params: apBuffer, aiVariableValue
// pdb locals: isize, cvalue, svalue, ivalue
void WriteEncodedInteger(char* buffer, unsigned int value)
{
    unsigned int size = 0;
    if (value < 0x40)
    {
        unsigned char encoded = (unsigned char)(value << 2);
        size = 1;
        memcpy(buffer, &encoded, size);
    }
    else if (value < 0x4000)
    {
        unsigned short encoded = (unsigned short)((value << 2) | 1);
        size = 2;
        memcpy(buffer, &encoded, size);
    }
    else if (value < 0x40000000)
    {
        unsigned int encoded = (value << 2) | 2;
        size = 4;
        memcpy(buffer, &encoded, size);
    }
    else
    {
        LogWarning("SAVELOAD: Variable-sized value %08X is too large to be stored.", value);
    }
    buffer[size] = '|';
}

// @fnv 0x00846080
// src: XBOX_RETAIL_PDB 0x00846080
// pdb: LoadVariableSizedValueFromBuffer | BGSSaveLoadDefines.obj | retail, call graph, high
// pdb params: apBuffer, ariVariableValue
// pdb locals: cvalue, esizeType, isize, svalue, ivalue
unsigned int LoadVariableSizedValueFromBuffer(char* apBuffer, unsigned int& ariVariableValue)
{
    unsigned int size;
    unsigned char encodedType;
    unsigned int type;
    type = 0;
    encodedType = apBuffer[0];
    size = encodedType & 3;
    switch (size)
    {
    case 0: {
        char encoded = 0;
        type = 1;
        memcpy(&encoded, apBuffer, type);
        encoded = (unsigned char)encoded >> 2;
        ariVariableValue = (unsigned char)encoded;
        break;
    }
    case 1: {
        unsigned short encoded = 0;
        type = 2;
        memcpy(&encoded, apBuffer, type);
        encoded = (unsigned short)(encoded >> 2);
        ariVariableValue = encoded;
        break;
    }
    case 2: {
        unsigned int encoded = 0;
        type = 4;
        memcpy(&encoded, apBuffer, type);
        encoded >>= 2;
        ariVariableValue = encoded;
        break;
    }
    }
    if (apBuffer[type] != '|')
    {
        LogWarning("SAVELOAD: Invalid spacer hit while loading data from the buffer");
    }
    type += 1;
    return type;
}


MemoryManager* __cdecl MemoryManager_Instance(void);

// @fnv 0x00401030
// src: COMMUNITY 0x00401030
// pdb: TESFile::FreeDecompressedBuffer | TESFile.obj | retail, call graph, medium
void __cdecl FormHeapFreeAndLog_00401030(void* ptr)
{
    MemoryManager_Instance()->Deallocate(ptr);
}

// @fnv 0x00845d20
void ReadFileIntoBuffer(SaveLoadFile* file, unsigned int* apuiBuffer, unsigned int size)
{
    file->Read(apuiBuffer, size);
}

extern unsigned int DAT_011a2040[];

// @fnv 0x00845d70
// src: XBOX_PDB 0x00845d70
unsigned int GetSizeTypeSize(unsigned int index)
{
    return DAT_011a2040[index];
}

void* __cdecl _memcpy(void* dst, const void* src, unsigned int size);

// Copies value into dst as 1, 2 or 4 bytes depending on sizeType (0, 1 or 2).
// @fnv 0x00845de0
// pdb: SaveGameSizeToFile | BGSSaveLoadDefines.obj | retail, object-file run extension, low
// pdb note: debug build links it to SaveGameSizeToBuffer
// pdb params: apFile, aiSize, aeSizeType
// pdb locals: csize, ssize
void __cdecl WriteTypedValue(void* apDest, unsigned int value, unsigned int sizeType)
{
    switch (sizeType)
    {
    case 0: {
        unsigned char c = (unsigned char)value;
        _memcpy(apDest, &c, 1);
        break;
    }
    case 1: {
        unsigned short s = (unsigned short)value;
        _memcpy(apDest, &s, 2);
        break;
    }
    case 2:
        _memcpy(apDest, (void*)&value, 4);
        break;
    }
}

struct FUN_00846330_shell
{
    void BGSSaveLoadFile_Write(int a, int b);
};

// @fnv 0x00845d00
void ForwardToShell(FUN_00846330_shell* apShell, int aiArg1, int aiArg2)
{
    apShell->BGSSaveLoadFile_Write(aiArg1, aiArg2);
}

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
// @fnv 0x00845cc0
// src: XBOX_PDB 0x00845cc0
// pdb: SaveGameWarning | BGSSaveLoadDefines.obj | retail, upstream name already matches, high
// pdb params: apMessage, varArgs
void __cdecl SaveGameWarning(const char* apMessage, ...)
{
    char* varArgs;
    varArgs = (char*)&apMessage + 4;
    if (g_BGSSaveLoadGame)
        g_BGSSaveLoadGame->SaveGameWarningFunction(apMessage, varArgs);
    varArgs = 0;
}

// @fnv 0x00845d40
// src: COMMUNITY 0x00845d40
unsigned int GetSizeTypeForSize(unsigned int value)
{
    if (value <= 0xff)
        return 0;
    else if (value <= 0xffff)
        return 1;
    return 2;
}

void* __cdecl __memcpy(void* dest, const void* src, unsigned int size);

// Copies 1, 2 or 4 bytes from source into value according to sizeType and returns the number of bytes copied, or 0 for other size types.
// @fnv 0x00845ee0
// pdb: LoadGameSizeFromBuffer | BGSSaveLoadDefines.obj | debug, call graph, medium
// pdb params: apBuffer, ariSize, aeSizeType
// pdb locals: csize, ssize
unsigned int ReadValueBySizeType(const void* source, unsigned int* value, unsigned int sizeType)
{
    switch (sizeType)
    {
    case SIZE_TYPE_SIZE_CHAR: {
        unsigned char c = 0;
        __memcpy(&c, source, 1);
        *value = c;
        return 1;
    }
    case SIZE_TYPE_SIZE_SHORT: {
        unsigned short s = 0;
        __memcpy(&s, source, 2);
        *value = s;
        return 2;
    }
    case SIZE_TYPE_SIZE_INT:
        __memcpy(value, source, 4);
        return 4;
    default:
        return 0;
    }
}

namespace fnv_00845d80 {
struct FUN_00846330_shell
{
    void BGSSaveLoadFile_Write(int, int);
};

// @fnv 0x00845d80
// pdb: LoadGameDataFromFileFunction | BGSSaveLoadDefines.obj | retail, object-file run extension, low
// pdb note: debug build links it to SaveGameSizeToFile
// pdb params: apFile, apData, aiSize
void WriteValueByType(FUN_00846330_shell* self, unsigned short ausValue, int type)
{
    switch (type)
    {
    case 0: {
        char b = ausValue;
        self->BGSSaveLoadFile_Write((int)&b, 1);
        break;
    }
    case 1: {
        short s = ausValue;
        self->BGSSaveLoadFile_Write((int)&s, 2);
        break;
    }
    case 2:
        self->BGSSaveLoadFile_Write((int)&ausValue, 4);
        break;
    }
}
}  // namespace fnv_00845d80
