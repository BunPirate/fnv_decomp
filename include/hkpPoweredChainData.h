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
    hkpPoweredChainData(FinishingFlag flag);
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
    void addConstraintInfoInBodySpace(void* frameA, void* frameB, void* frameC,
                    int motorA, int motorB, int motorC);
    void addConstraintInfoInBodySpace(const V4* frameA, const V4* frameB, const V4* frameC,
                    Body* motorA, Body* motorB, Body* motorC);

    hkpBridgeAtoms m_atoms;
    hkArray<hkpPoweredChainDataConstraintInfo> m_infos;
    hkReal m_tau;
    hkReal m_damping;
    hkReal m_cfmLinAdd;
    hkReal m_cfmLinMul;
    hkReal m_cfmAngAdd;
    hkReal m_cfmAngMul;
    hkReal m_maxErrorDistance;
};
