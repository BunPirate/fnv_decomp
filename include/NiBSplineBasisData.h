#pragma once

#include "NiObject.h"

template <class T, int Degree>
class BSplineBasis
{
  public:
    int m_iNumControlPoints;
    T m_afWeights[Degree + 1];
    T m_fLastTime;
    int m_iMinControlPoint;
    int m_iMaxControlPoint;
};

class NiBSplineBasis_float_3_;

// pdb: class NiBSplineBasisData, size 0x28, bases: NiObject, 1 members
class NiBSplineBasisData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    NiBSplineBasis_float_3_& GetBSplineBasis();

    BSplineBasis<float, 3> m_kBasisDegree3; // src: XBOX_RETAIL_PDB +0x8 (old: m_kBSplineBasis)
};
