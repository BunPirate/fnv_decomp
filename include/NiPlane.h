#pragma once

#include "NiPoint3.h"

class FNVVec3;
class NiStream;
class NiMatrix3;

// pdb: class NiPlane, size 0x10, 2 members
class NiPlane
{
public:
    float m_kNormal; // src: XBOX_RETAIL_PDB +0x0 (old: x)
    float y;
    float z;
    float m_fConstant; // src: XBOX_RETAIL_PDB +0xc (old: c)

    NiPlane();
    NiPlane(const NiPoint3& normal, float constant);
    NiPlane(const NiPoint3& normal, const NiPoint3& point);

    bool operator==(const NiPlane& other);
    bool operator==(const NiPlane& other) const;
    bool operator==(const NiPoint3& point);

    bool FUN_00439090(const NiPlane* other);
    bool HasEqualComponents(const NiPlane& other);
    bool HasEqualComponents(const NiPoint3& point);

    void Apply(const NiMatrix3& matrix, const NiPoint3& translation);
    int Side(const FNVVec3& point) const;
    float Distance(const FNVVec3& point) const;
    float Distance(const NiPoint3& kPoint) const;
    const NiPoint3& GetPlaneNormal() const;
    float GetPlaneConstant() const;
    float FUN_0084d030() const;
    void LoadBinary(NiStream& kStream);
};
