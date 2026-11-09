
// src/fallout/ai/middlehighprocess_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/middlehighprocess.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "middlehighprocess_decls.h"
bool IsValidSandboxProcedure(int aiProcedure);

struct C69FC0State
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int flags;
};
struct C69FC0Packet
{
    unsigned int status;
    unsigned char mode;
    unsigned int opcode;
    unsigned int selection;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
C69FC0State* __cdecl GetExtraDataChecked(int apObject);
void __cdecl bhkWorld_DoObjectRec(int apObject, C69FC0Packet* arData, unsigned int apFunc);
extern unsigned int DAT_011afebc;

static inline unsigned int C69FC0IsEnabled(int object)
{
    C69FC0State* pkState = GetExtraDataChecked(object);
    return pkState ? (pkState->flags & 2) : 0;
}

// @fnv 0x00c69fc0
// src: XBOX_RETAIL_PDB 0x00c69fc0
// pdb: bhkWorld::AdjustForceAddCount | bhkWorld.obj | retail, object-file gap fill, high
// pdb params: apObject, abIncrement, abRecurse, abForce
// pdb locals: bres, recData
bool __cdecl bhkWorld_AdjustForceAddCount(int apObject, unsigned char abIncrement, unsigned char abRecurse, unsigned char abForce)
{
    bool bResult = false;
    if (apObject)
    {
        if (abForce || C69FC0IsEnabled(apObject))
        {
            bResult = true;
            C69FC0Packet kPacket;
            kPacket.status = 0;
            kPacket.mode = abRecurse;
            kPacket.opcode = 0xd;
            kPacket.selection = abIncrement != 0;
            if (DAT_011afebc)
                bhkWorld_DoObjectRec(apObject, &kPacket, DAT_011afebc);
        }
    }
    return bResult;
}
