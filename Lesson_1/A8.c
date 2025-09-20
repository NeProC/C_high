#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint64_t M;
    scanf("%ld", &M);
    uint32_t counter = 0;
    uint64_t currentWeight = 1;

    while (M != 0)
    {
        uint32_t remains = M % 3;

        if (remains == 0)
        {
            M /= 3;
        }
        else if (remains == 1)
        {
            counter++;
            M = (M - 1) / 3;
        }
        else
        {
            counter++;
            M = (M + 1) / 3;
        }

        if (currentWeight > 1000000)
        {
            printf("-1\n");
            return 0;
        }
        currentWeight *= 3;
    }
    printf("%d\n", counter);
    return 0;
}
