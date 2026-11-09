#pragma once

#include "hkReferencedObject.h"

class hkpVehicleInstance;

// pdb: class hkpVehicleCastBatchingManager, size 0x18, bases: hkpVehicleManager, 1 members
class hkpVehicleCastBatchingManager : public hkReferencedObject
{
public:
    hkpVehicleInstance** m_registeredVehicles;
    int m_registeredVehiclesSize;
    int m_registeredVehiclesCapacityAndFlags;
    unsigned short m_totalNumWheels;
    char pad16[0x2];
};
