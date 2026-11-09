
#include "nimatrix3_decls.h"

// @fnv 0x00476930
// pdb: NiMatrix3::GetRow | BGSDestructibleObjectForm.obj | debug, call graph, medium
// pdb params: uiRow, row
void NiMatrix3::GetRow(unsigned int row, NiPoint3& point) const
{
    point.x = *(float*)((char*)m_pEntry + row * 12);
    point.y = *(float*)((char*)m_pEntry + row * 12 + 4);
    point.z = *(float*)((char*)m_pEntry + row * 12 + 8);
}

// @fnv 0x004D9AE0
// pdb: NiMatrix3::operator== | RagDollData.obj | debug, call graph, medium
// pdb params: mat
bool NiMatrix3::operator==(const NiMatrix3& matrix) const
{
    return m_pEntry[0][0] == matrix.m_pEntry[0][0]
        && m_pEntry[0][1] == matrix.m_pEntry[0][1]
        && m_pEntry[0][2] == matrix.m_pEntry[0][2]
        && m_pEntry[1][0] == matrix.m_pEntry[1][0]
        && m_pEntry[1][1] == matrix.m_pEntry[1][1]
        && m_pEntry[1][2] == matrix.m_pEntry[1][2]
        && m_pEntry[2][0] == matrix.m_pEntry[2][0]
        && m_pEntry[2][1] == matrix.m_pEntry[2][1]
        && m_pEntry[2][2] == matrix.m_pEntry[2][2];
}

// Product this * kRhs, filled column by column as the exe stores it; NIM3_ROWCOL(r, c) is row r of this dotted
// with column c of kRhs, summed left to right.
#define NIM3_ROWCOL(r, c) \
    m_pEntry[r][0] * kRhs.m_pEntry[0][c] + m_pEntry[r][1] * kRhs.m_pEntry[1][c] + m_pEntry[r][2] * kRhs.m_pEntry[2][c]
// @fnv 0x0043F8D0
// pdb: NiMatrix3::operator* | ModelLoader.obj | debug, call graph, medium
// pdb params: mat
// pdb locals: vfResult12, vfResult01, kTemp, vfResult11, vfResult10And30, vfResult01And21, vfResult12And32, vfResult20, vfResult00And20, kThisTranspose, vfResult11And31, vfResult10, vfResult21, prd, vfResult00, vfResult02, vfResult22, vfResult02And22
NiMatrix3 NiMatrix3::operator*(const NiMatrix3& kRhs) const
{
    NiMatrix3 kOut;
    kOut.m_pEntry[0][0] = NIM3_ROWCOL(0, 0);
    kOut.m_pEntry[1][0] = NIM3_ROWCOL(1, 0);
    kOut.m_pEntry[2][0] = NIM3_ROWCOL(2, 0);
    kOut.m_pEntry[0][1] = NIM3_ROWCOL(0, 1);
    kOut.m_pEntry[1][1] = NIM3_ROWCOL(1, 1);
    kOut.m_pEntry[2][1] = NIM3_ROWCOL(2, 1);
    kOut.m_pEntry[0][2] = NIM3_ROWCOL(0, 2);
    kOut.m_pEntry[1][2] = NIM3_ROWCOL(1, 2);
    kOut.m_pEntry[2][2] = NIM3_ROWCOL(2, 2);
    return kOut;
}
#undef NIM3_ROWCOL

#pragma optimize("gty", on)
// @fnv 0x00A69970
// pdb: NiPlane::NiPlane | NiPlane.obj | debug, object-file gap fill, low
// pdb params: kNormal, fConstant
NiPlane::NiPlane(const NiPoint3& n,float constant) { *reinterpret_cast<NiPoint3*>(&m_kNormal) = n; m_fConstant = constant; }

#pragma optimize("", off)

// @fnv 0x006404B0
// pdb: NiAVObject::SetRotate | Stars.obj | debug, call graph, high
// pdb params: fAngle, x, y, z
void NiAVObject::SetLocalRotation(float fAngle,float x,float y,float z) { m_kLocal.m_Rotate.MakeRotation(fAngle,x,y,z); }

// @fnv 0x0045BBA0
// pdb: NiCamera::GetWorldDirection | TES.obj | debug, call graph (shared callers), medium
// pdb locals: kDVector
NiPoint3 NiAVObject::GetWorldTranslation() {
 NiPoint3 result;

 m_kWorld.m_Rotate.GetCol(0,result);
 return result;
}

// @fnv 0x004768C0
// pdb: NiMatrix3::Transpose | BGSDestructibleObjectForm.obj | debug, upstream name already matches, high
// pdb locals: row
NiMatrix3 NiMatrix3::Transpose() const {
 NiPoint3 rows[3];
 GetRow(0,rows[0]); GetRow(1,rows[1]); GetRow(2,rows[2]);
 return NiMatrix3(rows[0],rows[1],rows[2]);
}

// @fnv 0x0043F850
// pdb: NiMatrix3::MakeYRotation | ModelLoader.obj | retail, upstream name already matches, high
// pdb params: fAngle
// pdb locals: cs, sn
void NiMatrix3::MakeYRotation(float fAngle) {
 float s,c;
 NiSinCos_004169a0(fAngle,s,c);
 m_pEntry[0][0]=c; m_pEntry[0][1]=0.0f; m_pEntry[0][2]=-s;
 m_pEntry[1][0]=0.0f; m_pEntry[1][1]=1.0f; m_pEntry[1][2]=0.0f;
 m_pEntry[2][0]=s; m_pEntry[2][1]=0.0f; m_pEntry[2][2]=c;
}

// @fnv 0x0062C250
// pdb: NiTransform::operator* | TEShavokUtilities.obj | retail, call graph, low
// pdb note: debug build links it to XMStoreFloat3A
// pdb params: xform
// pdb locals: vfResult12, vScale, vfResult01, kTemp, vfResult11, vfResult10And30, vfResult01And21, vfResult12And32, vReturn, vfResult20, vfResult00And20, kThisTranspose, vfResult11And31, vPtX, vResult, vfResult10, vfResult21, vfResult00, vPtY, vThisTrans, res, vfResult02, vfResult22, vfResult02And22 ...
NiTransform NiTransform::operator*(const NiTransform& other) const {
 NiTransform result;
 result.m_fScale=m_fScale*other.m_fScale;
 result.m_Rotate=m_Rotate*other.m_Rotate;
 result.m_Translate=m_Translate+NiPosData::ComputePositionAtTime(m_fScale,m_Rotate*other.m_Translate);
 return result;
}

// @fnv 0x004168A0
// pdb: NiMatrix3::MakeRotation | ExtraDataList.obj | retail, upstream name already matches, high
// pdb params: fAngle, x, y, z
// pdb locals: omcs, xym, ysin, xzm, zsin, z2, yzm, xsin, cs, sn, x2, y2
void NiMatrix3::MakeRotation(float fAngle,float x,float y,float z) {
 struct {float omc,xy,ys,xz,zs,z2,yz,xs,c,s,x2,y2;} v;
 NiSinCos_004169a0(fAngle,v.s,v.c);
 v.omc=1.0f-v.c;
 v.x2=x*x; v.y2=y*y; v.z2=z*z;
 v.xy=x*y*v.omc; v.xz=x*z*v.omc; v.yz=y*z*v.omc;
 v.xs=x*v.s; v.ys=y*v.s; v.zs=z*v.s;
 m_pEntry[0][0]=v.x2*v.omc+v.c;
 m_pEntry[0][1]=v.xy+v.zs; m_pEntry[0][2]=v.xz-v.ys;
 m_pEntry[1][0]=v.xy-v.zs; m_pEntry[1][1]=v.y2*v.omc+v.c; m_pEntry[1][2]=v.yz+v.xs;
 m_pEntry[2][0]=v.xz+v.ys; m_pEntry[2][1]=v.yz-v.xs; m_pEntry[2][2]=v.z2*v.omc+v.c;
}

// @fnv 0x004B46A0
// pdb: NiMatrix3::Inverse | GlobalFunc.obj | debug, call graph, medium
// pdb params: inv
// pdb locals: fDet, fInvdet, col
bool NiMatrix3::Inverse(NiMatrix3& out) const {
 struct { int col,row; float det,inv; } v;
 out.m_pEntry[0][0]=m_pEntry[1][1]*m_pEntry[2][2]-m_pEntry[1][2]*m_pEntry[2][1];
 out.m_pEntry[0][1]=m_pEntry[0][2]*m_pEntry[2][1]-m_pEntry[0][1]*m_pEntry[2][2];
 out.m_pEntry[0][2]=m_pEntry[0][1]*m_pEntry[1][2]-m_pEntry[0][2]*m_pEntry[1][1];
 out.m_pEntry[1][0]=m_pEntry[1][2]*m_pEntry[2][0]-m_pEntry[1][0]*m_pEntry[2][2];
 out.m_pEntry[1][1]=m_pEntry[0][0]*m_pEntry[2][2]-m_pEntry[0][2]*m_pEntry[2][0];
 out.m_pEntry[1][2]=m_pEntry[0][2]*m_pEntry[1][0]-m_pEntry[0][0]*m_pEntry[1][2];
 out.m_pEntry[2][0]=m_pEntry[1][0]*m_pEntry[2][1]-m_pEntry[1][1]*m_pEntry[2][0];
 out.m_pEntry[2][1]=m_pEntry[0][1]*m_pEntry[2][0]-m_pEntry[0][0]*m_pEntry[2][1];
 out.m_pEntry[2][2]=m_pEntry[0][0]*m_pEntry[1][1]-m_pEntry[0][1]*m_pEntry[1][0];
 v.det=m_pEntry[0][0]*out.m_pEntry[0][0]+m_pEntry[0][1]*out.m_pEntry[1][0]+m_pEntry[0][2]*out.m_pEntry[2][0];
 if(NiAbs_00408820(v.det)<=DAT_01017cf8) return false;
 v.inv=1.0f/v.det;
 for(v.row=0;v.row<3;v.row++)
  for(v.col=0;v.col<3;v.col++)
   out.m_pEntry[v.row][v.col]*=v.inv;
 return true;
}

