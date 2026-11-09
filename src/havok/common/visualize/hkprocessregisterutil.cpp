
// src/havok/common/visualize/hkprocessregisterutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkprocessregisterutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkDebugDisplayProcess_registerProcess();
void __cdecl hkStatisticsProcess_registerProcess();
void __cdecl hkInspectProcess_registerProcess();
// @fnv 0x00d61420
// src: COMMUNITY 0x00d61420
// pdb: hkProcessRegisterUtil::registerAllCommonProcesses | hkProcessRegisterUtil.obj | retail, upstream name already matches, high
void __cdecl hkProcessRegisterUtil_registerAllCommonProcesses()
{
    hkDebugDisplayProcess_registerProcess();
    hkStatisticsProcess_registerProcess();
    hkInspectProcess_registerProcess();
}
