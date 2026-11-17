#pragma once
#include "NiRefObject.h"

class NiPixelData;
class NiPixelFormat;

// pdb: class NiImageConverter, size 0x780 (here 0x8), bases: NiRefObject, 1 members
class NiImageConverter : public NiRefObject
{
public:
    virtual void vf02();
    virtual void vf03();
    virtual bool CanConvertPixelFormat(const NiPixelFormat&, const NiPixelFormat&);
    virtual NiPixelData* ConvertImageData(const NiPixelData&, const NiPixelFormat&, NiPixelData*, bool);

    static NiImageConverter* GetSharedImageConverter();
};
