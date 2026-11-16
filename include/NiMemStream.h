#pragma once

#include "NiBinaryStream.h"

// pdb: class NiMemStream, size 0x24, bases: NiBinaryStream, 6 members
class NiMemStream : public NiBinaryStream
{
public:
    // +0x04..+0x0F are the NiBinaryStream members (SetEndianSwap 0x00aa2f80 installs the reader/writer).
    char* m_pBuffer; // src: XBOX_RETAIL_PDB +0x10 (old: m_kRayStart)
    unsigned int m_uiPos; // src: XBOX_RETAIL_PDB +0x14 (old: m_pos)
    union
    {
        unsigned int m_kRayEnd;
        int m_uiLogicalSize;
    };
    union
    {
        unsigned int m_uiSize;
        unsigned int unk1C;
    };
    union
    {
        unsigned char m_bFlag20;
        unsigned char unk20;
    };
    union
    {
        unsigned char m_bFlag21;
        unsigned char unk21;
    };

    NiMemStream();
    NiMemStream(void* buffer, unsigned int size);
    virtual ~NiMemStream();
    virtual operator bool();
    virtual void Seek(int iNumBytes);
    virtual void SetEndianSwap(bool bDoSwap);

    void NiMemStreamDestructor();
    void SetSwapMode(bool bDoSwap);
    void __thiscall Seek_00aa2d70(int iNumBytes);
    unsigned int __thiscall MemWrite(const void* pBuffer, unsigned int uiBytes);
    void FUN_00aa2fb0(char* pBuffer, int uiSize);
    void NiMemStream_NiMemStream();
    char* NiMemStream_Str();
};
