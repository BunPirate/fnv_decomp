
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/BSMultiBound.h"
#include "../../../../include/GO.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"

// The shared header lacks declarations for these entry points. Keep their
// thiscall implementations here, inheriting all layout from the checked class.
class BSMultiBoundStreamOperations : public BSMultiBound
{
public:
    void LoadBinary(NiStream* arStream);
    void LinkObject(NiStream& arStream);
    void RegisterShape(NiStream& arStream);
    bool IsSameBound(BSMultiBound* apObject);
    void* Delete(unsigned int flags);
    const NiRTTI* GetRTTI() const;
    BSMultiBound* CloneBound(int arCloneData);
    void CopyBound(BSMultiBound* target, int context);
    void* GetViewerEntries(int argument);
    void* AppendCameraPathEntries(int pStrings);
};

// @fnv 0x00c36040
// pdb: BSMultiBound::LoadBinary | BSMultiBound.obj | retail, vtable slot, high
// pdb params: arStream
void BSMultiBoundStreamOperations::LoadBinary(NiStream* arStream)
{
    NiObject::LoadBinary(*arStream);
    arStream->ResetStreamState();
}

// @fnv 0x00c36070
// pdb: BSMultiBound::LinkObject | BSMultiBound.obj | retail, vtable slot, high
// pdb params: arStream
void BSMultiBoundStreamOperations::LinkObject(NiStream& arStream)
{
    int _u1;
    int _u2;
    NiObject::LinkObject(arStream);
    reinterpret_cast<GO&>(spShape) = arStream.GetLoadedObject();
}

// @fnv 0x00c36220
// pdb: BSMultiBound::GetViewerStrings | BSMultiBound.obj | debug, vtable slot, medium
// pdb params: apStrings
void* BSMultiBoundStreamOperations::GetViewerEntries(int arg)
{
    return AppendCameraPathEntries(arg);
}

void _delete(void*, unsigned int);
// @fnv 0x00c36290
// pdb: BSMultiBound::`scalar deleting destructor' | BSMultiBound.obj | retail, vtable slot, high
void* BSMultiBoundStreamOperations::Delete(unsigned int flags)
{
    BSMultiBound::~BSMultiBound();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct S_00c362c0
{
    NiObject* ptr;
    void UpdateFields_00c362c0();
};
// @fnv 0x00c362c0
// src: GUESS 0x00c362c0 (confidence: low)
// pdb: NiPointer<BSMultiBoundShape>::NiPointer<BSMultiBoundShape> | BSMultiBound.obj | debug, object-file run extension, low
// pdb params: pObject
void S_00c362c0::UpdateFields_00c362c0()
{
    NiObject* p;
    if (ptr)
    {
        p = ptr;
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
}

extern "C" void* g_01202810;

// @fnv 0x00c36300
const NiRTTI* BSMultiBoundStreamOperations::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_01202810);
}

// @fnv 0x00c35f50
// pdb: BSMultiBound::CreateClone | BSMultiBound.obj | retail, vtable slot, high
// pdb params: arCloneData
// pdb locals: pobj
BSMultiBound* BSMultiBoundStreamOperations::CloneBound(int arCloneData)
{
    BSMultiBound* t = new BSMultiBound;
    CopyBound(t, arCloneData);
    return t;
}

extern int _data_011c16bc;

// @fnv 0x00c361a0
// src: EXE 0x00c361a0
// pdb: BSMultiBound::CreateObject | BSMultiBound.obj | retail, upstream name already matches, high
BSMultiBound* BSMultiBound_CreateObject()
{
    return new BSMultiBound;
}

// @fnv 0x00c36130
// pdb: BSMultiBound::IsEqual | BSMultiBound.obj | retail, vtable slot, high
// pdb params: apObject
// pdb locals: bres, pkDest
bool BSMultiBoundStreamOperations::IsSameBound(BSMultiBound* apObject)
{
    bool result = IsSameAs(apObject);
    BSMultiBound* other = apObject;
    {
        int a;
        int b;
        if ((bool)(int)(spShape.m_pObject == other->spShape.m_pObject) &&
            ((a = uiBoundFrameCount) == (b = other->uiBoundFrameCount)))
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

// @fnv 0x00c360f0
// pdb: BSMultiBound::SaveBinary | BSMultiBound.obj | retail, vtable slot, high
// pdb params: arStream
void BSMultiBoundStreamOperations::RegisterShape(NiStream& arStream)
{
    NiObject::LinkObject(arStream);
    const void* object = spShape.m_pObject;
    arStream.SaveLinkID(reinterpret_cast<const NiObject*>(object));
}
