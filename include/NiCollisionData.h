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
    NiBoundingVolume* m_pkWorldABV; // src: XBOX_RETAIL_PDB +0x30 (old: unk30)
    void* m_pkOBBRoot; // src: XBOX_RETAIL_PDB +0x34 (old: m_pCollisionObject)
    unsigned int m_pfnCollideCallback; // src: XBOX_RETAIL_PDB +0x38 (old: unk38)
    unsigned int m_pvCollideCallbackData; // src: XBOX_RETAIL_PDB +0x3c (old: unk3C)
    void* m_pkWorldVertex; // src: XBOX_RETAIL_PDB +0x40 (old: m_pWorldVertices)
    void* m_pkWorldNormal; // src: XBOX_RETAIL_PDB +0x44 (old: unk44)
    unsigned char m_bWorldVerticesNeedUpdate; // src: XBOX_RETAIL_PDB +0x48 (old: unk48)
    unsigned char m_bWorldNormalsNeedUpdate; // src: XBOX_RETAIL_PDB +0x49 (old: unk49)
    unsigned short m_usNumVertices; // src: XBOX_RETAIL_PDB +0x4a (old: unk4A)
    unsigned short m_usNumTriangles; // src: XBOX_RETAIL_PDB +0x4c (old: unk4C)
    unsigned char m_bAuxCallbacks; // src: XBOX_RETAIL_PDB +0x4e (old: unk4E)
    unsigned char unk4F;
};
