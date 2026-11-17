// fallout_shared/mapmarkerdata.cpp: MapMarkerData, MapMarkerCompare, StringHolder (7 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "layout_support.h"
#include "../../include/TESFullName.h"
#include "TESFile.h"
#include "../../include/TESFile.h"

class TESReputation;

// Chunk tags of the MAP marker data record, kept as numeric enum values so the
// comparisons compile to the original immediates.
enum
{
    kMapMarkerDataChunk = 0x4B524D58,        // 'XMRK'
    kMapMarkerTypeChunk = 0x4D414E46,        // 'FNAM'
    kMapMarkerNameChunk = 0x4C4C5546,        // 'FULL'
    kMapMarkerTravelChunk = 0x4D414E54,      // 'TNAM'
    kMapMarkerReputationChunk = 0x31494D57,  // 'WMI1'
};

// member functions matched in this unit added.
#pragma pack(push, 4)
// pdb: class MapMarkerData, size 0x14, 5 members
class MapMarkerData
{
  public:
    TESFullName LocationName;           // +0x0, 12 bytes
    unsigned char cFlags;               // +0xC, 1 bytes
    unsigned char m_ucAdditionalFlags;  // +0xD, 1 bytes
    unsigned short sType;               // +0xE, 2 bytes
    TESReputation* pReputationData;     // +0x10, 4 bytes

    bool Load(TESFile* apFile);
    bool GetVisible();
    void SetVisible(bool visible);
    bool IsTravelLocation();
    void SetTravelLocation(bool travelLoc);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MapMarkerData) == 20);
FNV_STATIC_ASSERT(offsetof(MapMarkerData, LocationName) == 0);
FNV_STATIC_ASSERT(offsetof(MapMarkerData, cFlags) == 12);
FNV_STATIC_ASSERT(offsetof(MapMarkerData, m_ucAdditionalFlags) == 13);
FNV_STATIC_ASSERT(offsetof(MapMarkerData, sType) == 14);
FNV_STATIC_ASSERT(offsetof(MapMarkerData, pReputationData) == 16);

// TESFile::GetChunkData(unsigned short*) and the offset-chunk accessors are not
// declared in the bundled TESFile.h; declared here on shims following the same
// precedent.
struct TESFileChunkData16 : public TESFile
{
    bool GetChunkData(unsigned short* apData);
};

struct TESFileOffsetChunk : public TESFile
{
    unsigned int GetOffsetChunk();
    bool SetOffsetChunk(unsigned int offset);
};

// @fnv 0x00438ca0
// pdb: MapMarkerData::Load | MapMarkerData.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: uRewind, itempint
bool MapMarkerData::Load(TESFile* apFile)
{
    if (!apFile)
        return false;
    if (apFile->GetChunkID() != kMapMarkerDataChunk)
        return false;
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == kMapMarkerTypeChunk)
    {
        apFile->GetChunkData(&cFlags, 1);
        m_ucAdditionalFlags = cFlags;
        if (!apFile->NextChunk())
            return false;
    }
    if (apFile->GetChunkID() == kMapMarkerNameChunk)
    {
        TESFullNameLoader::LoadFullNameChunk(&LocationName, apFile);
    }
    else
    {
        return false;
    }
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == kMapMarkerTravelChunk)
    {
        ((TESFileChunkData16*)apFile)->GetChunkData(&sType);
    }
    else
    {
        return false;
    }
    unsigned int chunkOffset = ((TESFileOffsetChunk*)apFile)->GetOffsetChunk();
    if (!apFile->NextChunk())
        return false;
    if (apFile->GetChunkID() == kMapMarkerReputationChunk)
    {
        unsigned int reputationID = 0;
        apFile->GetChunkData(&reputationID);
        if (reputationID)
            pReputationData = (TESReputation*)reputationID;
    }
    else
    {
        ((TESFileOffsetChunk*)apFile)->SetOffsetChunk(chunkOffset);
    }
    return true;
}

// @fnv 0x00438ed0
// pdb: MapMarkerData::SetLocationName | MapMarkerData.obj | debug, object-file run extension, low
// pdb params: apName
bool MapMarkerData::GetVisible()
{
    if (cFlags & 0x1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sets or clears bit 0x1 in cFlags according to the visible argument.
// @fnv 0x0044de40
void MapMarkerData::SetVisible(bool visible)
{
    if (visible)
    {
        cFlags |= 0x1;
    }
    else
    {
        cFlags &= ~0x1;
    }
}

// @fnv 0x00438ef0
bool MapMarkerData::IsTravelLocation()
{
    if (cFlags & 0x2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sets or clears bit 0x2 in cFlags according to travelLoc.
// @fnv 0x0044de80
void MapMarkerData::SetTravelLocation(bool travelLoc)
{
    if (travelLoc)
    {
        cFlags |= 0x2;
    }
    else
    {
        cFlags &= ~0x2;
    }
}

class MapMarkerCompare : public MapMarkerData
{
  public:
    bool MapMarkerData_Compare(MapMarkerData* other);
};

// Returns true if any of LocationName, cFlags, sType, or pReputationData differs from the other MapMarkerData.
// @fnv 0x00438e40
// src: XBOX_PDB 0x00438e40
// pdb: MapMarkerData::Compare | MapMarkerData.obj | retail, upstream name already matches, high
// pdb params: apCompare
bool MapMarkerCompare::MapMarkerData_Compare(MapMarkerData* other)
{
    if (LocationName.CompareWithBase(reinterpret_cast<BaseFormComponent*>(other)))
        return true;
    if (cFlags != other->cFlags)
        return true;
    if (sType != other->sType)
        return true;
    if (pReputationData != other->pReputationData)
        return true;
    return false;
}

struct StringHolder
{
    const char* TESModel_GetModel();
    const char* MapMarkerData_GetLocationName();
};
// @fnv 0x00438eb0
// src: XBOX_PDB 0x00438eb0
// pdb: MapMarkerData::GetLocationName | MapMarkerData.obj | debug, upstream name already matches, high
const char* StringHolder::MapMarkerData_GetLocationName()
{
    return TESModel_GetModel();
}
