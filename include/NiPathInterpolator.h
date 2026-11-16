#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiQuaternion.h"
#include "NiPoint3.h"

class NiPosData;
class NiFloatData;
class PositionKeyInterpolator;
class NiMatrix3;
class StrArr;

// pdb: class NiPathInterpolator, size 0x5c, bases: NiKeyBasedInterpolator, 15 members
class NiPathInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiPathInterpolator(NiPosData* pkPathData = 0, NiFloatData* pkPctData = 0);
    virtual ~NiPathInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual bool UpdateTransform(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float fStartTime, float fEndTime);
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    void GuaranteeTimeRange_00a3dc50(float m_fStartTime, float m_fMaximumDistance);
    void* GetKeyCount(short usChannel);
    int GetValueByIndex(short arg);
    int GetKeyArray(short usChannel);
    char GetKeyStride(unsigned short usChannel);
    int GetChannelIndex(unsigned short usChannel);
    void* GenPathInterp(void* pData, int i1, int i2, float fTime);
    NiPoint3 GenPathInterp(int i1, int i2, float fTime);
    void ProcessClone_00a3dc80(CloningProcess& kCloning);
    bool RegisterStreamables_00a3dcc0(void* pkStream);
    void GetRange(float* pfMin, float* pfMax);
    void ReadFromStream(NiStream* source);
    void WriteToStream(NiStream* pStream);
    void AppendString(StrArr* pkStrings);
    void CopyMemberData(NiPathInterpolator* pDest, CloningProcess& kCloning);
    void CopyMembers_00a3f2f0(NiPathInterpolator* pDest, CloningProcess& kCloning);
    void LinkObject_00a3ee80(NiStream& stream);
    bool IsEqual_00a3e7b0(NiObject* pkObject);
    bool BaseIsEqual(NiObject* pkObject);
    bool PartialLengthsEqual(NiPathInterpolator* pkPath);
    int GetPathKeys(int& uiNumKeys, int& eType, char& ucSize);
    PositionKeyInterpolator* GetPathKeys(unsigned int& count, unsigned int& type,
        unsigned char& stride) const;
    float CalcTotalLength();
    float GetAccumulatedValue();
    float NiPathInterpolator_PathLength(int iI0, int iI1, float fTime);
    float PathSpeed(int iI0, int iI1, float fTime);
    void GetPercentLoc(float fPercent, unsigned int& uiI1, unsigned int& uiI2, float& fNormTime);
    void FindKeyPair(float fTime, unsigned int& i1, unsigned int& i2, float& fNormTime);
    void FindKeyPair(float fTime, int& i1, int& i2, float& fNormTime);
    void CalcRefFrame(int ui1, int ui2, float fNormTime, NiMatrix3& kRefFrame);
    void CalcRefFrame(unsigned int ui1, unsigned int ui2, float fNormTime,
        NiMatrix3* kRefFrame);
    void SetBit(bool bVal, unsigned short uMask);
    bool GetBit(unsigned short uMask) const;
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const;
    void SetConstVelocity(bool b);
    bool GetConstVelocity() const;
    bool GetCVDataNeedsUpdate() const;
    void SetCVDataNeedsUpdate(bool value);
    bool GetFollow() const;
    bool TimeHasChanged(float fTime) const;

    unsigned short m_uFlags; // src: XBOX_RETAIL_PDB +0xc (old: m_uiObjectFlags)
    unsigned short unk0E;
    union
    {
        unsigned int m_uiPathKeyCount;
        int unk10;
    };
    union
    {
        unsigned int m_uiPercentKeyCount;
        int unk14;
    };
    NiPosData* m_spPathData; // src: XBOX_RETAIL_PDB +0x18 (old: m_pPathObject)
    void* m_spPctData; // src: XBOX_RETAIL_PDB +0x1c (old: m_pPathInterp)
    float* m_pfPartialLength; // src: XBOX_RETAIL_PDB +0x20 (old: m_pfPathLengths)
    float m_fTotalLength; // src: XBOX_RETAIL_PDB +0x24 (old: m_fTotalPathLength)
    float m_fMaxBankAngle; // src: XBOX_RETAIL_PDB +0x28 (old: m_fPreviousTime)
    float m_fSmoothing; // src: XBOX_RETAIL_PDB +0x2c (old: m_fLastPercent)
    short m_sFollowAxis; // src: XBOX_RETAIL_PDB +0x30 (old: m_sLastPathIndex)
    short unk32;
    union
    {
        float m_fPathLength;
        int unk34;
    };
    int m_eBankDir; // src: XBOX_RETAIL_PDB +0x38 (old: m_iPathPointCount)
    NiQuaternion m_kRotation; // src: XBOX_RETAIL_PDB +0x3c (old: m_kRotationMatrix)
    NiPoint3 m_kPosition; // src: XBOX_RETAIL_PDB +0x4c (old: m_kPathOffset)
    union
    {
        float m_fLast;
        float m_fZValue;
    };
};
