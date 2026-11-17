#pragma once

class BGSLoadGameBuffer;
class BGSLoadFormBuffer;
class BGSSaveGameBuffer;
class BGSSaveFormBuffer;
class TESForm;

// pdb: class BGSLoadGameSubBuffer, size 0x4, 1 members
class BGSLoadGameSubBuffer
{
public:
    char* pBuffer;

    BGSLoadGameSubBuffer();
    BGSLoadGameSubBuffer(int initial);

    void SetBuffer(char* buffer);
    void ResetReadPosition();
    void RestoreAnimation(TESForm* apForm);
    void LoadCharController(TESForm* apForm);
    void LoadHavokData(TESForm* apForm);
    void LoadHavokData(void* form);
    void SaveAnimation(TESForm* apForm);
    void SaveHavokData(TESForm* apForm);
    void SaveGame(BGSSaveGameBuffer* buffer);
    void LoadGame(BGSLoadGameBuffer* apLoadGameBuffer);
    BGSLoadFormBuffer* CreateLoadFormBuffer(TESForm* apForm);
    void RenderCopyData(BGSSaveFormBuffer* buffer);
    void DeleteBuffer();
};
