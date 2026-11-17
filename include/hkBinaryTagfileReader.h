#pragma once

#include "hkTagfileReader.h"
#include "hkArray.h"

class hkClass;
class hkStatisticsCollector;
struct DataObjectImplReference;

// pdb: class hkBinaryTagfileReader, size 0x8 (here 0x30), bases: hkTagfileReader, 0 members
class hkBinaryTagfileReader : public hkTagfileReader
{
public:
    virtual ~hkBinaryTagfileReader();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual unsigned int __stdcall hkBinaryTagfileReader_load(unsigned int a, unsigned int b, unsigned int c);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    hkArray<char*> m_pStringFunctions;

    int ReadSignedVarInt32() throw();
    __int64 ReadVarInt();
    void hkIArchive_readArrayGeneric(void* array, int elemsize, int arraySize) throw();
    void Reader_readBitfield(int numMembers, hkArray<char>& bout) throw();
    void ForwardCall_00dd90d0(void* pvBuf, int iNumBytes) throw();
    char* Reader_readString();
    void ReadByteArray(void* array, int elemsize, int arraySize);
    int ReadTag();
    int Reader_readClass();
    DataObjectImplReference Reader_readObject(int objectTag);
    DataObjectImplReference ProcessEntries_00dc6e50();
};
