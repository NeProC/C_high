#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

union floatBit
{
    float value;
    struct
    {
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
    } bit;
};

int extractExp(float);

int main()
{
    float N;
    scanf("%f", &N);
    printf("%d", extractExp(N));
    return 0;
}

int extractExp(float in)
{
    union floatBit fb;
    fb.value = in;
    return (int)fb.bit.exp;
}