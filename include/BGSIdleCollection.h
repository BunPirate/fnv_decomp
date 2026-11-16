#pragma once

#include "BaseFormComponent.h"

class Actor;
class TESFile;
class TESForm;
class TESIdleForm;
class TESObjectREFR;
template <class T, unsigned int N> class BSSimpleArray;

// pdb: class BGSIdleCollection, size 0x10, bases: BaseFormComponent, 4 members
class BGSIdleCollection : public BaseFormComponent
{
public:
    BGSIdleCollection();  // 0x00479790: BaseFormComponent(), vftable 0x0101aa98, InitializeComponent()
    ~BGSIdleCollection();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* apCompareFC);

    unsigned int GetAvailableIdles(Actor* actor, TESObjectREFR* target,
                                   BSSimpleArray<TESIdleForm*, 1024>* idles);
    void Load(TESFile* apFile);
    void InitializeComponent();
    void InitItem(TESForm* apOwner);
    void RemoveIdleEntry(unsigned int index);
    int GetPickType();

    unsigned char cIdleFlags; // src: XBOX_RETAIL_PDB +0x4 (old: m_ucIdleCount)
    unsigned char cIdleCount; // src: XBOX_RETAIL_PDB +0x5 (old: m_ucPickType)
    unsigned char layoutPadding6[2];
    TESIdleForm** pIdleArray; // src: XBOX_RETAIL_PDB +0x8 (old: m_ppIdleForms)
    float fTimerCheckForIdle; // src: XBOX_RETAIL_PDB +0xc (old: m_fIdleChance)
};
