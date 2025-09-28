#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t cnk2(uint32_t n, uint32_t k)
{
    double res = 1;
    for (uint32_t i = 1; i <= k; ++i)
    {
        res = res * (n - k + i) / i;
    }
    return (int)(res + 0.01);
}

int main()
{
    uint32_t numFlag[10] = {
        0,
    };
    uint32_t numCounter = 0;
    uint64_t num;
    uint32_t tmp;

    scanf("%ld", &num);
    while (num != 0)
    {
        tmp = num % 10;
        numFlag[tmp] = 1;
        num /= 10;
    }
    for (size_t i = 0; i < 10; i++)
    {
        numCounter += numFlag[i];
    }

    printf("%d", cnk2(numCounter, 3));

    return 0;
}
