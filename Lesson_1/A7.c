#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    uint32_t N, oneTime = 0, tmp;
    scanf("%d", &N);

    for (uint32_t i = 0; i < N; i++)
    {
        scanf("%d", &tmp);
        oneTime ^= tmp;
    }
    printf("%d\n", oneTime);

    return 0;
}