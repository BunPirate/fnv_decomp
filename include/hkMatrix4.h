#pragma once

#include "hkVector4.h"

// pdb: class hkMatrix4, size 0x40, 4 members
class hkMatrix4
{
public:
    hkVector4 m_col0;
    hkVector4 m_col1;
    hkVector4 m_col2;
    hkVector4 m_col3;

    __forceinline hkMatrix4()
    {}

    __forceinline void operator=(const hkMatrix4& o)
    {
        m_col0.m_vComponents = o.m_col0.m_vComponents;
        m_col1.m_vComponents = o.m_col1.m_vComponents;
        m_col2.m_vComponents = o.m_col2.m_vComponents;
        m_col3.m_vComponents = o.m_col3.m_vComponents;
    }

    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_col0)[x];
    }

    __forceinline const hkVector4& getColumn(int x) const
    {
        return (&m_col0)[x];
    }

    float& operator()(int r, int c);

    __forceinline const float& operator()(int r, int c) const
    {
        return ((const float*)&getColumn(c).m_vComponents)[r];
    }

    void setIdentity();
    void transformPosition(const hkVector4& positionIn, hkVector4& positionOut) const;
    void transformDirection(const hkVector4& directionIn, hkVector4& directionOut) const;
    void setMulAffine(const hkMatrix4& a, const hkMatrix4& b);

    void hkMatrix4_setMul(const hkMatrix4& a, const hkMatrix4& b);
    void MultiplyInPlace(const hkMatrix4& b);
    void UpdateFields_00de9140(const hkMatrix4& a, const hkMatrix4& b);
    void ProcessAndReturnValue_00de88a0(const hkSimdReal& s, const hkMatrix4& m);
    int UpdateState_00de8910(float epsilon);
};
