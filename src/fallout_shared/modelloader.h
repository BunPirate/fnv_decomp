
#include "modelloader_decls.h"
// @fnv 0x00712380
unsigned char QueuedFileLoad::GetFileIndex()
{
    return fileIndex;
}
// @fnv 0x0043fdf0
// pdb: QueuedReference::PostProcess | ModelLoader.obj | debug, vtable slot, medium
void QueuedReference::ProcessLoadedAnimIdle()
{
    vfn_3c();
}
template <>
// @fnv 0x0044a7f0
// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator= | Tile.obj | debug, call graph, medium
// pdb params: _Ptr
std::basic_string<char, std::char_traits<char>, std::allocator<char> >& std::basic_string<
    char, std::char_traits<char>, std::allocator<char> >::assign(const char* source, unsigned int count)
{
    if (_Inside(source))
        return assign(*this, source - _Myptr(), count);
    if (_Grow(count, false))
    {
        std_Traits_helper_copy_s_std_char_traits_char(_Myptr(), capacity, source, count);
        _Eos(count);
    }
    return *this;
}
