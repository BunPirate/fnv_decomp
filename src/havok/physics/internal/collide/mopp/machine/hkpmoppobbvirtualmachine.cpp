
// src/havok/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppobbvirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/HitArray.h"

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct GridSource {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float f10;
    float f14;
    float f18;
    float f1c;
    unsigned char* p20;
};

struct GridBounds {
    float f00;
    float f04;
    float f08;
    float unk0c;
    float f10;
    float f14;
    float f18;
};

struct __declspec(align(16)) GridScratch {
    int f00;
    int f04;
    int f08;
    int unk0c;
    int f10;
    int f14;
    int f18;
    int unk1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
};

// pdb: structure GridCell, size 0x4 (here 0x38), 1 members
struct GridCell {
    int m00;
    int unk04;
    int unk08;
    int unk0c;
    union {
        int m10;
        struct {
            short unk10;
            short m12;
        };
    };
    union {
        int m14;
        struct {
            short unk14;
            short m16;
        };
    };
    int m18;
    int unk1c;
    union {
        int m20;
        struct {
            short unk20;
            short m22;
        };
    };
    union {
        int m24;
        struct {
            short unk24;
            short m26;
        };
    };
    union {
        int m28;
        struct {
            short unk28;
            short m2a;
        };
    };
    int unk2c;
    void* m30;
    int m34;

    void hkpMoppObbVirtualMachine_queryAabb(GridSource* code, GridBounds* aabb, int primitives_out);
    void hkpMoppObbVirtualMachine_queryAabbOnTree(GridScratch* query, unsigned char* PC, int chunkOffset);
};

// @fnv 0x00dd1da0
// src: HAVOK_LIB 0x00dd1da0
// pdb: hkpMoppObbVirtualMachine::queryAabb | hkpMoppObbVirtualMachine.obj | retail, upstream name already matches, high
// pdb params: code, aabb, primitives_out
// pdb locals: query
void GridCell::hkpMoppObbVirtualMachine_queryAabb(GridSource* code, GridBounds* aabb, int primitives_out) {
    m30 = code;
    m00 = primitives_out;
    float s = code->f1c;
    float p10 = code->f10;
    m20 = fnv_FloatToInt((aabb->f00 - p10) * s) - 1;
    m10 = fnv_FloatToInt((aabb->f10 - p10) * s) + 1;
    float p14 = code->f14;
    m24 = fnv_FloatToInt((aabb->f04 - p14) * s) - 1;
    m14 = fnv_FloatToInt((aabb->f14 - p14) * s) + 1;
    float p18 = code->f18;
    m28 = fnv_FloatToInt((aabb->f08 - p18) * s) - 1;
    m18 = fnv_FloatToInt((aabb->f18 - p18) * s) + 1;

    GridScratch loc;
    loc.f10 = m22;
    loc.f00 = m12 + 1;
    loc.f14 = m26;
    loc.f04 = m16 + 1;
    loc.f18 = m2a;
    loc.f08 = (m18 >> 16) + 1;
    loc.f20 = 0;
    loc.f24 = 0;
    loc.f28 = 0;
    loc.f2c = 0;
    loc.f30 = 0;
    loc.f34 = 0;

    unsigned char* p = code->p20;
    m34 = ((*p != 0xd) ? 1 : 0) - 1;
    hkpMoppObbVirtualMachine_queryAabbOnTree(&loc, p, 0);
}

extern "C" void _ReadWriteBarrier();
extern "C" void __debugbreak();
struct __declspec(align(16)) QueryState {
 union {int lower[4]; struct {int f00;int f04;int f08;int unk0c;};};
 union {int upper[4]; struct {int f10;int f14;int f18;int unk1c;};};
 union {int origin[3]; struct {int f20;int f24;int f28;};};
 union {unsigned primitiveOffset;unsigned f2c;};
 union {int shift;int f30;};
 union {unsigned properties[1];unsigned f34;};
};
struct CodeData {
 int unk00;int unk04;int unk08;int unk0c;
 float f10;float f14;float f18;float f1c;
 union {unsigned char* code;unsigned char* p20;};
};
struct AllocatorContext { int field00, field04, field08, field0c; void* allocator; };
extern AllocatorContext* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(void*, void*, int);
extern unsigned char DAT_01269cbc;
extern void __cdecl ValidateHavokKeyCode(unsigned char*);
struct ErrorText { char* data; int length; int capacity; void FUN_00cb1600(char*,int); void ProcessAndReturnValue_00cc01c0(const char*); void FUN_00cc00e0(); };
struct ErrorReporter { virtual void ReportDiagnostic(); virtual void unused1(); virtual void unused2(); virtual int report(int,unsigned,const char*,const char*,int); };
extern ErrorReporter* DAT_01268360;
struct VirtualMachine {
 union {int m00;HitArray* hits;};
 int unk04;int unk08;int unk0c;
 union {int lower[4];struct {
 union {int m10;struct {short unk10;short m12;};};
 union {int m14;struct {short unk14;short m16;};};
 int m18;int unk1c;
 };};
 union {int upper[4];struct {
 union {int m20;struct {short unk20;short m22;};};
 union {int m24;struct {short unk24;short m26;};};
 union {int m28;struct {short unk28;short m2a;};};
 int unk2c;
 };};
 union {CodeData* data;void* m30;};
 union {int primitiveMask;int m34;};
 void hkpMoppObbVirtualMachine_queryAabbOnTree(const QueryState*,unsigned char*,int);
 __forceinline void AddHit(int value) {
  HitArray* out=hits;AllocatorContext* context=hkMemoryRouter_getInstance();
  if(out->size==(out->capacity&0x3fffffff)) ResizeAudioStream(context->allocator,out,4);
  int* destination=&reinterpret_cast<int*>(out->data)[out->size]; ++out->size; *destination=value; }
};
// Executes a MOPP BVH tree traversal from a QueryState, recursing on diagonal and axial branches, and emits a hit via AddHit on a leaf.
// @fnv 0x00dd1400
// src: XBOX_RETAIL_PDB 0x00dd1400
// pdb: hkpMoppObbVirtualMachine::queryAabbOnTree | hkpMoppObbVirtualMachine.obj | retail, string-set bridge, high
// pdb params: query, PC, chunkOffset
// pdb locals: scaledQuery, assertBuf, ostr
void VirtualMachine::hkpMoppObbVirtualMachine_queryAabbOnTree(const QueryState* query,unsigned char* __restrict PC,int chunkOffset) {
    int by;(void)by;
    QueryState localQueryState;
    if (!DAT_01269cbc) {
        ValidateHavokKeyCode(&DAT_01269cbc);
        if (!DAT_01269cbc) return;
    }
    for (;;) {
        unsigned op=*PC;
        int high,low,left,right,length;
        int term;
        switch(op) {
        case 0: return;
        case 0x13: left=PC[1]*2;right=PC[2]*2;high=query->upper[1]+query->upper[2];low=query->lower[1]+query->lower[2];goto diagonal;
        case 0x14: left=PC[1]*2-255;right=PC[2]*2-255;high=query->upper[1]-query->lower[2];low=query->lower[1]-query->upper[2];goto diagonal;
        case 0x15: left=PC[1]*2;right=PC[2]*2;high=query->upper[0]+query->upper[2];low=query->lower[0]+query->lower[2];goto diagonal;
        case 0x16: left=PC[1]*2-255;right=PC[2]*2-255;high=query->upper[0]-query->lower[2];low=query->lower[0]-query->upper[2];goto diagonal;
        case 0x17: left=PC[1]*2;right=PC[2]*2;high=query->upper[0]+query->upper[1];low=query->lower[0]+query->lower[1];goto diagonal;
        case 0x18: left=PC[1]*2-255;right=PC[2]*2-255;high=query->upper[0]-query->lower[1];low=query->lower[0]-query->upper[1];goto diagonal;
        case 0x19: left=PC[1]*3;right=PC[2]*3;high=query->upper[2]+query->upper[1]+query->upper[0];low=query->lower[2]+query->lower[1]+query->lower[0];goto diagonal;
        case 0x1a: left=(PC[1]-85)*3;right=(PC[2]-85)*3;high=query->upper[1]-query->lower[2]+query->upper[0];low=query->lower[1]-query->upper[2]+query->lower[0];goto diagonal;
        case 0x1b: left=(PC[1]-85)*3;right=(PC[2]-85)*3;high=query->upper[2]-query->lower[1]+query->upper[0];low=query->lower[2]-query->upper[1]+query->lower[0];goto diagonal;
        case 0x1c: left=(PC[1]-170)*3;right=(PC[2]-170)*3;high=query->upper[0]-query->lower[2]-query->lower[1];low=query->lower[0]-query->upper[2]-query->upper[1];
        diagonal:
            PC+=4;
            if(low<=right) {if(high<left) break;return;}
            length=PC[-1];
            if(high>=left) {PC+=length;break;}
            hkpMoppObbVirtualMachine_queryAabbOnTree(query,PC,chunkOffset);
            PC+=length;break;
        case 0x10:case 0x11:case 0x12:
            left=PC[1];right=PC[2];high=query->upper[op-0x10];PC+=4;
            if(query->lower[op-0x10]<=right) {if(high<left) break;return;}
            length=PC[-1]; PC+=length;
            if(high<left) goto recurseAxial;
            break;
        case 0x20:case 0x21:case 0x22:
            right=PC[1];PC+=3;
            if(query->lower[op-0x20]<=right) break;
            length=PC[-1];PC+=length;
            if(query->upper[op-0x20]>right) break;
        recurseAxial: hkpMoppObbVirtualMachine_queryAabbOnTree(query,PC-length,chunkOffset);
            break;
        case 0x23:case 0x24:case 0x25:
            left=PC[1];right=PC[2];high=query->upper[op-0x23];length=(PC[3]<<8)+PC[4];PC+=7;
            if(query->lower[op-0x23]<=right) {if(high>=left)return;PC+=length;break;}
            {int other=(PC[-2]<<8)+PC[-1];PC+=other;
            if(high<left) hkpMoppObbVirtualMachine_queryAabbOnTree(query,PC+length-other,chunkOffset);}
            break;
        case 0x26:case 0x27:case 0x28:
            if(query->lower[op-0x26]<PC[1])return;
            if(query->upper[op-0x26]>=PC[2])return;
            PC+=3;break;
        case 0x29:case 0x2a:case 0x2b:
            left=(((PC[1]<<8)+PC[2])<<8)+PC[3];
            if(lower[op-0x29]<left)return;
            right=(((PC[4]<<8)+PC[5])<<8)+PC[6];
            if(upper[op-0x29]>right)return;
            PC+=7;break;
        case 5: PC+=2; length=PC[-1];PC+=length; break;
        case 6: {int a=PC[1];int b=PC[2];PC+=3;a<<=8;a+=b;PC+=a;break;}
        case 7: {int a=PC[1];int b=PC[2];int c=PC[3];PC+=4;a<<=8;a+=b;a<<=8;a+=c;PC+=a;break;}
        case 12:
            chunkOffset=((PC[1]<<8)|PC[2])<<9;goto changePage;
        case 0x70:
            chunkOffset=(((((PC[1]<<8)+PC[2])<<8)+PC[3])<<8)+PC[4];
        changePage: PC=data->code+chunkOffset;break;
        case 1: case 2: case 3: case 4:
            {volatile QueryState& q=localQueryState;
            q.origin[0]=(PC[1]+query->origin[0])<<op;
            q.origin[1]=(PC[2]+query->origin[1])<<op;
            q.origin[2]=(PC[3]+query->origin[2])<<op;
            q.shift=query->shift+op;
            int inverseShift=16-localQueryState.shift;
            q.upper[0]=(upper[0]>>inverseShift)-q.origin[0];
            q.upper[1]=(upper[1]>>inverseShift)-q.origin[1];
            q.upper[2]=(upper[2]>>inverseShift)-q.origin[2];
            q.lower[0]=(lower[0]>>inverseShift)-q.origin[0]+1;
            int iOriginY=q.origin[1];by=((volatile int&)lower[1])>>inverseShift;q.lower[1]=by-iOriginY+1;
            q.lower[2]=(lower[2]>>inverseShift)-q.origin[2]+1;
            q.properties[0]=query->properties[0];
            q.primitiveOffset=query->primitiveOffset;
            query=&localQueryState; PC+=4; break;}
        case 9:
            length=PC[1]; if(query!=&localQueryState) {localQueryState=*query;query=&localQueryState;}
            localQueryState.primitiveOffset+=length;PC+=2;break;
        case 10:
            length=(PC[1]<<8)+PC[2]; if(query!=&localQueryState) {localQueryState=*query;query=&localQueryState;}
            localQueryState.primitiveOffset+=length;PC+=3;break;
        case 11:
            length=((((PC[1]<<8)+PC[2])<<8)+PC[3]<<8)+PC[4];
            if(query!=&localQueryState) {localQueryState=*query;query=&localQueryState;}
            localQueryState.primitiveOffset=length;PC+=5;break;
        case 13: PC+=5;break;
        case 0x60:case 0x61:case 0x62:case 0x63:
            {int propertyValue=PC[1];PC+=2;localQueryState.properties[op-0x60]=propertyValue;}goto property;
        case 0x64:case 0x65:case 0x66:case 0x67:
            {int propertyValue=(PC[1]<<8)+PC[2];localQueryState.properties[op-0x64]=propertyValue;PC+=3;}goto property;
        case 0x68:case 0x69:case 0x6a:case 0x6b:
            {int propertyValue=(((((PC[1]<<8)+PC[2])<<8)+PC[3])<<8)+PC[4];localQueryState.properties[op-0x68]=propertyValue;PC+=5;}
        property:
            {int value=localQueryState.properties[0];if(query!=&localQueryState){localQueryState=*query;query=&localQueryState;}localQueryState.properties[0]=value;}break;
        case 0x50: term=PC[1];goto emit;
        case 0x51: term=(PC[1]<<8)+PC[2];goto emit;
        case 0x52: term=(((PC[1]<<8)+PC[2])<<8)+PC[3];goto emit;
        case 0x53: term=(((((PC[1]<<8)+PC[2])<<8)+PC[3])<<8)+PC[4];goto emit;
        case 0x30:case 0x31:case 0x32:case 0x33:case 0x34:case 0x35:case 0x36:case 0x37:case 0x38:case 0x39:case 0x3a:case 0x3b:case 0x3c:case 0x3d:case 0x3e:case 0x3f:case 0x40:case 0x41:case 0x42:case 0x43:case 0x44:case 0x45:case 0x46:case 0x47:case 0x48:case 0x49:case 0x4a:case 0x4b:case 0x4c:case 0x4d:case 0x4e:case 0x4f:
            term=op-0x30;goto emit;
        default:
        badCommand:
            {unsigned int errorBuffer[128];ErrorText errorText;errorText.FUN_00cb1600(reinterpret_cast<char*>(errorBuffer),512);
            errorText.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            if(DAT_01268360->report(3,0x1298fedd,reinterpret_cast<char*>(errorBuffer),".\\Collide\\Mopp\\Machine\\hkpMoppObbVirtualMachine.cpp",459)) __debugbreak();
            errorText.FUN_00cc00e0();}break;
        emit:
            {unsigned key=query->primitiveOffset+term; unsigned value=((((unsigned)(chunkOffset>>9))<<8)&primitiveMask)|key;
            AddHit(value);return;}
        }
    }
}
