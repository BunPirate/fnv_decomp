#pragma once

#include "TESPackageData.h"

class PackageTargetRecord;
class LocationDescriptor;
class TESObjectWEAP;
class TESForm;

// pdb: class TESUseWeaponPackageData, size 0x24, bases: TESPackageData, 14 members
class TESUseWeaponPackageData : public TESPackageData
{
public:
    struct Parameters
    {
        char m_c00;
        char m_c01;
        char m_c02;
        char m_c03;
        char m_c04;
        char m_c05;
        short m_s06;
        short m_s08;
        short m_s0A;
        float m_f0C;
        float m_f10;
    };

    struct Color
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    struct Info
    {
        unsigned char m_ucType;
        unsigned char m_ucPad;
        unsigned short m_usElementCount;
    };

    struct Range
    {
        unsigned short m_usMin;
        unsigned short m_usMax;
    };

    TESUseWeaponPackageData();
    TESUseWeaponPackageData(Parameters kData, int iParam);
    TESUseWeaponPackageData(Color kColor, Info kInfo, Range kRange,
                            float fStart, float m_fEndValue);

    virtual ~TESUseWeaponPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* apOwner);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    PackageTargetRecord* m_pUseTarget;
    LocationDescriptor* pTargetLocation;
    bool bAlwaysHit;
    bool bDoNoDamage;
    bool bCrouch;
    bool bHoldFire;
    bool bVolleyFire;
    bool bRepeatFire;
    unsigned short sBurstCount;
    unsigned short sVolleyShotsMin;
    unsigned short sVolleyShotsMax;
    float fVolleyWaitMin;
    float fVolleyWaitMax;
    TESObjectWEAP* pWeapon;

    TESUseWeaponPackageData* __thiscall InitializeFields_0067caa0();
    void* DestroyIfFlagged(unsigned int flags);
    void Copy(TESPackageData* apCopy);
    void Copy_0067cd90(TESPackageData* apSource);
    bool Compare_0067cfc0(TESPackageData* apCompare);
    void Save_0067d350();
    void SaveGame_0067d550(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadUseWeaponData(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadForm(BGSLoadFormBuffer* apLoadGameBuffer);

    // Out-of-line accessors (HighProcess::ProcessUseWeapon); names from the UseWeapon package flags.
    PackageTargetRecord* GetTarget();         // 0x00726070: m_pUseTarget (+0x4)
    bool IsCrouch();                          // 0x008f9100: +0xe
    bool IsHoldFireWhenBlocked();             // 0x008f9120: +0xf
    bool IsVolleyFire();                      // 0x00833c20: +0x10
    bool GetRepeatFire();                     // 0x00824060: +0x11
    unsigned short GetBurstCount();           // 0x008f21d0: +0x12
    unsigned short GetVolleyShotsMin();       // 0x008f9140: +0x14
    unsigned short GetVolleyShotsMax();       // 0x008f9160: +0x16
    float GetVolleyWaitMin();                 // 0x004a7bd0: +0x18
    float GetVolleyWaitMax();                 // 0x00495460: +0x1c
};
