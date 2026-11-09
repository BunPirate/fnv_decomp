#pragma once

class TESResponse;

class TESResponseList
{
public:
    TESResponse* pHead;

    TESResponseList();
    ~TESResponseList();
    operator unsigned int() const;
    TESResponse* QResponseList();
    void AddTail(TESResponse*);
    void Remove(TESResponse*);
    unsigned int GetListCount();
    void ResponseListWrapper_ClearResponseList();
    void SetResponseList(TESResponse*);
    void ResetFaceGen();
    void InsertBefore(TESResponse*, TESResponse*);
    void InsertAfter(TESResponse*, TESResponse*);
};
