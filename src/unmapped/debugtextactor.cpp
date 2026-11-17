
// src/unmapped/debugtextactor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextactor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_009aae70_Entry
{
    unsigned char flag;
    int unk04;
};
extern S_009aae70_Entry DAT_011a55b4[];

const char* __cdecl CombatWorldState_GetStateValueText(int type, unsigned int value);
const char* __cdecl CombatWorldState_GetStateName(int type);
int __cdecl BSsprintf(char* buf, int size, const char* fmt, ...);
unsigned int __cdecl BSstrlen(const char* s);
int __cdecl FUN_00406d50(char* dst, unsigned int size, const char* src);

struct S_009aae70
{
    unsigned int FUN_005bd5c0(int type);
    void CombatWorldStateArray_GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aeState);
};

// @fnv 0x009aae70
// src: XBOX_DEBUG_PDB 0x009aae70
// pdb: CombatWorldStateArray::GetDebugText | CombatWorldState.obj | debug, unique string literal, high
// pdb params: apDebugText, aiMaxLength, aeState
// pdb locals: ivalue, bstarted, i, ptemp
void S_009aae70::CombatWorldStateArray_GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aeState)
{
    unsigned int mask = FUN_005bd5c0(aeState);
    if (DAT_011a55b4[aeState].flag)
    {
        bool any = false;
        for (unsigned int uiBit = 0; uiBit < 32; uiBit++)
        {
            if (mask & (1 << uiBit))
            {
                if (!any)
                {
                    BSsprintf(apDebugText, aiMaxLength, "%s: %s", CombatWorldState_GetStateName(aeState), CombatWorldState_GetStateValueText(aeState, uiBit));
                }
                else
                {
                    char acTemp[260];
                    BSsprintf(acTemp, 0x104, ", %s", CombatWorldState_GetStateValueText(aeState, uiBit));
                    FUN_00406d50(apDebugText, aiMaxLength - BSstrlen(apDebugText), acTemp);
                }
                any = true;
            }
        }
        if (!any)
            BSsprintf(apDebugText, aiMaxLength, "%s: None", CombatWorldState_GetStateName(aeState));
    }
    else
    {
        BSsprintf(apDebugText, aiMaxLength, "%s: %s", CombatWorldState_GetStateName(aeState), CombatWorldState_GetStateValueText(aeState, mask));
    }
}
