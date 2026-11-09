#pragma once

#include <xmmintrin.h>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpConstraintChainInstance;
class hkpConstraintMotor;
class hkpPoweredChainMapperLinkInfo;
class hkpPoweredChainMapperTarget;

// pdb: class hkpPoweredChainMapper, size 0x2c, bases: hkReferencedObject, 3 members
class hkpPoweredChainMapper : public hkReferencedObject
{
public:
    virtual ~hkpPoweredChainMapper() throw();

    void setMotors(int linkIndex, int coordinateIndex, hkpConstraintMotor* newMotor);
    void CollectSlotValues(int range, int slot, hkArray<int>& out);
    void SetLinkVector(int chainIndex, const __m128& vec);

    hkArray<hkpPoweredChainMapperLinkInfo> m_links;
    hkArray<hkpPoweredChainMapperTarget> m_targets;
    hkArray<hkpConstraintChainInstance*> m_chains;
};
