#pragma once

// The NIF file header Bethesda's streams read after the Gamebryo header: the exporter's author and the two export-info
// strings (process and export script), 196 bytes.
// pdb: structure BSStreamHeader, size 0xc4, 4 members
struct BSStreamHeader
{
    unsigned int uiVersion;    // +0x00
    char pAuthor[64];         // +0x04
    char pProcessScript[64];  // +0x44
    char pExportScript[64];   // +0x84
};
