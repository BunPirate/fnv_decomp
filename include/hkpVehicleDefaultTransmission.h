#pragma once

#include "hkpVehicleTransmission.h"
#include "hkaAnimation.h"

struct Vehicle;

// pdb: class hkpVehicleDefaultTransmission, size 0x34, bases: hkpVehicleTransmission, 7 members
class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
public:
    float calcTransmissionRPM(const Vehicle* vehicle, const void* transmissionOut);
    virtual void vf03();
    virtual void vf04();
    virtual float vf05(const Vehicle* vehicle, const void* input);
    virtual void vf06();
    virtual void vf07();
    virtual hkReal getTransmissionRatio(const Vehicle* vehicle, const void* input) const;

    hkReal m_downshiftRPM; // src: XBOX_RETAIL_PDB +0x8 (old: m_fDownshiftRPM)
    hkReal m_upshiftRPM; // src: XBOX_RETAIL_PDB +0xc (old: m_fUpshiftRPM)
    hkReal m_primaryTransmissionRatio; // src: XBOX_RETAIL_PDB +0x10 (old: m_fPrimaryTransmissionRatio)
    hkReal m_clutchDelayTime; // src: XBOX_RETAIL_PDB +0x14 (old: m_fClutchDelayTime)
    hkReal m_reverseGearRatio; // src: XBOX_RETAIL_PDB +0x18 (old: m_fReverseGearRatio)
    hkArray<hkReal> m_gearsRatio; // src: XBOX_RETAIL_PDB +0x1c (old: m_kGearRatios)
    hkArray<hkReal> m_wheelsTorqueRatio; // src: XBOX_RETAIL_PDB +0x28 (old: m_kWheelTorqueRatios)
};
