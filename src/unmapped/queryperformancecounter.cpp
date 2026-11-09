// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObject_0044fae0
{
    void BSCriticalSection_Lock(int);
    void BSCriticalSection_Enter(int);
};

// @fnv 0x004538a0
// src: XBOX_PDB 0x004538a0
// pdb: BSCriticalSection::Enter | TES.obj | debug, upstream name already matches, high
// pdb params: apName
void GlobalObject_0044fae0::BSCriticalSection_Enter(int apName)
{
    BSCriticalSection_Lock(apName);
}
