#ifndef FNV_TESOBJECTCONT_MATCH_DECLS_H
#define FNV_TESOBJECTCONT_MATCH_DECLS_H

class TESObjectCONT_TESScriptableInitCall
{
  public:
    void InitItem(TESForm*);
};

#include "../../include/TESSound.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

// pdb: class ContainerItemExtra, size 0xc, 5 members
class ContainerItemExtra
{
  public:
    unsigned int pOwnerForm;
    unsigned int opaque4;
    unsigned int fHealthMult;
    ContainerItemExtra();
    bool Load(TESFile*);
};

struct ContainerItemExtraOwner
{
    unsigned int opaque0;
    unsigned int opaque4;
    ContainerItemExtra* item;
};

class CombatController;
#include "../../include/CombatProcedure.h"
#include "../../include/EffectSetting.h"
class BGSVoiceType;
#include "../../include/BGSTalkingActivator.h"
struct CNTOChunkData
{
    unsigned int formID;
    unsigned int count;
    void TwoValues_Endian();
};

extern "C" ContainerItemExtraOwner* DAT_011c9348;

int __cdecl Warning(const char*, ...);

#endif
