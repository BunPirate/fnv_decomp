#pragma once

#include "hkxAttributeHolder.h"
#include "hkStringPtr.h"

struct SceneMatrix;
struct SceneAnnotation;

// pdb: class hkxNode, size 0x48, bases: hkxAttributeHolder, 7 members
class hkxNode : public hkxAttributeHolder
{
public:
    hkStringPtr m_name; // src: XBOX_RETAIL_PDB +0x14 (old: name)
    hkReferencedObject* m_object; // src: XBOX_RETAIL_PDB +0x18 (old: object)
    hkArray<SceneMatrix> m_keyFrames; // src: XBOX_RETAIL_PDB +0x1c (old: keyFrames)
    hkArray<hkxNode*> m_children; // src: XBOX_RETAIL_PDB +0x28 (old: children)
    hkArray<SceneAnnotation> m_annotations; // src: XBOX_RETAIL_PDB +0x34 (old: annotations)
    hkStringPtr m_userProperties; // src: XBOX_RETAIL_PDB +0x40 (old: userProperties)
    bool m_selected; // src: XBOX_RETAIL_PDB +0x44 (old: selected)
    bool bone;

    explicit hkxNode(FinishingFlag flag) throw();
    virtual ~hkxNode() throw();
};
