#pragma once

#include "TESModel.h"

class BGSTextureSet;
class DistantTreeTextureInfo;
class NiAVObject;
class TESFile;
class TESForm;
template <class K, class V> class BSMap;

#include "BSSimpleList.h"

#include "BSSimpleList.h"

// pdb: class TESModelTextureSwap, size 0x20, bases: TESModel, 1 members
class TESModelTextureSwap : public TESModel
{
public:
    struct Texture
    {
        unsigned long textureID;
        unsigned long index3D;
        char textureName[0x80];
    };

    TESModelTextureSwap();
    virtual ~TESModelTextureSwap();
    virtual void Free();

    void InitItem(TESForm* apOwner);
    void InitializeComponent();
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
    bool SerializeList(char**, unsigned int*);
    void ApplyTextureSwapOverrides(unsigned int);
    bool CompareTextureSwaps(BaseFormComponent*);
    void LoadTextureSwapChunk(char* buffer, unsigned int size, unsigned short version);
    bool UnpackTextureSwapChunkData(void* data, unsigned int size, unsigned int version);
    DistantTreeTextureInfo* GetTexSwap(int aiIndex);
    void AddTexSwap(const char* apObjName, int aiIndex, BGSTextureSet* apTexSet);
    void ClearTexSwapList();
    void ApplyTextureSwaps(NiAVObject* ap3D);
    const char* GetModelFilePath();

    static void LoadModelTextureSwapChunk(TESModelTextureSwap* apModel, TESFile* apFile);
    static bool ApplyTextureSwapToNode(NiAVObject* object,
                                      BSMap<int, DistantTreeTextureInfo*>* swapMap,
                                      int& index);

    // Exe list-head operations use the shared eight-byte BSSimpleList pointer list.
    BSSimpleList<Texture*> textureList;
};
