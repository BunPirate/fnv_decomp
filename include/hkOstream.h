#pragma once

#include "hkBool.h"
#include "hkReferencedObject.h"
#include "hkStreamWriter.h"

class hkStringPtr;
struct InlineStorageString;

// pdb: class hkOstream, size 0xc, bases: hkReferencedObject, 1 members
class hkOstream : public hkReferencedObject
{
public:
    hkStreamWriter* m_writer;

    static const ClassMemberDescriptor Members[];

    __declspec(nothrow) hkOstream(void* buf, int bufSize) throw();
    hkOstream(char* buf, int bufSize);
    hkOstream(char* buf, int bufSize, hkBool isString);
    __declspec(nothrow) ~hkOstream() throw();

    __declspec(nothrow) hkOstream& operator<<(const char* str) throw();
    hkOstream& operator<<(const void* ptr);
    hkOstream& operator<<(const hkStringPtr& str);
    hkOstream& operator<<(unsigned int u) throw();
    hkOstream& operator<<(float value) throw();

    hkOstream& WriteInt(int i);
    hkOstream& WriteFloat(float f) throw();
    __declspec(nothrow) hkOstream& WriteName(const hkStringPtr& str) throw();
    void InvokeFromRequest(const InlineStorageString& str);

    hkOstream* FUN_00cb1600(void* buf, int bufSize);
    void FUN_00cc00e0();
    __declspec(nothrow) hkOstream& ProcessAndReturnValue_00cc01c0(const char* str) throw();
};
