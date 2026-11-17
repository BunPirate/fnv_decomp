// fallout/misc/main.h: declares SceneGraph, Main
#include "../../../include/SceneGraph.h"
#ifndef FNV_MAIN_H
#define FNV_MAIN_H

// Shared classes: NiMemObject, NiPointer, NiRefObject (include/). Main::spMenuSceneGraph's assignment is the
// out-of-line NiPointer<SceneGraph>::operator= (0x0066b0d0), declared as an explicit specialization below.
#include "../../../include/NiMemObject.h"
#include "../../../include/NiPointer.h"
#include "../../../include/NiRefObject.h"

class NiCamera;
class SceneGraph;
class PlayerCharacter;

template <> NiPointer<SceneGraph>& NiPointer<SceneGraph>::operator=(SceneGraph* object);

extern PlayerCharacter* g_thePlayer;


// pdb: class Main, size 0xac (here 0x1), 25 members
class Main
{
  public:
    static NiPointer<SceneGraph> spMenuSceneGraph;

    static void CreateMenuRootNode3D();
};

// @fnv 0x004dc650
// src: XBOX_DEBUG_PDB 0x004dc650
// pdb: Main::CreateMenuRootNode3D | Main.obj | debug, unique string literal, high
void Main::CreateMenuRootNode3D()
{
    spMenuSceneGraph = new SceneGraph("3DMenu", false, 0);
}

#endif
