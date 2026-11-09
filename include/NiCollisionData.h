#pragma once

#include "NiCollisionObject.h"
#include "NiBoundingVolume.h"
#include "NiPoint3.h"
#include "StrArr.h"

// pdb: class NiCollisionData, size 0x50, bases: NiCollisionObject, 16 members
class NiCollisionData : public NiCollisionObject
{
  public:
    NiCollisionData();
    virtual ~NiCollisionData();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void SetSceneObject(NiAVObject*);
    virtual void Unk_24(NiUpdateData&);
    virtual NiPoint3 GetVelocity();

    void SetModelSpaceABV(NiBoundingVolume* pkBV);
    void CreateTriData(int);
    void CloneCollisionData(NiCollisionData* pkDest, CloningProcess& kCloning);
    void* DestroyIfFlagged(unsigned int);
    void VirtAt64(StrArr*);
    void FUN_00a81100(StrArr*);
    void NiCollisionObject_CopyMembers(NiCollisionData*, CloningProcess&);
    void NiCollisionData_dtor();
    void CreateWorldVertices();
    void UpdateWorldVertices();
    void SetSceneGraphObject(NiAVObject* pkSceneObject);
    void FUN_00ead760(NiStream&);
    void GetViewerStrings_00ead870(StrArr*);

    NiPoint3 m_kLocalVelocity;
    NiPoint3 m_kWorldVelocity;
    int m_ePropagationMode;
    int m_eCollisionMode;
    NiBoundingVolume* m_pkModelABV;
    NiBoundingVolume* m_pkWorldABV;
    void* m_pkOBBRoot;
    unsigned int m_pfnCollideCallback;
    unsigned int m_pvCollideCallbackData;
    void* m_pkWorldVertex;
    void* m_pkWorldNormal;
    unsigned char m_bWorldVerticesNeedUpdate;
    unsigned char m_bWorldNormalsNeedUpdate;
    unsigned short m_usNumVertices;
    unsigned short m_usNumTriangles;
    unsigned char m_bAuxCallbacks;
    unsigned char unk4F;
};
