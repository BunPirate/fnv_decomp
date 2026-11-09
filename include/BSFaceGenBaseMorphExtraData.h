#pragma once

#include "NiExtraData.h"
#include "NiPoint3.h"

// pdb: class BSFaceGenBaseMorphExtraData, size 0x1c (here 0x18), bases: NiExtraData, 4 members
class BSFaceGenBaseMorphExtraData : public NiExtraData
{
public:
    BSFaceGenBaseMorphExtraData(NiGeometry* apMesh, NiPoint3* apAdditionalVertices, unsigned int aiAdditionalVerticesCount);
    virtual ~BSFaceGenBaseMorphExtraData();
    virtual const NiRTTI* GetRTTI() const;

    NiPoint3* GetVertices();
    unsigned int GetPointerByFlag(unsigned int);
    void* FUN_006626f0(unsigned int flags);
    void UpdateFields_00662720();

    static const NiRTTI ms_kRTTI;

    NiPoint3* vertices;
    unsigned int count;
    unsigned int originalCount;
};
