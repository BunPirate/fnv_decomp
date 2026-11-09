#pragma once

// BGSMenuPacker: packs menu glow branches into one texture area, no vtable. 0x24 bytes: FOHUDEffectManager holds it by
// value from +0x04 to its own bool at +0x28. The constructor 0x007002d0 constructs the NiTPrimitiveArray<PackedMenu*>
// at +0x00 (0x00700480, RTTI NiTPrimitiveArray<BGSMenuPacker::PackedMenu *>, arguments 0 and 1) and clears the byte at
// +0x21; the destructor is 0x007f7770. DumpInfo 0x00700350 prints each PackedMenu ("==== Begin PACK AREA Output ====").

#include "NiTPrimitiveArray.h"

// pdb: class BGSMenuPacker, size 0x24, 7 members
class BGSMenuPacker
{
public:
    struct PackedMenu;

    NiTPrimitiveArray<PackedMenu*> PackedMenus;  // 0x00
    unsigned int w;                           // 0x10
    unsigned int h;                           // 0x14
    unsigned int max_w;                           // 0x18
    unsigned int max_h;                           // 0x1c
    bool dump_info_flag;                                 // 0x20
    bool bPackFailed;                                 // 0x21 ctor: 0

    BGSMenuPacker();                              // 0x007002d0
    ~BGSMenuPacker();                             // 0x007f7770
    void DumpInfo();                              // 0x00700350
};
