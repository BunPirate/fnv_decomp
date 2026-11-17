
#include "nibound_decls.h"
// @fnv 0x00a7fdd0
// pdb: NiBound::Update | NiParticleSystem.obj | debug, call graph, medium
// pdb params: bound, xform
// pdb locals: pnty, yy, rot2, rad, pntz, zz, transscl, rot1, scl, rot0, pntx, xx, res
void NiBound::Update(const NiBound& bound,const NiTransform& transform)
{
    m_kCenter = transform.m_Translate + (transform.m_Rotate * bound.m_kCenter) * transform.m_fScale;
    m_fBoundRadius = bound.m_fBoundRadius * transform.m_fScale;
}
