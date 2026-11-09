#pragma once

#include "Actor.h"

class BipedAnim;
class BGSLoadFormBuffer;

// pdb: class Character, size 0x1c8, bases: Actor, 6 members
class Character : public Actor
{
public:
    BipedAnim* pBiped;
    float fArmorRating;
    float fArmorThreshold;
    bool bTrespassing;
    bool bGuard;
    unsigned short layoutPadding1C2;
    float fequippedweight;

    virtual void Unk_137(void);
    virtual void Unk_138(void);

    Character(bool);
    virtual ~Character();
    void* operator new(unsigned int);

    MagicTarget* GetMagicTarget();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    void* GetCurrentMusicMarker();
    bool GetActorGuard();
    void SetActorGuardState(bool guard);
    void Reset3D();
};
