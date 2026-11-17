#include "nishaderconstantmapentry_decls.h"

// @fnv 0x00e81ba0
// pdb: NiShaderConstantMapEntry::NiShaderConstantMapEntry | NiD3DShaderConstantMap.obj | debug, upstream name already matches, high
NiShaderConstantMapEntry::NiShaderConstantMapEntry() throw()
    : m_kKey((reinterpret_cast<unsigned char*>(&m_bEnabled)[0] = 1,
                       EmptyFS.m_kHandle), 0),
      m_kVariableName((m_uiFlags = 0, m_uiExtra = 0, m_uiShaderRegister = 0,
                          m_uiRegisterCount = 0, EmptyFS.m_kHandle), 0)
{
    volatile NiShaderConstantMapEntry* ordered = this;
    ordered->m_uiDataSize = 0;
    ordered->m_uiDataStride = 0;
    ordered->m_pvDataSource = 0;
    ordered->m_bOwnData = false;
    // The two remaining state bytes occupy the tail padding of the shared class.
    reinterpret_cast<volatile unsigned char*>(&m_bOwnData)[1] = 0;
    reinterpret_cast<volatile unsigned char*>(&m_bOwnData)[2] = 0;
}
