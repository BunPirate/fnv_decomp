#pragma once

#include "NiColor.h"

// pdb: class BSFogProperty, size 0x64, bases: NiFogProperty, 9 members
class BSFogProperty
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiColor color;
    float nearDepth;
    float fEndDistance;
    int fStartWaterDistance;
    int fEndWaterDistance;
    int kPlane;
    int unk40;
    int unk44;
    int unk48;
    int fFalloff;
    int fHeight;
    int unk54;
    int unk58;
    int unk5c;
    float density;

    BSFogProperty();
    ~BSFogProperty();

    static void* operator new(size_t size);
    static void operator delete(void*, unsigned int);
    void IncRefCount();
    void DecRefCount();
    BSFogProperty* __thiscall BSFogProperty_ScalarDtor(unsigned char flags);

    void SetFog(float start, float end);
    void SetPower(float power);
    void SetWaterFog(float start, float end);
    void SetWaterColor(const NiColor& color);
};
