
// bgsentrypointfunction_ctx_variant.cpp: context variant of src/fallout_shared/bgsentrypointfunction.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "BGSEntryPointFunction.h"
// Retain the support types already supplied by this unit's legacy headers.
#include "../fallout_shared/layout_support.h"
#pragma include_alias("TESForm.h", "../../include/TESForm.h")
#pragma include_alias("BaseFormComponent.h", "../fallout_shared/BaseFormComponent.h")
#pragma include_alias("BSSimpleList.h", "../fallout_shared/layout_support.h")
#include "../../include/Script.h"
#include "../../include/ScriptVariableInfo.h"

extern "C" void* __cdecl memset(void* dest, int c, size_t count);

extern ScriptVariableInfo* DAT_011cb0fc;

class FUN_00500910
{
  public:
    BSStringT<char> name;
    unsigned int formID;
    unsigned int variableOrIndex;

    FUN_00500910();
};

class FUN_00472840_impl
{
  public:
    bool ReadChunkData(unsigned short*);
};

class FUN_005e6c60_shell
{
  public:
    void SetLabel(void* apLabel);
};

class ActivateChoice : public BGSEntryPointFunctionDataActivateChoice
{
  public:
    bool BGSEntryPointFunctionDataActivateChoice_Load(TESFile* apFile);
};

// @fnv 0x005e6ee0
// src: XBOX_PDB 0x005e6ee0
// pdb: BGSEntryPointFunctionDataActivateChoice::Load | BGSEntryPointFunction.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: pMessage, tmpdata, n, pNewItem, tempID, pbuffer
bool ActivateChoice::BGSEntryPointFunctionDataActivateChoice_Load(TESFile* apFile)
{
    void* scvrBuf3;
    unsigned int scdaSize4;
    void* scdaData;
    unsigned int scroRefID2;
    FUN_00500910* scroObjVal;
    unsigned int scrvRefID3;
    FUN_00500910* _scrvObj;
    void* epf2BufTmp;

    switch (static_cast<int>(apFile->GetChunkID()))
    {
    case 0x44534c53:  // 'SLSD'
    case 0x52564353:  // 'SCVR'
        if (apFile->GetChunkID() == 0x44534c53)
        {
            DAT_011cb0fc = new ScriptVariableInfo();
            DAT_011cb0fc->Load(apFile);
            (&resultScript)->GetVariableList()->AddTail(DAT_011cb0fc);
        }
        else if (DAT_011cb0fc)
        {
            scvrBuf3 = _alloca(apFile->GetChunkSize());
            apFile->GetChunkData(scvrBuf3, 0x200);
            DAT_011cb0fc->name.Set(reinterpret_cast<const char*>(scvrBuf3), 0);
        }
        break;

    case 0x52484353:  // 'SCHR'
        apFile->GetChunkData((&resultScript)->GetHeader(), 0);
        if (apFile->IsEndianConversionRequired())
        {
            (&resultScript)->GetHeader()->Endian();
        }
        break;

    case 0x41444353:  // 'SCDA'
        scdaSize4 = apFile->GetChunkSize();
        scdaData = _alloca(scdaSize4);
        memset(scdaData, 0, scdaSize4);
        apFile->GetChunkData(scdaData, 0);
        (&resultScript)->SetCompileData(scdaSize4, reinterpret_cast<char*>(scdaData));
        break;

    case 0x4f524353:  // 'SCRO'
        scroObjVal = new FUN_00500910();
        apFile->GetChunkData(&scroRefID2);
        scroObjVal->formID = scroRefID2;
        (&resultScript)->GetReferencedObjectList()
            ->AddTail(reinterpret_cast<ScriptReferencedObject*&>(scroObjVal));
        break;

    case 0x56524353:  // 'SCRV'
        _scrvObj = new FUN_00500910();
        apFile->GetChunkData(&scrvRefID3);
        _scrvObj->variableOrIndex = scrvRefID3;
        (&resultScript)->GetReferencedObjectList()
            ->AddTail(reinterpret_cast<ScriptReferencedObject*&>(_scrvObj));
        break;

    case 0x32465045:  // 'EPF2'
        epf2BufTmp = _alloca(apFile->GetChunkSize());
        apFile->GetChunkData(epf2BufTmp, 0);
        reinterpret_cast<FUN_005e6c60_shell*>(this)->SetLabel(epf2BufTmp);
        break;

    case 0x33465045:  // 'EPF3'
        reinterpret_cast<FUN_00472840_impl*>(apFile)->ReadChunkData(&cFlags);
        break;

    default:
        break;
    }

    return true;
}
