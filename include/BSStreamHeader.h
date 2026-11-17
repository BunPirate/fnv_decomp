#pragma once

// The NIF file header Bethesda's streams read after the Gamebryo header: the exporter's author and the two export-info
// strings (process and export script), 196 bytes.
// pdb: structure BSStreamHeader, size 0xc4, 4 members
struct BSStreamHeader
{
    unsigned int uiVersion;    // +0x00 // src: XBOX_RETAIL_PDB +0x0 (old: m_uiVersion)
    char pAuthor[64];         // +0x04 // src: XBOX_RETAIL_PDB +0x4 (old: m_acAuthor)
    char pProcessScript[64];  // +0x44 // src: XBOX_RETAIL_PDB +0x44 (old: m_acProcessScript)
    char pExportScript[64];   // +0x84 // src: XBOX_RETAIL_PDB +0x84 (old: m_acExportScript)
};
