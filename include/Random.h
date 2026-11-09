#pragma once

class FloatIntPair;

// pdb: class Random, size 0x4, 0 members
class Random
{
public:
    virtual ~Random();
    virtual float Next();
    virtual char* Name();
    virtual float Density(float value) const;
    virtual FloatIntPair* vf04(FloatIntPair* value);
    virtual FloatIntPair* vf05(FloatIntPair* value);
    virtual int vf06();
    virtual void vf07();
    virtual void vf08(int a, int b, int c);

    static float Raw();
    static void Set(double s);
    static void SetLong(long s);
    void* __thiscall DestroyRandom(unsigned int flags);
};
