// produce (ebp frame in an /O2 unit). Move the functions to their real unit once identified.
#include "../../../../include/BSMultiBound.h"
#include "../../../../include/BSMultiBoundShape.h"
#include "../../../../include/NiStream.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pObject)
{
    T* pOld = m_pObject;
    m_pObject = pObject;
    for (int i = 0; i < 1; ++i)
    {
        if (pObject)
            InterlockedIncrement((volatile long*)&pObject->m_uiRefCount);
        if (pOld && !InterlockedDecrement((volatile long*)&pOld->m_uiRefCount))
            pOld->DeleteThis();
    }
    return *this;
}

// @fnv 0x00c35fe0
// src: XBOX_PDB 0x00c35fe0
// pdb: BSMultiBound::CopyMembers | BSMultiBound.obj | debug, call graph, medium
// pdb params: pDest, arCloneData
// pdb locals: pshape
void BSMultiBound::CopyMembers_00c35fe0(BSMultiBound* pkDest, int kCloning)
{
    CopyMembersStream((unsigned int)pkDest, (void*)kCloning);
    BSMultiBoundShape* pNewInstance = (BSMultiBoundShape*)spShape->MakeClone(*(CloningProcess*)kCloning);
    pkDest->spShape = pNewInstance;
}

// @fnv 0x00c360a0
// pdb: BSMultiBound::RegisterStreamables | BSMultiBound.obj | retail, upstream name already matches, high
// pdb params: arStream
bool BSMultiBound::RegisterStreamables(NiStream& arStream)
{
    if (!NiObject::RegisterStreamables(arStream))
        return false;
    spShape->RegisterStreamables(arStream);
    return true;
}

// @fnv 0x00c36240
// src: XBOX_PDB 0x00c36240
// pdb: BSMultiBound::QPointWithin | BSMultiBound.obj | debug, upstream name already matches, high
// pdb params: aPoint
unsigned char BSMultiBound::QPointWithin(int aPoint)
{
    if (spShape)
        return spShape->BSMultiBoundSphere_QPointWithin((NiPoint3*)aPoint);
    return 0;
}
