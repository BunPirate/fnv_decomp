#pragma once

#include <xmmintrin.h>
#include "hkpConstraintChainData.h"
#include "hkpBridgeAtoms.h"
#include "hkaAnimation.h"

class hkpPoweredChainDataConstraintInfo;
class hkMemoryRouter;
struct Motor;
struct Body;
class V4;
struct QueryInput;
struct QueryOutput;

// pdb: class hkpPoweredChainData, size 0x40, bases: hkpConstraintChainData, 9 members
class hkpPoweredChainData : public hkpConstraintChainData
{
public:
    struct RuntimeInfo
    {
        int offset;
        int stride;
    };

    hkpPoweredChainData() throw();
    hkpPoweredChainData(FinishingFlag f);
    virtual ~hkpPoweredChainData() throw();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void GetRuntimeInfo(unsigned int wantRuntime, void* runtimeInfo);
    virtual void v0A();
    virtual void AddInstance(hkpConstraintInstance* instance, void* runtime,
                             unsigned int runtimeSize);
    virtual void v0C();
    virtual unsigned char* WantsRuntime(unsigned char* result);
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;
    virtual void vf16();

    int ReturnConstant_102();
    void getRuntimeInfo_00e3b770(int unused, RuntimeInfo* result);
    void buildJacobian_00e3ba40(const QueryInput& inNotValid, QueryOutput& out);
    void getConstraintInfo_00e3b720(int* info) const;

    hkMemoryRouter* hkMemoryRouter_getInstance();
    void addConstraintInfoInBodySpace(const __m128* pivotInA, const __m128* pivotInB,
                    const __m128* aTc, Motor* xMotor, Motor* yMotor,
                    Motor* zMotor);
    void addConstraintInfoInBodySpace(void* pivotInA, void* pivotInB, void* aTc,
                    int xMotor, int yMotor, int zMotor);
    void addConstraintInfoInBodySpace(const V4* pivotInA, const V4* pivotInB, const V4* aTc,
                    Body* xMotor, Body* yMotor, Body* zMotor);

    hkpBridgeAtoms m_atoms; // src: XBOX_RETAIL_PDB +0xc (old: m_kBridgeAtoms)
    hkArray<hkpPoweredChainDataConstraintInfo> m_infos; // src: XBOX_RETAIL_PDB +0x18 (old: m_pConstraintInfo)
    hkReal m_tau; // src: XBOX_RETAIL_PDB +0x24 (old: m_fTau)
    hkReal m_damping; // src: XBOX_RETAIL_PDB +0x28 (old: m_fMotorDamping)
    hkReal m_cfmLinAdd; // src: XBOX_RETAIL_PDB +0x2c (old: m_fMaximumErrorDistance)
    hkReal m_cfmLinMul; // src: XBOX_RETAIL_PDB +0x30 (old: m_fMaximumLinearImpulse)
    hkReal m_cfmAngAdd; // src: XBOX_RETAIL_PDB +0x34 (old: m_fBreachImpulse)
    hkReal m_cfmAngMul; // src: XBOX_RETAIL_PDB +0x38 (old: m_fInertiaStabilizationFactor)
    hkReal m_maxErrorDistance; // src: XBOX_RETAIL_PDB +0x3c (old: m_fMaximumAngularImpulse)
};
