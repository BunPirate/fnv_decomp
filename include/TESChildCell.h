#pragma once

class TESObjectCELL;

// pdb: class TESChildCell, size 0x4, 0 members
class TESChildCell
{
public:
    TESChildCell();

    virtual TESObjectCELL* GetSaveParentCell();
};
