#pragma once

class TESFile;
class TESForm;

// pdb: class BGSEntryPointFunctionData, size 0x4, 0 members
class BGSEntryPointFunctionData
{
public:
    virtual ~BGSEntryPointFunctionData();
    virtual unsigned char GetType();
    virtual BGSEntryPointFunctionData* Duplicate();
    virtual bool Compare(BGSEntryPointFunctionData* other);
    virtual void Save();
    virtual void Load(TESFile* file);
    virtual void InitItem(TESForm* form);
};
