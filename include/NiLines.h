#pragma once

#include "NiGeometry.h"

namespace stand { class NiPoint3; }
class NiColorA;

// pdb: class NiLines, size 0xf0 (here 0xc4), bases: NiGeometry, 0 members
class NiLines : public NiGeometry
{
  public:
    NiLines();
    NiLines(unsigned short usVertices, stand::NiPoint3* vertices, NiColorA* colors,
            void* normals, void* textures, void* data, bool* pkFlags);
    void CopyMemberData(NiLines* source, CloningProcess& process);
    bool FUN_00a80430(NiStream& stream);

};
