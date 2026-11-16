#pragma once

#include "TESForm.h"
#if !defined(FNV_LAYOUT_SUPPORT_H) && !defined(FNV64_BSSTRINGT_DEFINED)
#include "BSStringT.h"
#endif
#include "TESFullName.h"

// pdb: class TESGlobal, size 0x28, bases: TESForm, 3 members
class TESGlobal : public TESForm
{
public:
    BSStringT<char> cFormEditorID; // src: XBOX_RETAIL_PDB +0x18 (old: cGlobalEditorID)
    char cType;
    unsigned char layoutPadding21;
    unsigned short layoutPadding22;
    float fValue;

    TESGlobal();
    virtual ~TESGlobal();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* apEditorID);

    bool Load(TESFile* apFile);
    void SetValue(float value);
    float GetValue();
    bool IsConstantGlobal();
    float BSMultiBoundCapsule_QMultiBoundRadius();
};
