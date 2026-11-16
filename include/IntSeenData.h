#pragma once

#include "SeenData.h"

// pdb: class IntSeenData, size 0x2c, bases: SeenData, 3 members
class IntSeenData : public SeenData
{
public:
    signed char cSectionX; // src: XBOX_RETAIL_PDB +0x24 (old: field_24)
    signed char cSectionY; // src: XBOX_RETAIL_PDB +0x25 (old: field_25)
    unsigned short field_26;
    IntSeenData* pNextSection; // src: XBOX_RETAIL_PDB +0x28 (old: field_28)

    IntSeenData();
    IntSeenData(char x, char y);
    IntSeenData(unsigned char x, unsigned char y);

    virtual ~IntSeenData();
    virtual void AddToNode(NiNode* apDrawNode, NiPoint3& aSeenStart, bool abDrawSeen) override;
    virtual unsigned short GetSaveSize(bool abRecursing) override;
    virtual void SaveGame_0087a060(bool abRecursing) override;
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) override;
    virtual void LoadGame_0087a090(unsigned short count) override;

    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void* FUN_0087a140(unsigned int flags);
};
