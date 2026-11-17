// speedtree/libvector_source/idvvector.h: declares RotationMatrix3x3
#ifndef FNV_IDVVECTOR_H
#define FNV_IDVVECTOR_H

#include "../../../include/CVec3.h"

class RotationMatrix3x3
{
  public:
    float m_fComponents[3][3];
};
__forceinline CVec3::CVec3(float a, float b, float c) : x(a), y(b), z(c)
{}
// @fnv 0x00b12890
// pdb: CVec3::operator* | FrondEngine.obj | debug, call graph, high
// pdb params: cTransform
CVec3 CVec3::operator*(const RotationMatrix3x3& cTransform) const
{
    float result[3];
    result[0] =
        cTransform.m_fComponents[2][0] * z + (cTransform.m_fComponents[1][0] * y + cTransform.m_fComponents[0][0] * x);
    result[1] =
        cTransform.m_fComponents[2][1] * z + (cTransform.m_fComponents[1][1] * y + cTransform.m_fComponents[0][1] * x);
    result[2] =
        cTransform.m_fComponents[2][2] * z + (cTransform.m_fComponents[1][2] * y + cTransform.m_fComponents[0][2] * x);
    return CVec3(result[0], result[1], result[2]);
}
#endif
