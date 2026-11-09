#pragma once

template <class T> class NiPointer;
class NiTexture;

// pdb: class SkyTextureManager, size 0x1, 0 members
class SkyTextureManager
{
public:
    static void LoadTextureInBackground(NiPointer<NiTexture>*, const char*);
};
