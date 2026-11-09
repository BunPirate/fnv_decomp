#pragma once

#include "NiIntegerExtraData.h"

// pdb: class BSDecalPlacementVectorExtraData, size 0x40, bases: NiIntegerExtraData, 3 members
class BSDecalPlacementVectorExtraData : public NiIntegerExtraData
{
  public:
    struct ExtraList
    {
        void* head;
        void* tail;
        unsigned int size;

        ExtraList();
        ~ExtraList();
        void ReleaseStorage_00c64710();
    };

    BSDecalPlacementVectorExtraData(int iValue);
    virtual ~BSDecalPlacementVectorExtraData();
    void LinkToObject(void* apObject);
    // NiMemObject's operator new (0x00aa13e0), redeclared: blk_00c60000_od_ob1_variant's 0x00c63c30 inlines its body
    // for this class only, so that unit defines it inline here.
    static void* operator new(unsigned int size);

    unsigned short usGroupCount;
    unsigned short unk12;
    void* pDecalPlacementGroups[8];
    ExtraList skinnedObjects;
};
