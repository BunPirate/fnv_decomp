#pragma once

#include "NiObject.h"

class ScreenReference;

// pdb: class NiScreenPolygon, size 0x1c, bases: NiObject, 5 members
class NiScreenPolygon : public NiObject
{
  public:
    ScreenReference* m_spPropertyState;
    ScreenReference* m_usVertices;
    ScreenReference* m_pkVertex;
    ScreenReference* m_pkTexture;
    ScreenReference* m_pkColor;

    NiScreenPolygon(const NiScreenPolygon& other);
    NiScreenPolygon& operator=(const NiScreenPolygon& other);
};
