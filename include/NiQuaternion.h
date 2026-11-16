#pragma once

class Mat112;
class NiPoint3;
class NiStream;
class NiMatrix3;

// pdb: class NiQuaternion, size 0x10, 4 members
class NiQuaternion
{
public:
    float m_fW; // src: XBOX_RETAIL_PDB +0x0 (old: m_fVectorX)
    float m_fX; // src: XBOX_RETAIL_PDB +0x4 (old: m_fVectorY)
    float m_fY; // src: XBOX_RETAIL_PDB +0x8 (old: m_fVectorZ)
    float m_fZ; // src: XBOX_RETAIL_PDB +0xc (old: m_fScalarPart)

    NiQuaternion();

    NiQuaternion(float w, float x, float y, float z)
        : m_fW(w), m_fX(x), m_fY(y), m_fZ(z)
    {}

    NiQuaternion& operator=(const NiQuaternion& src);

    bool operator!=(const NiQuaternion& other) const;
    NiQuaternion Negate() const;

    NiQuaternion operator+(const NiQuaternion& q) const
    {
        return NiQuaternion(m_fW + q.m_fW, m_fX + q.m_fX,
                            m_fY + q.m_fY, m_fZ + q.m_fZ);
    }

    NiQuaternion operator*(float scalar) const
    {
        return NiQuaternion(m_fW * scalar, m_fX * scalar,
                            m_fY * scalar, m_fZ * scalar);
    }

    NiQuaternion ScaleFourComponents(float scalar) const;
    void FUN_00a38560();
    void NiQuaternion_ToRotation(Mat112* matrix);

    void SetW(float value);
    void SetX(float value);
    void SetY(float value);
    void SetZ(float value);
    float GetW();
    float GetX();
    float GetY();
    float GetZ();
    void SetValues(float w, float x, float y, float z);
    void GetValues(float* w, float* x, float* y, float* z);

    void Sum4(const NiQuaternion& q, float w, float x, float y, float z)
    {
        m_fW = q.m_fW + w;
        m_fX = q.m_fX + x;
        m_fY = q.m_fY + y;
        m_fZ = q.m_fZ + z;
    }

    void MakeUnitLength();
    void Normalize();
    void FastNormalize();
    void Snap();
    void Slerp(float t, const NiQuaternion& p, const NiQuaternion& q);
    void Slerp(float t, NiQuaternion* a, NiQuaternion* b);
    void InterpolateSquad(float t, NiQuaternion* a, NiQuaternion* b, NiQuaternion* c, NiQuaternion* d);
    void GetAngleAxis(float& angle, NiPoint3& axis);
    void GetAngleAxis(float* angle, NiPoint3* axis);
    void FromAngleAxis(float angle, NiPoint3* axis);
    void FromAngleAxisX(float fAngle);
    void FromAngleAxisY(float angle);
    void FromAngleAxisZ(float angle);
    void SetRotationFromEulerXYZ(float x, float y, float z);
    void ToRotationMatrix(NiMatrix3& matrix);
    void ToRotationMatrix(NiMatrix3* matrix);
    void FromRotationMatrix(const NiMatrix3& rot);
    void FromRotationMatrix(NiMatrix3* matrix);
    void LoadBinary(NiStream* stream);
    void SaveBinary(NiStream* stream);
    char* GetViewerString(char* buffer);

    static float Dot(const NiQuaternion& p, const NiQuaternion& q);

    static float Dot(NiQuaternion* p, NiQuaternion* q);
    static NiQuaternion MakeUnitLength(NiQuaternion* quaternion);
    static NiQuaternion Exp(NiQuaternion* quaternion);
    static NiQuaternion Log(NiQuaternion* quaternion);
    static NiQuaternion Intermediate(NiQuaternion* a, NiQuaternion* b, NiQuaternion* c);
    static void LoadBinary(NiStream* stream, NiQuaternion* quaternions, unsigned int count);
    static void SaveBinary(NiStream* stream, NiQuaternion* quaternions, unsigned int count);
    static float ISqrt_approx_in_neighborhood(float value);
    static float Lerp(float a, float b, float t);
    static __declspec(noinline) float CalculateSlerpWeight(float t, float cosine);
    static const NiQuaternion IDENTITY;
};
