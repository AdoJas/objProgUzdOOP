#include "common.h"

void swap(float* var1, float* var2)
{
    float temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}