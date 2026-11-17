#pragma once

#include "hkArray.h"

// pdb: class hkStringBuf, size 0x8c, 1 members
class hkStringBuf
{
public:
    hkArray<char, hkContainerTempAllocator> m_string;
    unsigned int m_storage[32];

    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };

    hkStringBuf() throw();
    ~hkStringBuf() throw();

    void hkStringBuf_ctor() throw();
    __declspec(noinline) void Writer_MemberWriteFlags_dtor() throw();
    void FUN_00d61c10(const char* s) throw();

    int indexOf(const char* s, int startIndex, int endIndex) const throw();
    int indexOf(char c, int start, int end) const;
    int lastIndexOf(char needle, int start, int end) const;
    int startsWithCase(const char* s) const;
    void pathBasename();
    int replace(char from, char to, ReplaceType rtype);
    void lowerCase();
    void upperCase();
    void appendJoin(const char* s0, const char* s1 = 0, const char* s2 = 0,
                    const char* s3 = 0, const char* s4 = 0, const char* s5 = 0) throw();
    void set(const char* s, int len);
    int split(int sep, hkArray<const char*, hkContainerTempAllocator>& bits);
    void chompStart(int n);
    void chompEnd(int n);
    void slice(int startOffset, int length);
    hkStringBuf& operator=(const char* s);
    hkStringBuf& operator+=(const char* other) throw();

    int getLength() const { return m_string.m_iElementCount - 1; }
    int getCapacity() const { return m_string.getCapacity(); }
    const char* cString() const { return m_string.m_data; }
    void setEmpty() { m_string.m_data[0] = 0; }
    __forceinline void SetSizeAndGrow(int n);
    __forceinline void setLength(int n);
};
