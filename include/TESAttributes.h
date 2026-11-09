#pragma once

#include "BaseFormComponent.h"

namespace ActorValue
{
    enum Index;
}

class BGSSaveFormBuffer;
class BGSLoadFormBuffer;

// pdb: class TESAttributes, size 0xc, bases: BaseFormComponent, 1 members
class TESAttributes : public BaseFormComponent
{
public:
    TESAttributes();
    ~TESAttributes();
    TESAttributes& operator=(const TESAttributes& other);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    unsigned int Save(void* buffer);
    unsigned int Load(void* buffer);
    void BaseFormRecord(BaseFormComponent* apCopyFC);
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
    unsigned int GetAttributeDataSize();
    unsigned char GetAttributeValue(int index);
    unsigned char GetAttributeValue(ActorValue::Index index);
    void SetAttributeValue(int aeAttribute, unsigned char acValue, bool abMarkChange);
    void SetAttributeValue(ActorValue::Index aeAttribute, unsigned char acValue, bool abMarkChange);
    void SetAttributeValue(unsigned char aeAttribute, unsigned char acValue, bool abMarkChange);
    void SetAttributeValue(unsigned int aeAttribute, unsigned char acValue, bool abMarkChange);
    void SetAttribute(unsigned char index);
    unsigned char GetAttributeStrength();
    unsigned char GetPerception();
    unsigned char GetEndurance();
    unsigned char GetCharisma();
    unsigned char GetIntelligence();
    unsigned char GetAgility();
    unsigned char GetLuck();
    unsigned char GetStrength();
    unsigned char GetAttributeValue7();
    unsigned char GetAttributeValue10();
    void SetStrength(unsigned char value);
    void SetPerception(unsigned char acValue);
    void SetEndurance(unsigned char value);
    void SetCharisma(unsigned char acValue);
    void SetIntelligence(unsigned char acValue);
    void SetAgility(unsigned char value);
    void SetLuck(unsigned char acValue);
    unsigned short GetSaveSize(unsigned int flags);
    void SaveGame(BGSSaveFormBuffer* buffer);
    void SaveGame(unsigned int buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void LoadGame(unsigned int aiFlags, unsigned int aiCurrentFlags);
    void LoadDataIfChanged(BGSLoadFormBuffer* buffer);


    unsigned char cAttribute[7];
    unsigned char layoutPaddingB[1];
};
