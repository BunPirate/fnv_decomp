#pragma once

#include "TESForm.h"
#include "TESChildCell.h"

class LandscapeColorData;
class NiGeometry;
class NiPoint3;
class NiColorA;
class TESObjectCELL;
class NiPoint3;

// pdb: class TESObjectLAND, size 0x2c, bases: TESForm, TESChildCell, 4 members
class TESObjectLAND : public TESForm, public TESChildCell
{
public:
    unsigned char Data[0x10]; // src: XBOX_RETAIL_PDB +0x1c (old: formData)

    TESObjectLAND();
    void InitializeForCell(TESObjectCELL* cell);
    bool GetLandHeightAtPosition(const NiPoint3& coord, float& height);
    void ResetFadeOutMultipliers();
    bool __thiscall TESObjectLAND_GetCoordData(LandscapeColorData&, const LandscapeColorData&, int);
    bool __thiscall TESObjectLAND_GetCoordData(LandscapeColorData*, const NiPoint3*, int);
    float __thiscall TESObjectLAND_GetDefaultWorldHeight();
    bool __thiscall TESObjectLAND_GetLandHeight(LandscapeColorData&, float&);
    bool __thiscall GetLandHeight(const LandscapeColorData&, float&);
    NiGeometry* __thiscall GetGeometry_0053f120(LandscapeColorData*);
    NiGeometry* __thiscall GetGeometry_0053f0e0(const NiPoint3&);
    void TESObjectLAND_GetColorA(int iblock, int m_iGridY, NiColorA* color);
    bool GetLandColor_0(const LandscapeColorData* cdata, NiColorA* color);
    void TESObjectLAND_SetLandRemapped(int);
    void SetCell(TESObjectCELL* apCell);
    void SetAltered_00539010(bool abVal);
    NiPoint3* TESObjectLAND_GetMainTexture();
};
