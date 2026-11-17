#pragma once

#include <stddef.h>
#include "NiObject.h"
#include "NiAVObject.h"
#include "Bound.h"

class BSMultiBoundShape;

// pdb: class BSMultiBound, size 0x10, bases: NiObject, 2 members
class BSMultiBound : public NiObject
{
public:
    BSMultiBound();
    virtual ~BSMultiBound();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    virtual unsigned char QPointWithin(int);
    virtual void v90(void*);

    BSMultiBoundShape* GetShape() const;
    void SetShape(BSMultiBoundShape* shape);
    void CopyMembers_00c35fe0(BSMultiBound*, int);
    void v_8c();
    void BSMultiBound_SetShape(void*);
    void BSMultiBound_SetShape(Bound*);
    bool IsKindOfType(const NiRTTI* type);


    unsigned int uiBoundFrameCount; // src: XBOX_RETAIL_PDB +0x8 (old: m_uiBoundFlags)
    NiPointer<BSMultiBoundShape> spShape; // src: XBOX_RETAIL_PDB +0xc (old: pShape)
};
