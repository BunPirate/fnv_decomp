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

    unsigned char cIdleFlags;
    unsigned char cIdleCount;
    unsigned char layoutPadding6[2];
    TESIdleForm** pIdleArray;
    float fTimerCheckForIdle;
};
