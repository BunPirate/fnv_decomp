#pragma once

class NiStream;
class SkinStream;

// pdb: class NiSphere, size 0x10, 2 members
class NiSphere
{
public:
    float m_kCenter; // src: XBOX_RETAIL_PDB +0x0 (old: x)
    float y;
    float z;
    float m_fRadius; // src: XBOX_RETAIL_PDB +0xc (old: r)

    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    void SaveBinary(SkinStream& stream);
};
