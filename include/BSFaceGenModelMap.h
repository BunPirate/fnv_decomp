#pragma once

#include "NiTMapItem.h"
class Sol;
class SolPtr;

// pdb: class BSFaceGenModelMap, size 0x24, 3 members
class BSFaceGenModelMap
{
public:
    virtual void vf00();

    char Map[0x20]; // src: XBOX_RETAIL_PDB +0x4 (old: pad)

    BSFaceGenModelMap();
    bool GetModel(void* key, SolPtr* result);
    void SetMaxDataSize(int aDataType, char* auiSize);
    void SetModel(void* key, Sol* model);
    bool HasModels();
    void PurgeUnusedModels(bool);
    void FreeStringMapObject(NiTMapItem<const char*, void*>* stringMap);
    bool HasFaceGenData(const char*);
};
