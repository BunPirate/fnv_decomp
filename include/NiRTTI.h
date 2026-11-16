#pragma once

// pdb: class NiRTTI, size 0x8, 2 members
class NiRTTI
{
public:
    NiRTTI(const char* pcName, const NiRTTI* pkBaseRTTI);

    const char* GetName() const;
    const NiRTTI* GetBaseRTTI() const;
    char* GetName();
    void* GetBaseRTTI();
    bool IsExactly(const NiRTTI* type) const;

    const char* m_pcName;
    const NiRTTI* m_pkBaseRTTI; // src: XBOX_RETAIL_PDB +0x4 (old: m_pBaseRTTI)
};
