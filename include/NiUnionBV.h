#pragma once

#include "NiBoundingVolume.h"
#include "NiTexturingProperty.h"

class NiObject;

// pdb: class NiUnionBV, size 0x18, bases: NiBoundingVolume, 2 members
class NiUnionBV : public NiBoundingVolume
{
public:
    NiTPrimitiveArray<NiBoundingVolume*> m_kBoundingVolume; // src: XBOX_RETAIL_PDB +0x4 (old: m_kBoundingVolumes)
    void* m_uiWhichObjectIntersect; // src: XBOX_RETAIL_PDB +0x14 (old: m_pkEntry)

    NiUnionBV() throw();

    virtual void LoadBinary(NiStream& kStream);
    virtual void __thiscall SaveBinary(NiStream& stream);
    virtual ~NiUnionBV();
    virtual int F3() const;
    virtual void v10();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
    virtual NiBoundingVolume* Clone();
    virtual void Copy(const NiBoundingVolume& kABV);
    virtual int IsEqual(const NiBoundingVolume& kABV) const;
    virtual bool IsDifferent(NiBoundingVolume* pkOther);
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);

    NiUnionBV* NiUnionBV_NiUnionBV(void* pkOtherRaw);
    void NiUnionBV_RemoveAllBoundingVolumes();
    void AddViewerStrings_00e9f0b0(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);
};
