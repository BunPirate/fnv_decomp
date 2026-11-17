#pragma once

#include <cstddef>
#include "hkReferencedObject.h"

class hkpContactMgr;

// pdb: class hkpCollisionAgent, size 0xc, bases: hkReferencedObject, 1 members
class hkpCollisionAgent : public hkReferencedObject
{
public:
    class CommandArgument;

    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl operator delete(void* p);
    static void* __cdecl operator new(std::size_t nbytes, void* p);
    static void* __cdecl operator new[](std::size_t nbytes, void* p);
    static void __cdecl operator delete(void* p, void* placement);
    static void __cdecl operator delete[](void* p, void* placement);

    hkpContactMgr* m_contactMgr; // src: XBOX_RETAIL_PDB +0x8 (old: m_pContactManager)

    hkpContactMgr* getContactMgr();

protected:
    hkpCollisionAgent(hkpContactMgr* contactMgr);
    ~hkpCollisionAgent() throw();
};
