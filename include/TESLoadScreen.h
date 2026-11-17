#pragma once

#include "TESForm.h"
#include "TESTexture.h"
#include "TESDescription.h"
#include "MagicTarget.h"
#include "TESFullName.h"
#include "TESLoadScreenType.h"

class WorldCellRecord;

// pdb: class TESLoadScreen, size 0x40, bases: TESForm, TESTexture, TESDescription, 3 members
class TESLoadScreen : public TESForm, public TESTexture, public TESDescription
{
public:
    TESLoadScreen();
    virtual ~TESLoadScreen();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual void InitItem();

    bool Load(TESFile* apFile);
    void ClearLoadFormList();
    bool MatchesFormLocation(TESForm* form);
    bool IsRefFlag400Set();
    bool IsDefaultLoadScreen();
    int GetLoadScreenTypeDataType();
    TESLoadScreenType* GetLoadScreenType();
    void SetLoadScreenType(TESLoadScreenType* type);
    void CopyFormData(TESForm* form);
    void CopyLoadScreenData(TESForm* apCopy);
    bool CompareFormData(TESLoadScreen* apCompare);
    bool CompareLoadScreenData(void* apCompare);

    BSSimpleList<WorldCellRecord*> LoadFormList; // src: XBOX_RETAIL_PDB +0x2c (old: m_kWorldCellRecordList)
    TESLoadScreenType* pLoadScreenType; // src: XBOX_RETAIL_PDB +0x34 (old: m_pLoadScreenType)
    BSStringT<char> cDescText; // src: XBOX_RETAIL_PDB +0x38 (old: m_kLoadScreenText)
};
