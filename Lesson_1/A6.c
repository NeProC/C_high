#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MASK 0xFF000000

uint32_t bigByte(uint32_t N)
{
    return N ^ MASK;
}

int main()
{
    uint32_t N;
    scanf("%d", &N);
    printf("%u", bigByte(N));

    return 0;
}