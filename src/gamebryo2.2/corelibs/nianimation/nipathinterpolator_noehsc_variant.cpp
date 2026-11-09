#include "../../../../include/NiPathInterpolator.h"
#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRefObject.h"

// This flag-variant unit uses /MT /O2 /GS /Gy, without /EHsc.
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<long volatile*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<long volatile*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& ptr)
{
    T* pObject = ptr.m_pObject;
    if (m_pObject != pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

// 0x00a3ce20 is NiFloatData's range-copy operation; the shared header lacks its declaration.
class FloatDataRangeOps : public NiFloatData
{
  public:
    void NiFloatData_GetSequenceData(float fA, float fB, NiPointer<NiFloatData>& spOut);
};

// @fnv 0x00a3e6f0
// pdb: NiPathInterpolator::GetSequenceInterpolator | NiPathInterpolator.obj | retail, object-file gap fill, high
// pdb params: fStartTime, fEndTime
// pdb locals: pkSeqInterp, spNewPctData
NiInterpolator* NiPathInterpolator::CloneForTimeRange(float fStartTime, float fEndTime)
{
    NiPathInterpolator* pkCopy = static_cast<NiPathInterpolator*>(NiInterpolator::CloneForTimeRange(fStartTime, fEndTime));
    if (m_spPctData)
    {
        NiPointer<NiFloatData> spInterp;
        static_cast<FloatDataRangeOps*>(m_spPctData)->NiFloatData_GetSequenceData(fStartTime, fEndTime, spInterp);
        *reinterpret_cast<NiPointer<NiFloatData>*>(&pkCopy->m_spPctData) = spInterp;
        pkCopy->m_uiPercentKeyCount = 0;
    }
    return pkCopy;
}
