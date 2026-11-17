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

    hkArray<hkpPoweredChainMapperLinkInfo> m_links; // src: XBOX_RETAIL_PDB +0x8 (old: m_ppLinks)
    hkArray<hkpPoweredChainMapperTarget> m_targets; // src: XBOX_RETAIL_PDB +0x14 (old: m_kTargets)
    hkArray<hkpConstraintChainInstance*> m_chains; // src: XBOX_RETAIL_PDB +0x20 (old: m_kChainInstances)
};
