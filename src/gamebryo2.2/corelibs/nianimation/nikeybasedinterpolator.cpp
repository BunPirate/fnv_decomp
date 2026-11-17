
// NiQuaternion component-wise inequality comparison.
// Returns true when any of the four quaternion components differs.

#include "../../../../include/NiQuaternion.h"

// Returns true if any of the four quaternion components differs from the corresponding component of kOther.
// @fnv 0x0064a290
bool NiQuaternion::operator!=(const NiQuaternion& kOther) const
{
    return m_fW != kOther.m_fW || m_fX != kOther.m_fX || m_fY != kOther.m_fY ||
           m_fZ != kOther.m_fZ;
}
