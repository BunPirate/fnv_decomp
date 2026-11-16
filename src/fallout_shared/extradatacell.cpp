// fallout_shared/extradatacell.cpp: ExtraNorthRotation, ExtraCell3D, ExtraHavok, ExtraCellImpactSwap and more (28 functions)

#include "../../include/ExtraCell3D.h"
#include "../../include/ExtraCellAcousticSpace.h"
#include "../../include/ExtraNorthRotation.h"
#include "../../include/ExtraCellImpactSwap.h"
#include "../../include/ExtraCellImageSpace.h"
#include "../../include/ExtraHavok.h"

// Constructs an ExtraNorthRotation, setting its vtable and initializing its float value to 0.0f.
// @fnv 0x0040f680
// pdb: ExtraNorthRotation::ExtraNorthRotation | ExtraDataCell.obj | debug, upstream name already matches, high
ExtraNorthRotation::ExtraNorthRotation() : BSExtraData(0x43)
{
    fNorthRot = 0.0f;
}

struct BE
{
    void* pVftable;
    BE(unsigned char);
};

struct FUN_0040ef00_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040ef00_shell(void* aField);
};

extern void* DAT_01014228;

// Sets the vftable pointer to DAT_01014228 and stores aField in pField.
// @fnv 0x0040ef00
// pdb: ExtraRegionList::ExtraRegionList | ExtraDataCell.obj | debug, call graph, medium
// pdb params: apList
FUN_0040ef00_shell::FUN_0040ef00_shell(void* aField) : BE(4)
{
    *reinterpret_cast<void**>(this) = &DAT_01014228;
    pField = aField;
}

// @fnv 0x0040efd0
// pdb: ExtraCellAcousticSpace::ExtraCellAcousticSpace | ExtraDataCell.obj | debug, upstream name already matches, high
// pdb params: apSpace
ExtraCellAcousticSpace::ExtraCellAcousticSpace(BGSAcousticSpace* apSpace) : BSExtraData(0x81)
{
    pSpace = apSpace;
}

extern void* DAT_0101424c;

struct FUN_0040f070_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f070_shell(void* aField);
};

// @fnv 0x0040f070
// pdb: ExtraCellClimate::ExtraCellClimate | ExtraDataCell.obj | debug, call graph, medium
// pdb params: apClimate
FUN_0040f070_shell::FUN_0040f070_shell(void* aField) : BE(8)
{
    pVftable = &DAT_0101424c;
    pField = aField;
}

struct FUN_0040f4d0_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f4d0_shell(void* aField);
    void* FUN_0040f4d0(unsigned int flags);
    void FUN_0040f500();
};

extern void* _Deallocate(void*);

// Calls FUN_0040f500, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0040f4d0
// pdb: ExtraCellCanopyShadowMask::`scalar deleting destructor' | ExtraDataCell.obj | retail, vtable slot, high
void* FUN_0040f4d0_shell::FUN_0040f4d0(unsigned int flags)
{
    FUN_0040f500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* DAT_01014294;

struct FUN_0040f590_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f590_shell();
};

// Initialises the object with base value 5, sets its vftable pointer to DAT_01014294 and clears pField.
// @fnv 0x0040f590
// pdb: ExtraSeenData::ExtraSeenData | ExtraDataCell.obj | debug, call graph, medium
FUN_0040f590_shell::FUN_0040f590_shell() : BE(5)
{
    pVftable = &DAT_01014294;
    pField = 0;
}

// Calls FUN_0040ee70, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0040ee40
// pdb: ExtraHavok::`scalar deleting destructor' | ExtraDataCell.obj | retail, vtable slot, high
void* ExtraHavok::FUN_0040ee40(unsigned int flags)
{
    FUN_0040ee70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSMusicType;

extern int DAT_01014234;
struct FUN_0040ef30 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040ef30(BGSMusicType* aMusic);
};
// @fnv 0x0040ef30
// pdb: ExtraCellMusicType::ExtraCellMusicType | ExtraDataCell.obj | debug, call graph, medium
// pdb params: apType
FUN_0040ef30::FUN_0040ef30(BGSMusicType* aMusic) : BE(7)
{
    pVftable = &DAT_01014234;
    pField = aMusic;
}

// @fnv 0x0040f1e0
// pdb: ExtraCellImpactSwap::`scalar deleting destructor' | ExtraDataCell.obj | retail, vtable slot, high
void* ExtraCellImpactSwap::FUN_0040f1e0(unsigned int flags)
{
    FUN_0040f210();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01014270;
struct FUN_0040f370 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f370();
};
// @fnv 0x0040f370
// pdb: ExtraCellWaterType::ExtraCellWaterType | ExtraDataCell.obj | debug, call graph, medium
FUN_0040f370::FUN_0040f370() : BE(3)
{
    pVftable = (void*)&DAT_01014270;
    pField = 0;
}

extern int DAT_0101427c;
struct FUN_0040f410 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f410();
};
// @fnv 0x0040f410
// pdb: ExtraProcessMiddleLow::ExtraProcessMiddleLow | ExtraDataCell.obj | debug, call graph, high
FUN_0040f410::FUN_0040f410() : BE(9)
{
    BE::pVftable = (void*)&DAT_0101427c;
    pField = 0;
}

// Initializes the image-space extra data and stores its image-space pointer.
// @fnv 0x0040f110
// pdb: ExtraCellImageSpace::ExtraCellImageSpace | ExtraDataCell.obj | debug, upstream name already matches, high
// pdb params: apImageSpace
ExtraCellImageSpace::ExtraCellImageSpace(void* apImageSpace) : BSExtraData(0x59)
{
    pImageSpace = apImageSpace;
}

struct FUN_0040f1b0_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f1b0_shell();
};

extern void* DAT_01014264;

// @fnv 0x0040f1b0
// pdb: ExtraCellImpactSwap::ExtraCellImpactSwap | ExtraDataCell.obj | debug, call graph, medium
FUN_0040f1b0_shell::FUN_0040f1b0_shell() : BE(0x8c)
{
    *(void**)this = &DAT_01014264;
    pField = 0;
}

// Drop the held cell node before the member and base destructors run.
// @fnv 0x0040ed30
// pdb: ExtraCell3D::~ExtraCell3D | ExtraDataCell.obj | retail, upstream name already matches, high
ExtraCell3D::~ExtraCell3D()
{
    spCellNode = static_cast<NiCell3DNode*>(0);
}

// Constructs the Havok extra data with its world pointer and an empty Mopp reference.
// @fnv 0x0040eda0
// pdb: ExtraHavok::ExtraHavok | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apWorld
ExtraHavok::ExtraHavok(bhkWorld* apWorld) : BSExtraData(1), first(0), spCellMopp(0)
{
    first.FUN_0066b0d0(apWorld);
    spCellMopp.FUN_0066b0d0(0);
}

// @fnv 0x0040ee70
// pdb: ExtraHavok::~ExtraHavok | ExtraDataCell.obj | retail, upstream name already matches, high
ExtraHavok::~ExtraHavok()
{
    spCellMopp.FUN_0066b0d0(0);
    first.FUN_0066b0d0(0);
}

class B0F210Data
{
  public:
    ~B0F210Data();
};

class B0F210ExtraData
{
  public:
    virtual ~B0F210ExtraData();

    unsigned char m_ucType;
    void* m_pkNext;
};

class FUN_0040f210 : public B0F210ExtraData
{
  public:
    virtual ~FUN_0040f210();

    B0F210Data* m_pUserData;
};

// @fnv 0x0040f210
// pdb: ExtraCellImpactSwap::~ExtraCellImpactSwap | ExtraDataCell.obj | debug, object-file run extension, low
FUN_0040f210::~FUN_0040f210()
{
    delete m_pUserData;
}

struct FUN_0040f3a0_node
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    int m_0c;
};

extern int DAT_01183c38;
extern int DAT_01183b2c;
void* FUN_00ec43fb(void* a, int b, void* c, void* d, int e);

struct FUN_0040f3a0_cls
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    int m_0c;

    bool IsDifferentFrom(void* a1);
    bool ExtraCellWaterType_Compare(void* apCompare);
};

// Looks up a node via FUN_00ec43fb and returns true if it is null, IsDifferentFrom succeeds, or the node's m_0c differs from this object's m_0c.
// @fnv 0x0040f3a0
// src: XBOX_PDB 0x0040f3a0
// pdb: ExtraCellWaterType::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool FUN_0040f3a0_cls::ExtraCellWaterType_Compare(void* apCompare)
{
    FUN_0040f3a0_node* p = (FUN_0040f3a0_node*)FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183c38, 0);
    if (p == 0)
    {
        return true;
    }
    if (IsDifferentFrom(apCompare))
    {
        return true;
    }
    if (p->m_0c != m_0c)
    {
        return true;
    }
    return false;
}

struct FUN_0040f500_base
{
    virtual ~FUN_0040f500_base();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0040f500_sub
{
    unsigned int unk00;
    unsigned int unk04;
    void Init(unsigned char flags);
    ~FUN_0040f500_sub();
};

struct FUN_0040f500_cls : FUN_0040f500_base
{
    unsigned int unk0c;
    FUN_0040f500_sub m_10;
    unsigned int unk18;

    virtual ~FUN_0040f500_cls();
};

// Clears unk0c and unk18 and reinitialises m_10 with flags 0.
// @fnv 0x0040f500
// pdb: ExtraCellCanopyShadowMask::~ExtraCellCanopyShadowMask | ExtraDataCell.obj | debug, object-file gap fill, medium
FUN_0040f500_cls::~FUN_0040f500_cls()
{
    unk0c = 0;
    m_10.Init(0);
    unk18 = 0;
}

struct Field_40f
{
    virtual ~Field_40f();
};

struct Base_40f
{
    virtual void v00();
    ~Base_40f();
};

// pdb: class ExtraSeenData, size 0x10, bases: BSExtraData, 1 members
struct ExtraSeenData : Base_40f // src: EXE 0x01014294 (vtable; old: FUN_0040f5f0)
{
    void* pad1;
    void* pad2;
    Field_40f* pSeenData; // src: XBOX_RETAIL_PDB +0xc (old: m_pField)
    virtual void v00();
    ~ExtraSeenData();
};

// Destructor that deletes the owned m_pField object.
// @fnv 0x0040f5f0
// pdb: ExtraSeenData::~ExtraSeenData | ExtraDataCell.obj | debug, object-file gap fill, medium
ExtraSeenData::~ExtraSeenData()
{
    delete pSeenData;
}

class ExtraData40F
{
  public:
    ExtraData40F(unsigned char ucType);
    virtual ~ExtraData40F();

    unsigned char m_ucType;
    ExtraData40F* m_pkNext;
};

class Handle40F
{
  public:
    Handle40F(int iValue);
    ~Handle40F();
    void Reset(void* pvObject);

    void* m_pvObject;
    int unk04;
};

class FUN_0040f440 : public ExtraData40F
{
  public:
    FUN_0040f440(int aeState, void* apTex);
    virtual ~FUN_0040f440();

    int m_iValue;
    Handle40F m_kHandle;
    int m_iArrayLength;
};

// Initializes an ExtraData40F of type 0xa, storing iValue, resetting m_kHandle to pvObject, and zeroing the trailing field.
// @fnv 0x0040f440
// pdb: ExtraCellCanopyShadowMask::ExtraCellCanopyShadowMask | ExtraDataCell.obj | retail, call graph, high
// pdb params: aeState, apTex
FUN_0040f440::FUN_0040f440(int aeState, void* apTex) : ExtraData40F(0xa), m_kHandle(0)
{
    m_iValue = aeState;
    m_kHandle.Reset(apTex);
    m_iArrayLength = 0;
}

struct FUN_0040f5c0
{
    virtual ~FUN_0040f5c0();
};
// @fnv 0x0040f5c0
// pdb: ExtraSeenData::`scalar deleting destructor' | ExtraDataCell.obj | retail, vtable slot, high
FUN_0040f5c0::~FUN_0040f5c0()
{}

extern int DAT_01183b84;

struct ExtraMusicTypeShell : BSExtraData
{
    BGSMusicType* pType;
    bool ExtraCellMusicType_Compare(BSExtraData* apCompare);
};

// Returns true if the cast fails, IsDifferentFrom(extra) is true, or the two pType pointers differ; otherwise false.
// @fnv 0x0040ef60
// src: XBOX_PDB 0x0040ef60
// pdb: ExtraCellMusicType::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool ExtraMusicTypeShell::ExtraCellMusicType_Compare(BSExtraData* apCompare)
{
    ExtraMusicTypeShell* pOther =
        static_cast<ExtraMusicTypeShell*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183b84, 0));
    if (!pOther)
        return true;
    if (reinterpret_cast<FUN_0040f3a0_cls*>(this)->IsDifferentFrom(apCompare))
        return true;
    if (pOther->pType != pType)
        return true;
    return false;
}

extern int DAT_01183ba8;
// Compares this ExtraCellAcousticSpace against apCompare, returning true if the cast target is null, the base differs, or the acoustic space pointer differs.
// @fnv 0x0040f000
// pdb: ExtraCellAcousticSpace::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool ExtraCellAcousticSpace::Compare(BSExtraData* apCompare)
{
    ExtraCellAcousticSpace* pComp =
        static_cast<ExtraCellAcousticSpace*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183ba8, 0));
    if (!pComp)
        return true;
    if (BSExtraData::Compare(apCompare))
        return true;
    if (pComp->pSpace != pSpace)
        return true;
    return false;
}

extern int DAT_01183bd0;
struct FUN_0040f0a0_shell : BSExtraData
{
    void* pField;
    bool IsDifferentFrom(BSExtraData*);
    bool ExtraCellClimate_Compare(BSExtraData* apCompare);
};
// Returns true if the cast fails, IsDifferentFrom(extra) returns true, or the pField pointers differ; otherwise false.
// @fnv 0x0040f0a0
// src: XBOX_PDB 0x0040f0a0
// pdb: ExtraCellClimate::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool FUN_0040f0a0_shell::ExtraCellClimate_Compare(BSExtraData* apCompare)
{
    FUN_0040f0a0_shell* cast = (FUN_0040f0a0_shell*)FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183bd0, 0);
    if (!cast)
        return true;
    if (IsDifferentFrom(apCompare))
        return true;
    if (cast->pField != pField)
        return true;
    return false;
}

extern int DAT_01183c14;

struct CellImpactSwapValue
{
    bool ImpactSwap_Compare(CellImpactSwapValue*);
};

struct CellImpactCompare : BSExtraData
{
    CellImpactSwapValue* m_pCellImpactSwapValue;

    bool ExtraCellImpactSwap_Compare(BSExtraData* apCompare);
};

// Returns true if the cast fails, IsDifferentFrom(apCompare) is true, or the payload comparison returns true.
// @fnv 0x0040f2d0
// src: XBOX_PDB 0x0040f2d0
// pdb: ExtraCellImpactSwap::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool CellImpactCompare::ExtraCellImpactSwap_Compare(BSExtraData* apCompare)
{
    CellImpactCompare* pComp;

    pComp = static_cast<CellImpactCompare*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183c14, 0));

    if (!pComp)
        return true;

    if (reinterpret_cast<FUN_0040f3a0_cls*>(this)->IsDifferentFrom(apCompare))
        return true;

    if (pComp->m_pCellImpactSwapValue && this->m_pCellImpactSwapValue)
    {
        if (pComp->m_pCellImpactSwapValue->ImpactSwap_Compare(this->m_pCellImpactSwapValue))
            return true;
    }
    else if (pComp->m_pCellImpactSwapValue || this->m_pCellImpactSwapValue)
    {
        return true;
    }

    return false;
}

extern int DAT_01183bf0;

// Returns true if the cast fails, FUN_0040f700(extra) returns true, or the image-space pointers differ; otherwise false.
// @fnv 0x0040f140
// pdb: ExtraCellImageSpace::Compare | ExtraDataCell.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pComp
bool ExtraCellImageSpace::Compare(BSExtraData* apCompare)
{
    ExtraCellImageSpace* cast =
        static_cast<ExtraCellImageSpace*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183bf0, 0));
    if (!cast)
        return true;
    if (IsDifferentFrom(apCompare))
        return true;
    if (cast->pImageSpace != pImageSpace)
        return true;
    return false;
}
