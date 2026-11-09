#pragma once

#include "TESForm.h"

enum DEFAULT_OBJECT;

// pdb: class BGSDefaultObjectManager, size 0xa0, bases: TESForm, 1 members
class BGSDefaultObjectManager : public TESForm
{
public:
    TESForm* m_apDefaultObjects[34];

    BGSDefaultObjectManager();
    virtual ~BGSDefaultObjectManager();

    virtual void InitItem();

    void ResetFormData();
    void Save();
    bool IsFormInitialized() const;
    bool Load(TESFile* apFile);

    static BGSDefaultObjectManager* Instance();
    static TESForm* GetDefaultObjectByIndex(DEFAULT_OBJECT aeObject);
    static TESForm* GetDefaultObjectByIndex(int aeObject);
    static BGSDefaultObjectManager* ms_pSystemUtility;
};
