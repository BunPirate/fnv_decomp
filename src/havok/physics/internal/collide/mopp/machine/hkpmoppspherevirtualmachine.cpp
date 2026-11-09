
// src/havok/physics/internal/collide/mopp/machine/hkpmoppspherevirtualmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/machine/hkpmoppspherevirtualmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/HitArray.h"
#include "../../../../../../../include/MemoryManager.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), as in the other mopp machine units
extern "C" void __debugbreak();
struct MoppState { int axis[3]; int radius; int origin[3]; int offset; int shift; int properties[1]; };
MemoryManager* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*,HitArray*,int);
extern unsigned char DAT_0126efbb;
void __cdecl ValidateHavokKeyCode(unsigned char*);
struct FmtObj {
    int unk00, unk04, unk08;
    void FUN_00cb1600(char* buf, int bufSize);
    void ProcessAndReturnValue_00cc01c0(void* s);
    void FUN_00cc00e0();
};
struct Reporter {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual int Report(int a, unsigned int b, char* c, void* d, int e);
};
extern Reporter* DAT_01268360;

__forceinline void reportCorruption() {
    unsigned int buffer[128];
    FmtObj stream;
    stream.FUN_00cb1600(reinterpret_cast<char*>(buffer), sizeof(buffer));
    stream.ProcessAndReturnValue_00cc01c0("Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
    if (DAT_01268360->Report(3, 0x1298feddu, reinterpret_cast<char*>(buffer), ".\\Collide\\Mopp\\Machine\\hkpMoppSphereVirtualMachine.cpp", 292))
        __debugbreak();
    stream.FUN_00cc00e0();
}
struct MoppMachine { HitArray* hits; int unk04,unk08,unk0c; int axis[3]; int radius; void hkpMoppSphereVirtualMachine_querySphereOnTree(MoppState*, const unsigned char*); };
// @fnv 0x00e64870
// src: HAVOK_LIB 0x00e64870
// pdb: hkpMoppSphereVirtualMachine::querySphereOnTree | hkpMoppSphereVirtualMachine.obj | retail, upstream name already matches, high
// pdb params: query, PC
// pdb locals: scaledQuery, assertBuf, ostr
void MoppMachine::hkpMoppSphereVirtualMachine_querySphereOnTree(MoppState* query, const unsigned char* PC) {
    MoppState local;
    if (!DAT_0126efbb) { ValidateHavokKeyCode(&DAT_0126efbb); if (!DAT_0126efbb) return; }
    int hit = 0;
    for (;;) {
        unsigned command = *PC;
        int low, high, position, r;
        switch(command) {
        case 0: return;
        case 19:
            low = 2 * PC[1]; high = 2 * PC[2];
            position = query->axis[2] + query->axis[1];
            r = query->radius + (query->radius >> 1) + 1;
            goto test_interval;
        case 20:
            // Preserve the compiler's shared subtraction and radius tails.
            try {
                position = query->axis[1];
                low = 2 * PC[1]; high = 2 * PC[2];
                position -= query->axis[2];
                position += 255;
                r = query->radius + (query->radius >> 1) + 1;
            } catch (...) { throw; }
            goto test_interval;
        case 21:
            low = 2 * PC[1]; high = 2 * PC[2];
            position = query->axis[2] + query->axis[0];
            r = query->radius + (query->radius >> 1) + 1;
            goto test_interval;
        case 22:
            position = query->axis[0];
            low = 2 * PC[1]; high = 2 * PC[2];
            position -= query->axis[2];
            position += 255;
            r = query->radius + (query->radius >> 1) + 1;
            goto test_interval;
        case 23:
            low = 2 * PC[1]; high = 2 * PC[2];
            position = query->axis[1] + query->axis[0];
            r = query->radius + (query->radius >> 1) + 1;
            goto test_interval;
        case 24:
            low = 2 * PC[1]; high = 2 * PC[2];
            position = query->axis[0] - query->axis[1];
            position += 255;
            r = query->radius + (query->radius >> 1) + 1;
            goto test_interval;
        case 25:
            position = query->axis[2] + query->axis[1];
            low = 3 * PC[1]; high = 3 * PC[2];
            position += query->axis[0];
            r = 4 * query->radius;
            goto test_interval;
        case 26:
            low = 3 * PC[1]; high = 3 * PC[2];
            position = query->axis[1] - query->axis[2];
            position += query->axis[0] + 255;
            r = 4 * query->radius;
            goto test_interval;
        case 27:
            low = 3 * PC[1]; high = 3 * PC[2];
            position = query->axis[2] - query->axis[1];
            position += query->axis[0] + 255;
            r = 4 * query->radius;
            goto test_interval;
        case 28:
            position = query->axis[0] - query->axis[2] - query->axis[1] + 510;
            low = 3 * PC[1]; high = 3 * PC[2];
            r = 4 * query->radius;
            goto test_interval;
        case 16: case 17: case 18: low=PC[1];high=PC[2];position=query->axis[command-16];r=query->radius;
        test_interval: {
            PC+=4; if(position+r<high) break; int skip=PC[-1]; PC+=skip; if(position>r+low) break;
            hkpMoppSphereVirtualMachine_querySphereOnTree(query,PC-skip); break;
        }
        case 32: case 33: case 34: {
            int low = PC[1];
            int r = query->radius;
            position = query->axis[command - 32];
            PC += 3;
            if (position + r < low) break;
            int skip = PC[-1];
            PC += skip;
            if (position > r + low + 1) break;
            hkpMoppSphereVirtualMachine_querySphereOnTree(query, PC - skip);
            break;
        }
        case 35: case 36: case 37: {
            int low = PC[1];
            int high = PC[2];
            int position = query->axis[command - 35];
            int r = query->radius;
            int skip1 = (PC[3] << 8) + PC[4];
            PC += 7;
            if (position + r < high) {
                PC += skip1;
                break;
            }
            int skip2 = (PC[-2] << 8) + PC[-1];
            PC += skip2;
            if (position > r + low)
                break;
            hkpMoppSphereVirtualMachine_querySphereOnTree(query, PC + (skip1 - skip2));
            break;
        }
        case 38: case 39: case 40: {
            int position=query->axis[command-38];int r=query->radius;
            if(position+r<PC[1] || position>r+PC[2]) return;
            PC+=3;break;
        }
        case 41: case 42: case 43: {
            int position=axis[command-41];int r=radius;
            int low=((PC[1]<<8)+PC[2])*256+PC[3];
            if(position+r<low) return;
            int high=((PC[4]<<8)+PC[5])*256+PC[6];
            if(position>r+high) return;
            PC+=7;break;
        }
        case 5: PC+=PC[1]+2; break;
        case 6: PC+= (PC[1]<<8)+PC[2]+3; break;
        case 7: PC+= ((PC[1]<<8)+PC[2])*256+PC[3]+4; break;
        case 1: case 2: case 3: case 4: {
            int shift=query->shift-command;
            local.shift=shift;
            local.origin[0]=(query->origin[0]+PC[1])<<command; local.axis[0]=(axis[0]>>shift)-local.origin[0];
            local.origin[1]=(query->origin[1]+PC[2])<<command; local.axis[1]=(axis[1]>>shift)-local.origin[1];
            local.origin[2]=(query->origin[2]+PC[3])<<command; local.axis[2]=(axis[2]>>shift)-local.origin[2];
            local.radius=(radius>>shift)+1;
            local.offset=query->offset; local.properties[0]=query->properties[0];
            query=&local; PC+=4; break;
        }
        case 9: { int value=PC[1]; if(query!=&local) {local=*query;query=&local;} local.offset += value; PC+=2; break; }
        case 10: { int value=(PC[1]<<8)+PC[2]; if(query!=&local) {local=*query;query=&local;} local.offset += value; PC+=3; break; }
        case 11: { int value=(((PC[1]<<8)+PC[2])*256+PC[3])*256+PC[4]; if(query!=&local) {local=*query;query=&local;} local.offset = value; PC+=5; break; }
        case 96:
        case 97:
        case 98:
        case 99: {
            int value = PC[1];
            PC += 2;
            local.properties[command - 96] = value;
            goto update_property;
        }
        case 100:
        case 101:
        case 102:
        case 103:
            local.properties[command - 100] = (PC[1] << 8) + PC[2];
            PC += 3;
            goto update_property;
        case 104:
        case 105:
        case 106:
        case 107:
            local.properties[command - 104] = (((((PC[1] << 8) + PC[2]) << 8) + PC[3]) << 8) + PC[4];
            PC += 5;
        update_property: {
            int saved = local.properties[0];
            if (query != &local) {
                local = *query;
                query = &local;
            }
            local.properties[0] = saved;
            break;
        }
        default: { reportCorruption(); break; }
        case 80: hit = PC[1]; goto add_hit;
        case 81: hit = (PC[1] << 8) + PC[2]; goto add_hit;
        case 82: hit = (((PC[1] << 8) + PC[2]) << 8) + PC[3]; goto add_hit;
        case 83: hit = (((((PC[1] << 8) + PC[2]) << 8) + PC[3]) << 8) + PC[4]; goto add_hit;
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
            hit=command-48;
        add_hit: {
            hit+=query->offset;
            HitArray* output=hits;
            MemoryManager* manager=hkMemoryRouter_getInstance();
            if(output->size==(output->capacity&0x3fffffff)) ResizeAudioStream(manager->allocator,output,4);
            int* p = &reinterpret_cast<int*>(output->data)[output->size++];
            *p = hit;
            return;
        }
        }
    }
}

struct xMoppCode { int unk00, unk04, unk08, unk0c; float offset[3]; float scale; const unsigned char* data; };
struct xSphere { float pos[3]; float radius; };

struct xSphereMachine : MoppMachine {
    void hkpMoppSphereVirtualMachine_querySphere(const xMoppCode* code, const xSphere& sphere, HitArray* primitiveResults);
};

// @fnv 0x00e64f00
// src: HAVOK_LIB 0x00e64f00
// pdb: hkpMoppSphereVirtualMachine::querySphere | hkpMoppSphereVirtualMachine.obj | retail, upstream name already matches, high
// pdb params: code, sphere, primitiveResults
// pdb locals: query
void xSphereMachine::hkpMoppSphereVirtualMachine_querySphere(const xMoppCode* code, const xSphere& sphere, HitArray* primitiveResults)
{
    const unsigned char* program = code->data;
    hits = primitiveResults;
    axis[0] = fnv_FloatToInt((sphere.pos[0] - code->offset[0]) * code->scale) - 1;
    axis[1] = fnv_FloatToInt((sphere.pos[1] - code->offset[1]) * code->scale) - 1;
    axis[2] = fnv_FloatToInt((sphere.pos[2] - code->offset[2]) * code->scale) - 1;
    radius = fnv_FloatToInt(sphere.radius * code->scale) + 2;

    MoppState state;
    state.axis[0] = axis[0] >> 16;
    state.axis[1] = axis[1] >> 16;
    state.axis[2] = axis[2] >> 16;
    state.radius = (radius >> 16) + 1;
    state.origin[0] = 0;
    state.origin[1] = 0;
    state.origin[2] = 0;
    state.offset = 0;
    state.shift = 16;
    state.properties[0] = 0;
    hkpMoppSphereVirtualMachine_querySphereOnTree(&state, program);
}
