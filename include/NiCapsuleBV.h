#pragma once

#include "NiBoundingVolume.h"
#include "NiPoint3.h"

class NiTransform;

// pdb: class NiCapsuleBV, size 0x3c, bases: NiBoundingVolume, 4 members
class NiCapsuleBV : public NiBoundingVolume
{
public:
    virtual NiBoundingVolume* Clone();

    void UpdateSegment();
    void TransformToWorld(const NiCapsuleBV& kModel, const NiTransform& kWorld);
    void Copy(const NiBoundingVolume& kABV);
    int IsEqual(const NiBoundingVolume& kABV) const;
    NiCapsuleBV* CopyConstruct(const NiCapsuleBV& source);

    NiPoint3 m_kCenter;
    NiPoint3 m_kAxis;
    float m_fExtent;
    union
    {
        char _pad[0x18];
        struct
        {
            NiPoint3 m_kSegOrigin;
            NiPoint3 m_kSegDir;
        };
    };
    float m_fBoundRadius;
};
