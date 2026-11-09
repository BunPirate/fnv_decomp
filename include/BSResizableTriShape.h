#pragma once

#include "NiTriShape.h"
#include "NiBound.h"

// pdb: class BSResizableTriShape, size 0x110, bases: NiTriShape, 2 members
class BSResizableTriShape : public NiTriShape
{
  public:
    virtual ~BSResizableTriShape();
    virtual const NiRTTI* GetRTTI() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void UpdateWorldBound();
    virtual void RenderImmediate(NiRenderer* renderer);
    virtual void RenderWithRenderer(NiRenderer* renderer);
    virtual void SetLocalBound(NiBound bound);
    virtual void* GetBoundingVolume();

    void CopyMemberData(BSResizableTriShape* source, CloningProcess* process);
    void SetNumPrimitives(unsigned int count);
    unsigned int GetNumPrimitives();
    void __local_vftable_ctor_closure();

    static NiObject* CreateObject();

    char unkC4[44];
    unsigned int uiNumPrimitives;
    char LocalBound[16];
    char _pad_104[12];
};
