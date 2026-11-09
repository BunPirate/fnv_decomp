
// src/havok/physics/dynamics/constraint/hkpconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/hkpconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpAngConstraintAtom.h"
#include "../../../../../include/hkpAngFrictionConstraintAtom.h"
#include "../../../../../include/hkpConstraintAtom.h"
#include "../../../../../include/hkpSimpleContactConstraintAtom.h"

extern "C" void __cdecl hkString_memSet(void* dst, int n, int len);

struct FUN_00d21a30_class
{
    void __thiscall hkpConstraintData_addInstance(int a, int b, int c);
};

// @fnv 0x00d21a30
// src: HAVOK_LIB 0x00d21a30
void __thiscall FUN_00d21a30_class::hkpConstraintData_addInstance(int a, int pBuffer, int uiLength)
{
    if (pBuffer)
        hkString_memSet((void*)pBuffer, 0, uiLength);
}

// @fnv 0x00d21a50
// src: GUESS 0x00d21a50 (confidence: low)
int __stdcall hkpConstraintData_GetA(int a)
{
    return a;
}

extern "C" void _ReadWriteBarrier(void);
struct GenericConstraintAtomScheme
{
    int maxSizeOfSchema, sizeOfSchemas, numSolverResults, numSolverElemTemps;
    const hkpConstraintAtom* atoms;
    int sizeOfAllAtoms;
};
inline void addSolverSchema(GenericConstraintAtomScheme* info, int schema, int results, int temps)
{
    info->sizeOfSchemas += schema;
    info->numSolverResults += results;
    info->numSolverElemTemps += temps;
    _ReadWriteBarrier();
}
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
inline void addAngularFriction(GenericConstraintAtomScheme* out, int schema, int rows, int temps)
{
    out->sizeOfSchemas += schema;
    out->numSolverResults += rows;
    out->numSolverElemTemps += temps;
}
// Fills a GenericConstraintAtomScheme with solver schema sizes, result counts, and temps by walking the hkpConstraintAtom array.
// @fnv 0x00d21a60
// src: HAVOK_LIB 0x00d21a60
// pdb: hkpConstraintData::getConstraintInfoUtil | hkpConstraintData.obj | debug, upstream name already matches, high
// pdb params: atoms, sizeOfAllAtoms, infoOut
// pdb locals: assertBuf, ostr
void __cdecl hkpConstraintData_getConstraintInfoUtil(const hkpConstraintAtom* atoms, int sizeOfAllAtoms, GenericConstraintAtomScheme* infoOut)
{
    infoOut->atoms = atoms;
    infoOut->sizeOfAllAtoms = sizeOfAllAtoms;
    infoOut->maxSizeOfSchema = 0;
    infoOut->sizeOfSchemas = 0;
    infoOut->numSolverResults = 0;
    infoOut->numSolverElemTemps = 0;
    if (atoms->m_type == hkpConstraintAtom::CONTACT)
    {
        int iContactPoints = reinterpret_cast<const hkpSimpleContactConstraintAtom*>(atoms)->m_numContactPoints;
        int schema = 128 + 112 * (iContactPoints >> 1) + 48 * (iContactPoints & 1);
        infoOut->sizeOfSchemas = schema;
        infoOut->maxSizeOfSchema = schema + 32;
        infoOut->numSolverResults = iContactPoints + 2;
        infoOut->numSolverElemTemps = iContactPoints + 3;
        if (iContactPoints >= 2)
        {
            ++infoOut->numSolverResults;
            ++infoOut->numSolverElemTemps;
            infoOut->sizeOfSchemas = schema + 32;
        }
        return;
    }
    const char* cursor = reinterpret_cast<const char*>(atoms);
    infoOut->sizeOfSchemas = 16;
    const char* end = cursor + sizeOfAllAtoms;
    while (cursor < end)
    {
        int tempsDelta;

    dispatchAlignedAtom:
        const hkpConstraintAtom* atom = reinterpret_cast<const hkpConstraintAtom*>(cursor);
        switch (atom->m_type)
        {
        case hkpConstraintAtom::INVALID:
            cursor = reinterpret_cast<const char*>((reinterpret_cast<unsigned long>(cursor) + 15) & ~15UL);
            goto dispatchAlignedAtom;
        case hkpConstraintAtom::BALL_SOCKET:
            addSolverSchema(infoOut, 144, 3, 3);
            cursor += 8;
            break;
        case hkpConstraintAtom::STIFF_SPRING:
            addSolverSchema(infoOut, 48, 1, 1);
            cursor += 8;
            break;
        case hkpConstraintAtom::LIN:
            addSolverSchema(infoOut, 48, 1, 1);
            cursor += 4;
            break;
        case hkpConstraintAtom::LIN_SOFT:
        case hkpConstraintAtom::LIN_LIMIT:
            addSolverSchema(infoOut, 64, 1, 1);
            cursor += 12;
            break;
        case hkpConstraintAtom::LIN_FRICTION:
            addSolverSchema(infoOut, 64, 1, 2);
            cursor += 8;
            break;
        case hkpConstraintAtom::LIN_MOTOR:
            infoOut->sizeOfSchemas += 80;
            infoOut->numSolverResults += 1;
            tempsDelta = 3;
            goto sharedContribution;
        case hkpConstraintAtom::ANG_2D:
            addSolverSchema(infoOut, 96, 2, 2);
            cursor += 4;
            break;
        case hkpConstraintAtom::ANG: {
            addSolverSchema(infoOut, 48 * static_cast<const hkpAngConstraintAtom*>(atom)->m_numConstrainedAxes,
                            static_cast<const hkpAngConstraintAtom*>(atom)->m_numConstrainedAxes,
                            static_cast<const hkpAngConstraintAtom*>(atom)->m_numConstrainedAxes);
            cursor += 4;
            break;
        }
        case hkpConstraintAtom::ANG_LIMIT:
            addSolverSchema(infoOut, 48, 1, 1);
            cursor += 16;
            break;
        case hkpConstraintAtom::TWIST_LIMIT:
        case hkpConstraintAtom::CONE_LIMIT:
            addSolverSchema(infoOut, 48, 1, 1);
            cursor += 20;
            break;
        case hkpConstraintAtom::ANG_FRICTION: {
            int axes = static_cast<const hkpAngFrictionConstraintAtom*>(atom)->m_numFrictionAxes;
            int temps = 2 * static_cast<const hkpAngFrictionConstraintAtom*>(atom)->m_numFrictionAxes;
            addAngularFriction(infoOut, 48 * axes, axes, temps);
            cursor += 12;
            break;
        }
        case hkpConstraintAtom::ANG_MOTOR:
            addSolverSchema(infoOut, 64, 1, 3);
            cursor += 20;
            break;
        case hkpConstraintAtom::RAGDOLL_MOTOR:
            infoOut->sizeOfSchemas += 192;
            infoOut->numSolverResults += 3;
            tempsDelta = 9;
            goto sharedContribution;
        case hkpConstraintAtom::PULLEY:
            addSolverSchema(infoOut, 64, 1, 1);
            cursor += 64;
            break;
        case hkpConstraintAtom::SET_LOCAL_TRANSFORMS:
            cursor += 144;
            break;
        case hkpConstraintAtom::SET_LOCAL_ROTATIONS:
            cursor += 112;
            break;
        case hkpConstraintAtom::SET_LOCAL_TRANSLATIONS:
            cursor += 48;
            break;
        case hkpConstraintAtom::BRIDGE:
        case hkpConstraintAtom::MODIFIER_SOFT_CONTACT:
        case hkpConstraintAtom::MODIFIER_MASS_CHANGER:
        case hkpConstraintAtom::MODIFIER_VISCOUS_SURFACE:
        case hkpConstraintAtom::MODIFIER_MOVING_SURFACE:
        case hkpConstraintAtom::MODIFIER_IGNORE:
            return;
        default:
            break;
        }
        continue;
    sharedContribution:
        if (tempsDelta == 3)
        {
            infoOut->numSolverElemTemps += 3;
            _ReadWriteBarrier();
            cursor += 16;
        }
        else
        {
            infoOut->numSolverElemTemps += 9;
            _ReadWriteBarrier();
            cursor += 80;
        }
    }
}
