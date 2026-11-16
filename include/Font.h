#pragma once

#include "BSSimpleList.h"
#include "BSStringT.h"
#include "GO.h"
#include "StrMem.h"

class ButtonIcon;

class FontData;
class FontCharacterInfo;
class NiTriShape;
class NiPoint3;
class NiColorA;
class Shape;
class Color;
class Letter;
class NiPoint3;
class Layout;
class TextString;
class Color4;
class TextNode;
struct SStr;

namespace TextLayout
{
    class Layout;
}

namespace PageMeshes
{
    class Shape;
    class Color;
    class Letter;
}

// pdb: class Font, size 0x54, 10 members
class Font
{
public:
    class IconTextureNameStorage : public StrMem
    {
    public:
        IconTextureNameStorage();
        ~IconTextureNameStorage();

        template <class T> __forceinline operator T*()
        {
            return reinterpret_cast<T*>(this);
        }
    };

    class ButtonIconStorage
    {
    public:
        ButtonIcon* pBuffer;
        unsigned int iSize;
        unsigned int SimpleArrayStorage;

        ButtonIconStorage();
        virtual ~ButtonIconStorage();
        virtual void* Allocate(unsigned int count);

        template <class T> __forceinline operator T*()
        {
            return reinterpret_cast<T*>(this);
        }
    };

#ifndef FNV_FONT_H
    class TextMeasurement
    {
    public:
        BSStringT<char> m_kText;
        int iWidth;
        int iHeight;
        int m_iFirstTextMetric;
        int m_iSecondTextMetric;
        int m_iThirdTextMetric;
        char m_cTextState;
        BSSimpleList<int> m_kLineWidths;

        TextMeasurement();
        ~TextMeasurement()
        {
            m_kLineWidths.RemoveAll();
        }

        BSStringT<char>* GetNewText();
        int GetWidth();
        int GetHeight();
        int GetNumLines();
        int GetCharCount();
        int GetLineWidth(int iLine);
    };
#else
    class TextMeasurement;
#endif

    unsigned short iRefCount;
    unsigned char _pad2[2];
    char* pFontFile;
    int iFontNum;
    GO pTextureData[8];
    float fFontHeight;
    float fMaxDrop;
    unsigned char iLineOverlap[4]; // src: XBOX_RETAIL_PDB +0x34 (old: _unverified_iLineOverlap)
    FontData* pFontData;
    IconTextureNameStorage IconAtlasTextureName;
    ButtonIconStorage ButtonIcons;

    Font();
    Font(int fontNum, const char* file, bool load);
    Font(int fontNum, const char* file, int load);
    ~Font();

    void Load();
    void LoadFont();
    void ClearArray();
    void FUN_00a121e0();
    void Unload_00a152d0();
    NiTriShape* Font_MakeString(float fX, float fY, float fZ, SStr* text, int* piX,
                            int iFlags, void* pUnk, bool bShift, bool bSkip);
    NiTriShape* Font_MakeString(float afStartX, float afStartY, float afZ, BSStringT<char>* apTextString,
                            int* aiWidth, int aiFlags, void* axFontColor, bool abUpperLeftCorner, bool abPrepareObject);
    void Font_GetLineOffsets(char* str, float* pSize, float* pOut, int iFlags, int iStart);
    void Font_GetLineOffsets(const char* text, float& x, float& y, int flags,
                      unsigned int start);
    NiTriShape* CreateTextShape(int count, void* p, bool b);
    void CheckForVariablesInText(const char* input, Layout* layout);
    void PrepText(const char* apOrigString, TextLayout::Layout* axData);
    void CheckForVariablesInText(const char* input, TextMeasurement* layout);
    void Font_CreateText(TextString&, int*, int*, int, int, int, int,
                      const Color4*, TextNode**, TextNode**);
    PageMeshes::Shape* MakeIconsTriShape();
    PageMeshes::Shape* Font_MakeTriShape(int, const PageMeshes::Color*, bool);
    void Font_AddIcon(int, PageMeshes::Shape*, NiPoint3&);
    void BuildGlyphQuad(PageMeshes::Letter*, int, PageMeshes::Shape*, NiPoint3&,
                        const PageMeshes::Color*);

    static void MapCharacter(unsigned char& character);
    void AddCharacterToShape(FontCharacterInfo* apLetter, int aiVert, NiTriShape* apShape,
                             NiPoint3& axPos, const NiColorA* apColor);
    Shape* CreateTextShape(int, const Color*, bool);
    void UpdateIconGeometry(int, Shape*, NiPoint3&);
    void BuildGlyphQuad(Letter*, int, Shape*, NiPoint3&, const Color*);
    float GetHeight() const;
    void SetHeight(float value);
    unsigned int GetIconCount();
    void Font_AddTextIcon(const char*);
    float Height();
};

#ifndef FNV_FONT_H
#define FNV_FONT_H
#endif
