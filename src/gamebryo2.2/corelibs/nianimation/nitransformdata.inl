struct NiQuaternionConjugateValue
{
    float w, x, y, z;
};

// Quaternion conjugation inferred from the PC instructions.
// @fnv 0x00a6dc00
// pdb: D3DXShader::Compiler::Abs | import.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiQuaternion::UnitInverse
// pdb params: pInstr
NiQuaternionConjugateValue __cdecl NiQuaternionConjugate(const NiQuaternionConjugateValue& value)
{
    NiQuaternionConjugateValue result;
    result.w = value.w;
    result.x = -value.x;
    result.y = -value.y;
    result.z = -value.z;
    return result;
}
