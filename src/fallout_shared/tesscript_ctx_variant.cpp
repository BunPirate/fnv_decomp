
// tesscript_ctx_variant.cpp: context variant of src/fallout_shared/tesscript.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesscript_decls.h"
// TESFileFormInt_tesscript: local type (was include/TESFileFormInt.h, which had no evidence of one real class); its methods are 0x00472660 TESFile::GetTESForm
class TESFileFormInt_tesscript
{
public:
    int GetTESForm();
};

class ScriptLoader : public Script
{
  public:
    bool Script_Load(TESFile* pFile);
};

// @fnv 0x005ab9f0
// src: XBOX_PDB 0x005ab9f0
// pdb: Script::Load | TESScript.obj | retail, string-set bridge, high
// pdb params: pFile
// pdb locals: chunkid, pNewVariable, n, pMessage, pNewItem, tempID, refvidx
bool ScriptLoader::Script_Load(TESFile* pFile)
{
    ScriptVariableInfo* chunk = 0;
    unsigned int reference;
    char* variable;
    int size;
    char* variableName;
    unsigned int unusedID;
    ScriptReferencedObject* referenceID;
    unsigned int editorID;
    if (reinterpret_cast<TESFileFormInt_tesscript*>(pFile)->GetTESForm() != ENUM_FORM_ID_SCPT_ID)
        return false;
    LoadRecordHeader(pFile);
    while (size = pFile->GetChunkID())
    {
        switch (size)
        {
        case 0x44494445:
            variable = (char*)_alloca(pFile->GetChunkSize());
            pFile->GetChunkData(variable, 0x200);
            SetEditorID_AtRuntime(variable);
            break;
        case 0x444e424f:
            readOBNDSubRecord(pFile);
            break;
        case 0x52484353:
            pFile->GetChunkData(&m_header, 0);
            if (pFile->IsEndianConversionRequired())
                m_header.Endian();
            break;
        case 0x44534c53:
            chunk = new ScriptVariableInfo;
            chunk->Load(pFile);
            GetVariableList()->AddTail(chunk);
            break;
        case 0x52564353:
            if (chunk)
            {
                variableName = (char*)_alloca(pFile->GetChunkSize());
                pFile->GetChunkData(variableName, 0x200);
                chunk->name.Set(variableName, 0);
            }
            break;
        case 0x41444353:
            reference = pFile->GetChunkSize();
            m_data = ourCalloc(1, reference);
            memset(m_data, 0, reference);
            pFile->GetChunkData(m_data, 0);
            break;
        case 0x4f524353:
        case 0x56524353:
            referenceID = new ScriptReferencedObject;
            pFile->GetChunkData(&unusedID);
            if (size == 0x4f524353)
                referenceID->pForm = (TESForm*)unusedID;
            else
                referenceID->m_uiFormID = unusedID;
            GetReferencedObjectList()->AddTail(referenceID);
            break;
        case 0x54584353:
            break;
        case 0x44484353:
            break;
        case 0x4d414e52:
            pFile->GetChunkData(&editorID);
        }
        if (!pFile->NextChunk())
            break;
    }
    if (!m_data)
        Warning("MASTERFILE: Script '%s' in file '%s' has not been compiled.\r\n", GetName(), pFile->GetFilename());
    return true;
}
