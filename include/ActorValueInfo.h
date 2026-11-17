#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESDescription.h"
#include "TESIcon.h"

class ActorValueOwner;

namespace ActorValue
{
    enum Index;
    enum Section;
}

typedef float (*ActorValueDeriveCallback)(ActorValueOwner*, ActorValue::Index);
typedef ActorValue::Index (*ActorValueMappingCallback)(ActorValueOwner*, ActorValue::Index);
typedef void (*ActorValueModifiedCallback)(ActorValueOwner*, ActorValue::Index, float, float, ActorValueOwner*);

#if defined(FNV_ACTORVALUE_DECLS_H)
class ActorValueInfo
#else
struct ActorValueInfo
#endif
    : public TESForm, public TESFullName, public TESDescription, public TESIcon
{
public:
    ActorValueInfo(int, const char*);
    virtual ~ActorValueInfo();

    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* apCompare);
    virtual char* GetTextureResourcePath();

    bool Load(TESFile* apFile);
    void Save();
    void Copy(TESForm* apCopy);
    void SetFormID(unsigned int, bool);
    bool SetScriptName(const char*);
    void SetScriptName(const char*) const;
    bool SetScriptName(ActorValueInfo*);
    void SetEnumerated(int count, ...);
    char* GetEnumeratedName(int);
    static unsigned int GetActorValueFormID(ActorValue::Index);
    static unsigned int GetActorValueFormID(int);
    static int GetAffectedActorValue(unsigned int);

    char* m_pName;
    BSStringT<char> m_cAbbreviation;
    unsigned int uFlags;
    ActorValue::Section eAVType; // src: XBOX_RETAIL_PDB +0x48 (old: m_iSection)
    ActorValueDeriveCallback m_pDerivedValueFunction;
    ActorValueMappingCallback pMappingFunction; // src: XBOX_RETAIL_PDB +0x50 (old: m_pActorValueMapping)
    ActorValueModifiedCallback pModifiedCallback; // src: XBOX_RETAIL_PDB +0x54 (old: m_pActorValueChangedCallback)
    int iNumDependentActorValues; // src: XBOX_RETAIL_PDB +0x58 (old: m_iEnumeratedValueCount)
    ActorValue::Index DependentActorValues[15]; // src: XBOX_RETAIL_PDB +0x5c (old: m_aiEnumeratedValues)
    int iEnumCount; // src: XBOX_RETAIL_PDB +0x98 (old: m_iEnumeratedNameCount)
    const char* sEnumNames[10]; // src: XBOX_RETAIL_PDB +0x9c (old: m_apEnumeratedNames)
};
