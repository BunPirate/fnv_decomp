#pragma once

#include "NiRefObject.h"
#include "NiPoint3.h"
#include "NiQuaternion.h"
#include "NiPointer.h"
#include "NiTObjectArray.h"

class bhkRigidBody;
class bhkWorld;
namespace Local { class NiPoint3; }

// pdb: class CellMopp, size 0x18, bases: NiRefObject, 1 members
class CellMopp : public NiRefObject
{
public:
    NiTObjectArray<NiPointer<bhkRigidBody> > spRigidBodyA; // src: XBOX_RETAIL_PDB +0x8 (old: m_kThirdFollowingStreamField)

    virtual ~CellMopp();

    void* __thiscall Destroy(unsigned int flags);
    void Remove();
    void Kill();
    int LookupFirstFormID();
    bool QCreated();
    bool PlaceGridObjects(bhkWorld* p1, const NiPoint3* pPos, int p3);
    void PlaceGridObjects(bhkWorld*, const Local::NiPoint3&, const NiQuaternion&);
};
