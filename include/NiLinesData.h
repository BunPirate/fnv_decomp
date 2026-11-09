#pragma once

#include "NiGeometryData.h"

// pdb: class NiLinesData, size 0x44, bases: NiGeometryData, 1 members
class NiLinesData : public NiGeometryData
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);

    void* Destroy(unsigned int flags);
    bool IsGeometryEqual(NiObject* other) const;
    void RegisterGeometryFields(NiViewerStringsArray* pkStrings);

    unsigned char* m_pkFlags;
};
