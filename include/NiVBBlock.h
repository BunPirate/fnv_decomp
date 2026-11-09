#pragma once

// pdb: class NiVBBlock, size 0x44, 14 members
class NiVBBlock
{
public:
    struct DynamicArrayChip
    {
        void* unk00;
        unsigned int* m_30;
        unsigned short unk34;
        unsigned short m_36;
        unsigned short m_38;
        unsigned short unk3A;

        void RemoveAll(unsigned int zero)
        {
            for (unsigned short i = 0; i < m_36; ++i)
                m_30[i] = zero;
            m_36 = 0;
            m_38 = 0;
        }
    };

    union { unsigned int m_00; void* m_pBuffer; };
    unsigned int m_uiIndex;
    unsigned int m_pkVB;
    union { unsigned int m_0c; unsigned int m_uiSize; };
    unsigned int m_uiFVF;
    unsigned int m_uiFlags;
    unsigned int m_uiUsage;
    union { unsigned int m_1c; unsigned long m_uiValue1C; };
    union { unsigned int m_20; unsigned int m_uiValue20; };
    union { unsigned int m_24; unsigned int m_uiValue24; };
    union { unsigned int m_28; unsigned int m_uiValue28; };
    DynamicArrayChip m_apkChips;
    unsigned int m_pkNextBlock;
    unsigned int m_pkPrevBlock;

    void ClearAllData();
    void FreeVBBlock(unsigned int);
    void* NiVBBlock_AllocateChip(unsigned int);
};
