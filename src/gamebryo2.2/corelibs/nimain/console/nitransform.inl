
#include "nitransform_decls.h"
#pragma optimize("gty", on)
// @fnv 0x00a68bf0
// pdb: NiAVObject::UpdateWorldLoc | NiAVObject_Xenon.obj | retail, upstream name already matches, high
void NiAVObject::UpdateWorldLoc()
{
 if (m_pkParent) {
  if ((unsigned char)(m_uFlags >> 9) & 1) m_kWorld = m_pkParent->m_kWorld;
  else m_kWorld = m_pkParent->m_kWorld * m_kLocal;
 } else m_kWorld = m_kLocal;
}
#pragma optimize("", off)
// @fnv 0x004b4880
// pdb: NiTransform::InvertNonUniform | Actor.obj | retail, call graph, low
// pdb note: debug build links it to NiTransform::Invert
// pdb params: kDest
// pdb locals: tst
void NiTransform::CalculateInverse(NiTransform& out)
{
 out.m_Rotate = m_Rotate.Transpose();
 out.m_fScale = 1.0f / m_fScale;
 out.m_Translate = NiPosData::ComputePositionAtTime(out.m_fScale, static_cast<const NiMatrix3&>(out.m_Rotate) * static_cast<const NiPoint3&>(m_Translate).GetNegatedVector());
}
#pragma optimize("", on)
