#pragma once

class Matrix4f;
class RotationMatrix3x3;
class FloatMatrix3;

// SpeedTree RT's 3-component vector (Xbox debug PDB: class CVec3, size 0xc, float m_afData[3]; static m_fTolerance).
// Matrix4f / RotationMatrix3x3 are this tree's names for SpeedTree's CTransform / CRotTransform.
// pdb: class CVec3, size 0xc, 1 members
class CVec3
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float m_afData[3];
    };

    CVec3();
    CVec3(const float* p);
    CVec3(float x, float y = 0.0f, float z = 0.0f);

    void Set(float x, float y, float z);
    void Set(const float& x, const float& y, const float& z);
    float& operator[](int index);
    const float& operator[](int index) const;
    CVec3 operator*(const RotationMatrix3x3& cTransform) const;
    CVec3 TransformPointByMatrix4(const Matrix4f& cTransform);
    CVec3 TransformPointByMatrix4(const Matrix4f& cTransform) const;
    CVec3& Scale(float scale);
    CVec3 AddVector(const CVec3& other) const;
    CVec3 ScaleSwizzled(float scale) const;
    void Normalize_00b12790();
    CVec3 FUN_00b12810(const CVec3& other) const;
    CVec3 FUN_00b12890(const FloatMatrix3& cTransform) const;
    CVec3 Diff_00b13040(const CVec3& other) const;
};
