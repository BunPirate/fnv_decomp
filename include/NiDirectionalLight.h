#pragma once

#include "NiLight.h"

// pdb: class NiDirectionalLight, size 0x130 (here 0xfc), bases: NiLight, 1 members
class NiDirectionalLight : public NiLight
{
  public:
    NiDirectionalLight();


    void CopyMemberData(NiDirectionalLight* dst, CloningProcess& process);
    void SetAmbientColor(const NiColor& color);
    void SetDiffuseColor(const NiColor& color);

    char unkF0[4];
    char _pad_f4[8];
};
