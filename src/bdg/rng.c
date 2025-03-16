#include "rng.h"

unsigned long seed;

void GenerateSeed()
{
    unsigned long t_seed = time(NULL);
    srand(t_seed);
    seed = t_seed;
    printf("Seed generated: %lu\n", seed);
}

int GetNumbersInRange(int min, int max)
{
    int nRandonNumber = 0;
    nRandonNumber = rand() % (max-min) + min;
    return nRandonNumber;
}

float GetNumbersInRangef(float min, float max)
{
    float nRandonNumber = 0;
    float scale = rand() / (float) RAND_MAX;
    nRandonNumber = min + scale * ( max - min );
    return nRandonNumber;
}
