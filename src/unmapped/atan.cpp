// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

float __cdecl atan2_004b5570(float, float);

// @fnv 0x004b5550
// src: XBOX_PDB 0x004b5550
// pdb: NiATan2 | GlobalFunc.obj | debug, upstream name already matches, high
// pdb params: fNumerator, fDenominator
float __cdecl NiATan2(float fNumerator, float fDenominator)
{
    return atan2_004b5570(fNumerator, fDenominator);
}
