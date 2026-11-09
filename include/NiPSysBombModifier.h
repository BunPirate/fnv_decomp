#pragma once

#include "NiPSysModifier.h"
#include "NiPoint3.h"

struct StrArr;

// pdb: class NiPSysBombModifier, size 0x38, bases: NiPSysModifier, 6 members
class NiPSysBombModifier : public NiPSysModifier
{
public:
    NiPSysBombModifier();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& kStream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void Update(float time, NiPSysData* data);

    void ProcessClone_00c2e610(CloningProcess& process);
    bool IsEqual_00c2eaf0(NiObject* object);
    void Update_00c2e670(float time, NiPSysData* data);
    bool FUN_00c31830(NiObject* object);
    void FUN_00c319e0(StrArr* strings);
    void AppendToStrings(StrArr* strings);
    NiObject* Bomb();

    static const char* GetDecayTypeName(int type);
    static const char* GetSymmTypeName(int type);

    NiObject* m_pkBombObj;
    NiPoint3 m_kBombAxis;
    float m_fDecay;
    float m_fDeltaV;
    int m_eDecayType;
    int m_eSymmType;
};
