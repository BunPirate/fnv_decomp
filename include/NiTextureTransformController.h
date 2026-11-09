#pragma once

#include "NiFloatInterpController.h"

class NiTexturingProperty__Map;

enum NiTextureTransformController__TransformMember
{
    NiTextureTransformController__TransformMember_TT_TRANSLATE_U = 0,
    NiTextureTransformController__TransformMember_TT_TRANSLATE_V = 1,
    NiTextureTransformController__TransformMember_TT_ROTATE = 2,
    NiTextureTransformController__TransformMember_TT_SCALE_U = 3,
    NiTextureTransformController__TransformMember_TT_SCALE_V = 4
};

// pdb: class NiTextureTransformController, size 0x50, bases: NiFloatInterpController, 6 members
class NiTextureTransformController : public NiFloatInterpController
{
public:
    unsigned int m_uiLastIdx;
    NiTexturingProperty__Map* m_pkMap;
    bool m_bShaderMap;
    unsigned char layoutPadding41[3];
    unsigned int m_uiMapIndex;
    NiTextureTransformController__TransformMember m_eMember;
    mutable char* m_pcCtlrID;

    virtual const char* GetControllerID() const;
    virtual void Update(NiUpdateData& UpdateData);
    bool IsTextureMapValid();
    NiTextureTransformController(NiObjectNET* pkTarget, NiTexturingProperty__Map* pkMap,
                                 NiTextureTransformController__TransformMember eMember) throw();
};

