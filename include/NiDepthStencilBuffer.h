#pragma once

#include "Ni2DBuffer.h"

class NiRenderer;
class NiPixelFormat;
class Resource;
class Renderer;
class Format;

// pdb: class NiDepthStencilBuffer, size 0x14, bases: Ni2DBuffer, 0 members
class NiDepthStencilBuffer : public Ni2DBuffer
{
public:
    NiDepthStencilBuffer() throw();
    virtual ~NiDepthStencilBuffer();

    void* Destroy(unsigned int);
    static NiDepthStencilBuffer* Create(unsigned int, unsigned int, NiRenderer*, const NiPixelFormat&, unsigned int);
    static Resource* Create(unsigned int, unsigned int, Renderer*, const Format&, unsigned int);
};
