
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

float RandomFloat(float afMin, float afMax);
struct S_0062e910
{
    float RandomSignedFloat(float afSize);
};
// @fnv 0x0062e910
// pdb: TESWindListener::GetRandom | TESWindListener.obj | retail, vtable slot, high
// pdb params: afSize
float S_0062e910::RandomSignedFloat(float afSize)
{
    return RandomFloat(-afSize, afSize);
}
