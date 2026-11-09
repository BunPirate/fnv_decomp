#include "../../../../include/NiBlendAccumTransformInterpolator.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "niblendaccumtransforminterpolator_decls_decl_niblendaccumtransforminterpolator.h"
#include <string.h>

inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& other)
{
    memcpy(this, &other, sizeof(*this));
    return *this;
}

inline bool NiQuatTransform::IsMarkedInvalid() const
{
    return m_fScale == -3.4028234663852886e38 && qy == -3.4028234663852886e38 && m_kTranslate == -3.4028234663852886e38;
}

extern const AccumRotationMatrix DAT_011a9448;

// The shared class has no declaration for this override; keep its implementation here.
// @fnv 0x00a393c0
// pdb: NiBlendAccumTransformInterpolator::RemoveInterpInfo | NiBlendAccumTransformInterpolator.obj | retail, object-file gap fill, high
// pdb params: ucIndex
// pdb locals: bint
void __fastcall RemoveAccumulatedInterpolator(NiBlendAccumTransformInterpolator* self, int, unsigned char idx)
{
    if (self->m_ucInterpCount == 1 && idx == self->m_ucSingleIdx &&
        !static_cast<const NiQuatTransform&>(self->m_kAccumulatedTransformValue).IsMarkedInvalid())
    {
        NiQuatTransform* value = &self->m_pkAccumArray[self->m_ucSingleIdx].value;
        if (!value->IsInvalid())
            self->m_kAccumulatedTransformValue = self->m_kAccumulatedTransformValue.CombineTransforms(*value);
    }
    bool active = self->m_pkInterpArray[idx].interpolator != 0;
    self->NiBlendInterpolator::RemoveInterpolatorAt(idx);
    if (self->m_ucInterpCount == 1 && active)
    {
        AccumItem* item = &self->m_pkAccumArray[self->m_ucSingleIdx];
        self->m_bReset = true;
        item->time = -3.4028234663852886e38f;
        item->value.m_kTranslate = -3.4028234663852886e38f;
        item->value.qy = -3.4028234663852886e38f;
        item->value.m_fScale = -3.4028234663852886e38f;
        item->accum.m_kTranslate = -3.4028234663852886e38f;
        item->accum.qy = -3.4028234663852886e38f;
        item->accum.m_fScale = -3.4028234663852886e38f;
        item->rotation = DAT_011a9448;
    }
}
