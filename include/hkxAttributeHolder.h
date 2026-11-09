#pragma once

#include "FinishingFlag.h"
#include "hkReferencedObject.h"

class SceneAttribute;

#include "hkArray.h"

// pdb: class hkxAttributeHolder, size 0x14, bases: hkReferencedObject, 1 members
class hkxAttributeHolder : public hkReferencedObject
{
public:
    hkArray<SceneAttribute> m_attributeGroups;

    explicit hkxAttributeHolder(FinishingFlag flag) throw();
};
