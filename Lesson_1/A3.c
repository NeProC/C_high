#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint32_t N, K;
    uint32_t mask = 0b1;
    scanf("%d%d", &N, &K);
    for (uint32_t i = 0; i < K - 1; i++)
    {
        mask = mask << 1;
        mask++;
    }
    N &= mask;
    printf("%d\n", N);

    return 0;
}
