#pragma once

#include "hkReferencedObject.h"
#include "hkTransform.h"

// pdb: class hkDisplayGeometry, size 0x60 (here 0x50), bases: hkReferencedObject, 3 members
class hkDisplayGeometry : public hkReferencedObject
{
public:
    virtual ~hkDisplayGeometry() throw();
    virtual void vf03();
    virtual void vf04();

    hkTransform m_kMotionTransform;

    static void* __cdecl operator new(std::size_t nbytes);
};
