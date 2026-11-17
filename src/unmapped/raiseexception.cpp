
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Unk65
{
    void FUN_0065de30(int);
    Unk65* CallAndReturnSelf(int a);
};

// @fnv 0x0044a7d0
// pdb: std::basic_string<char,std::char_traits<char>,std::allocator<char> >::operator= | Tile.obj | debug, object-file run extension, low
// pdb params: _Right
Unk65* Unk65::CallAndReturnSelf(int a)
{
    FUN_0065de30(a);
    return this;
}
