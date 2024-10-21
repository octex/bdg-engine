#ifndef RNG_TBOX
#define RNG_TBOX

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

extern unsigned long seed;

void GenerateSeed();
int GetNumbersInRange(int min, int max);
float GetNumbersInRangef(float min, float max);

#endif