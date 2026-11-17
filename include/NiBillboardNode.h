#pragma once

#include "NiNode.h"
#include "StrArr.h"

struct BoardObject;
struct BoardVector;
struct BillboardClone;

// pdb: class NiBillboardNode, size 0xe0 (here 0xb4), bases: NiNode, 2 members
class NiBillboardNode : public NiNode
{
  public:
    NiBillboardNode();
    virtual ~NiBillboardNode();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void UpdateDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& UpdateData, unsigned int uFlags);
    virtual void UpdateWorldBound();
    virtual void OnVisible(NiCullingProcess& culler);

    using NiNode::MakeClone;
    using NiNode::IsEqual;
    using NiNode::UpdateDownwardPass;

    void ForwardCall_0051cfe0();
    void* Destroy(unsigned int flags);
    void NiAVObject_SetSelectiveUpdate(bool value);
    void SetMode_0051d000(int flags);
    void NiBillboardNode_SetUpdateControllers(int flags);

    void UpdateSelectedDownwardPass_00a7da80(NiUpdateData& UpdateData, unsigned int uFlags);
    void UpdateRigidDownwardPass_00a7dab0(NiUpdateData& UpdateData, unsigned int uFlags);
    void UpdateDownwardPass_00a7dae0(NiUpdateData& UpdateData, unsigned int uFlags);
    unsigned char IsEqual_00a7db30(NiObject* pkObject);
    __declspec(noalias) bool NiBillboardNode_RotateToCenter(const BoardObject* camera, const BoardVector& kWorldTranslate,
                                        BoardVector& kCamD, BoardVector& kCamU, BoardVector& kCamR);
    void RotateToCamera(const BoardObject* pkCamera);
    void RotateToCamera(NiCullingProcess* pkCamera);
    void OnVisible_00a7e610(NiCullingProcess* kCuller);
    void UpdateWorldBound_00a7e630();
    BillboardClone* CreateClone_00a7e710(void* kCloning);
    void LoadBinary_00a7e7b0(NiStream& kStream);
    void SaveBinary_00a7e850(NiStream& kStream);
    void GetViewerStrings_00a7e890(StrArr* pkStrings);

    static const NiRTTI ms_kRTTI;

    unsigned int unkAC;
    unsigned int unkB0;
};
