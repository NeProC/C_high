#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint8_t oneCounter(uint32_t N)
{
    uint8_t counter = 0;
    for (int i = 0; i < 32; i++)
    {
        counter += N & 0x1;
        N = N >> 1;
    }
    return counter;
}

int main()
{
    uint32_t N;
    scanf("%d", &N);
    printf("%hhd", oneCounter(N));

    return 0;
}