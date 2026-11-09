#pragma once

class NiStream;
class SkinStream;

// pdb: class NiSphere, size 0x10, 2 members
class NiSphere
{
public:
    float m_kCenter;
    float y;
    float z;
    float m_fRadius;

    void LoadBinary(NiStream& kStream);
    void SaveBinary(NiStream& kStream);
    void SaveBinary(SkinStream& stream);
};
