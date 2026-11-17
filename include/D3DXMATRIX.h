#pragma once

// Include after the SDK (or its CodeView-compatible local declaration) defines _D3DMATRIX.
// src: DirectX SDK d3dx9math.h; this project uses the trivial 64-byte storage form.
// pdb: structure D3DXMATRIX, size 0x40, bases: _D3DMATRIX, 0 members
class D3DXMATRIX : public _D3DMATRIX
{
};
