#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int32_t maskCounting(int32_t K)
{
    int32_t mask = 0b1;
    for (int i = 1; i < K; i++)
    {
        mask = mask << 1;
        mask++;
    }
    return mask;
}

int main()
{
    uint32_t N, K, mask, max = 0;
    scanf("%d%d", &N, &K);
    mask = maskCounting(K);
    for (int i = 0; i < 31; i++)
    {
        K = N & mask;
        N = N >> 1;
        if (K > max)
        {
            max = K;
        }
    }

    printf("%d\n", max);

    return 0;
}