#pragma once

#include "NiInterpolator.h"
#include "StrArr.h"

class NiBlendInterpolator__InterpArrayItem;

// pdb: class NiBlendInterpolator, size 0x30, bases: NiInterpolator, 13 members
class NiBlendInterpolator : public NiInterpolator
{
  public:
    class InterpArrayItem;

    NiBlendInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual ~NiBlendInterpolator();

    virtual void LoadBinary(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);

    virtual unsigned char AddInterpolatorItem(NiInterpolator* interpolator, float weight, char priority,
                                              float easeSpinner);
    virtual void RemoveInterpolatorAt(unsigned char ucIndex);
    virtual bool ControlsTransform(NiInterpolator* interpolator);
    virtual bool GrowInterpolatorArray();

    virtual void SaveBinary(NiStream& kStream);
    void CopyMembers(void* pkDest, void* kCloning);
    void AppendInterpolatorStrings(StrArr* pkStrings);
    bool Probe(void* object);
    bool GetUpdateTimeForItem(float& time, unsigned char index);

    virtual bool IsEqual(NiObject* object) const;
    void NormalizeWeights();
    void UpdatePriorityData();
    bool GetBlendUpdateTime(float& time, NiBlendInterpolator__InterpArrayItem& item);
    void GetTimeRange(float* minTime, float* maxTime);

    unsigned char m_uFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    unsigned char unk12[2];
    NiBlendInterpolator__InterpArrayItem* m_pkInterpArray;
    NiInterpolator* m_pkSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fHighEaseSpinner;

    static const float INVALID_TIME;
};
