#pragma once

#include "hkxAttributeHolder.h"
#include "hkStringPtr.h"

struct SceneMatrix;
struct SceneAnnotation;

// pdb: class hkxNode, size 0x48, bases: hkxAttributeHolder, 7 members
class hkxNode : public hkxAttributeHolder
{
public:
    hkStringPtr m_name;
    hkReferencedObject* m_object;
    hkArray<SceneMatrix> m_keyFrames;
    hkArray<hkxNode*> m_children;
    hkArray<SceneAnnotation> m_annotations;
    hkStringPtr m_userProperties;
    bool m_selected;
    bool bone;

    explicit hkxNode(FinishingFlag flag) throw();
    virtual ~hkxNode() throw();
};
