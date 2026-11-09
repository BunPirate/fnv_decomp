#pragma once

#include "MagicItemForm.h"

// pdb: class EnchantmentItem, size 0x44, bases: MagicItemForm, 1 members
class EnchantmentItem : public MagicItemForm
{
public:
    EnchantmentItem();
    virtual ~EnchantmentItem();

    bool IsValidObject(TESForm* form);
    unsigned int GetEnchantmentType();
    void ResetFormData();
    bool FUN_004094f0(TESForm* owner);
    int FUN_005f36f0();

    union
    {
        struct
        {
            union
            {
                unsigned int enchantmentType;
                unsigned int type;
            };
            union
            {
                unsigned char enchantmentData[0xC];
                struct
                {
                    unsigned int charge;
                    unsigned int cost;
                    unsigned char flags;
                    unsigned char unk41[3];
                };
            };
        };
        char data[0x10];
    };
};
