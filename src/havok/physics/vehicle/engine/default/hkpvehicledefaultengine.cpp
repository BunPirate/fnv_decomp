
// src/havok/physics/vehicle/engine/default/hkpvehicledefaultengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/engine/default/hkpvehicledefaultengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultEngine.h"

struct DriverInput
{
    hkReal m_fPrimaryValue;
};

struct RealValue
{
    hkReal m_fValue;
};

struct RealPair
{
    hkReal m_fFirstValueBeforeSteeringAngle;
    hkReal m_fSecondValueBeforeSteeringAngle;
};

class EngineHelper : public hkpVehicleDefaultEngine
{
  public:
    void CalculateEngineTorque(const hkReal deltaTime, const void* vehicle,
                               const DriverInput& filteredDriverInputOutput, const RealValue& transmissionOutput,
                               RealPair& engineOutput);
};

// Computes net engine torque from RPM, accelerator input, and transmission output, storing results in engineOutput.
// @fnv 0x00e440a0
// pdb: hkpVehicleDefaultEngine::calcEngineInfo | hkpVehicleDefaultEngine.obj | debug, vtable slot, medium
// pdb params: deltaTime, vehicle, filteredDriverInputInfo, transmissionInfo, engineOutput
// pdb locals: assertBuf, ostr
void EngineHelper::CalculateEngineTorque(const hkReal deltaTime, const void* vehicle,
                                         const DriverInput& filteredDriverInputOutput,
                                         const RealValue& transmissionOutput, RealPair& engineOutput)
{
    engineOutput.m_fSecondValueBeforeSteeringAngle = transmissionOutput.m_fValue;
    const hkReal acceleratorPedal = filteredDriverInputOutput.m_fPrimaryValue;

    if (engineOutput.m_fSecondValueBeforeSteeringAngle < m_minRPM)
    {
        const hkReal clutchSlip = m_clutchSlipRPM * acceleratorPedal;
        const hkReal halfMinRPM = m_minRPM * 0.5;
        if (engineOutput.m_fSecondValueBeforeSteeringAngle < halfMinRPM)
        {
            engineOutput.m_fSecondValueBeforeSteeringAngle = clutchSlip + m_minRPM;
        }
        else
        {
            engineOutput.m_fSecondValueBeforeSteeringAngle =
                m_minRPM +
                ((engineOutput.m_fSecondValueBeforeSteeringAngle - halfMinRPM) * clutchSlip) / (m_minRPM - halfMinRPM);
        }
    }

    hkReal grossTorque;
    hkReal resistanceTorque;

    const hkReal dRPM = engineOutput.m_fSecondValueBeforeSteeringAngle - m_optRPM;
    if (dRPM < 0.0f)
    {
        const hkReal invDenom = 1.0f / (m_minRPM - m_optRPM);
        const hkReal resFactor = (m_resistanceFactorAtMinRPM - m_resistanceFactorAtOptRPM) * invDenom;
        resistanceTorque = (m_resistanceFactorAtOptRPM + dRPM * resFactor) * m_maxTorque;

        const hkReal tqFactor = ((m_torqueFactorAtMinRPM - 1.0f) * invDenom) * invDenom;
        grossTorque = (1.0f + tqFactor * (dRPM * dRPM)) * m_maxTorque;

        const hkReal transRPM = transmissionOutput.m_fValue;
        if (transRPM < m_minRPM)
        {
            resistanceTorque *= transRPM / m_minRPM;
        }
    }
    else if (engineOutput.m_fSecondValueBeforeSteeringAngle < m_maxRPM)
    {
        const hkReal invDenom = 1.0f / (m_maxRPM - m_optRPM);
        const hkReal resFactor = (m_resistanceFactorAtMaxRPM - m_resistanceFactorAtOptRPM) * invDenom;
        resistanceTorque = (m_resistanceFactorAtOptRPM + dRPM * resFactor) * m_maxTorque;

        const hkReal tqFactor = ((m_torqueFactorAtMaxRPM - 1.0f) * invDenom) * invDenom;
        grossTorque = (1.0f + tqFactor * (dRPM * dRPM)) * m_maxTorque;
    }
    else
    {
        engineOutput.m_fSecondValueBeforeSteeringAngle = m_maxRPM;
        grossTorque = 0.0f;
        resistanceTorque = m_resistanceFactorAtMaxRPM * m_maxTorque;
    }

    engineOutput.m_fFirstValueBeforeSteeringAngle = acceleratorPedal * grossTorque - resistanceTorque;
}
