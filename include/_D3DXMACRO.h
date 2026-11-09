#pragma once

// DX9 SDK _D3DXMACRO; exe shader compilation passes an eight-byte Name/Definition pair.
// pdb: structure _D3DXMACRO, size 0x8, 2 members
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
typedef _D3DXMACRO D3DXMACRO;
