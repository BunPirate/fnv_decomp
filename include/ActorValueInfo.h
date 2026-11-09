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
    ActorValue::Section eAVType;
    ActorValueDeriveCallback m_pDerivedValueFunction;
    ActorValueMappingCallback pMappingFunction;
    ActorValueModifiedCallback pModifiedCallback;
    int iNumDependentActorValues;
    ActorValue::Index DependentActorValues[15];
    int iEnumCount;
    const char* sEnumNames[10];
};
