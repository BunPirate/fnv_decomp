#pragma once

#include "NiPoint3.h"
#include "NiQuaternion.h"

class NiStream;

// pdb: class NiQuatTransform, size 0x20, 3 members
class NiQuatTransform
{
public:
    float m_kTranslate; // src: XBOX_RETAIL_PDB +0x0 (old: x)
    float y;
    float z;
    float m_kRotate; // src: XBOX_RETAIL_PDB +0xc (old: qx)
    float qy;
    float qz;
    float qw;
    float m_fScale; // src: XBOX_RETAIL_PDB +0x1c (old: scale)

    NiQuatTransform();
    NiQuatTransform& operator=(const NiQuatTransform& rhs);

    const NiPoint3& GetTranslate();
    void GetTransformScale(void* kTranslate);
    void* GetRotate();
    void SetLocalRotation(void* value);
    float GetScale();
    void SetScale(float value);
    const NiQuaternion& GetOffsetC();
    float GetFloatAtOffset1C();

    bool IsInvalid() const;
    bool IsTranslateValid();
    bool IsRotateValid();
    bool IsScaleValid();
    bool IsMarkedInvalid();
    bool IsMarkedInvalid() const;
    bool IsTranslateXNotNegatedConstant();
    void SetTranslateValid(bool valid);
    void SetRotateValid(bool bValid);
    void SetScaleValid(bool valid);
    void MakeInvalid();

    void Invert(NiQuatTransform* result);
    void TransformBy(NiQuatTransform* result);
    void TransformBy(NiQuatTransform& result);
    NiQuatTransform CombineTransforms(void* kTransform);
    NiQuatTransform CombineTransforms(const NiQuatTransform& kTransform);

    void LoadBinary(NiStream* stream);
    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream* stream);
    void GetViewerStrings(void* strings);
};
