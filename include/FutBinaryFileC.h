#pragma once

#include <string>

class BxString;

// pdb: class FutBinaryFileC, size 0x40, 3 members
class FutBinaryFileC
{
public:
    virtual ~FutBinaryFileC();
    virtual bool vf01(std::string name);
    virtual bool vf02(std::string path);
    virtual void vf03(int a, int b, int c);
    virtual void vf04(int a, int b, int c);

    FutBinaryFileC(std::string signature);
    template <class String>
    FutBinaryFileC(String signature);

    char CheckSignature(const std::string& path);
    bool CheckSignature(const BxString& path);
    template <class String>
    char CheckSignature(const String& path);

    char ProcessAndReturnValue_00ac3fe0(const std::string& path);
    bool ProcessAndReturnValue_00ac3fe0(const BxString& path);
    bool ProcessAndReturnValue_00ac3fe0(const char* name);
    template <class String>
    char ProcessAndReturnValue_00ac3fe0(const String& path);

    std::string m_fname; // src: XBOX_RETAIL_PDB +0x4 (old: signature)
    std::string fileId; // src: XBOX_RETAIL_PDB +0x20 (old: path)
    unsigned int fptr; // src: XBOX_RETAIL_PDB +0x3c (old: unk3c)
};
