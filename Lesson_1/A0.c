#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int n;
    int maxRes, counter = 1;
    int tmp;
    scanf("%d", &n);

    if (n == 0)
    {
        counter = 0;
    }
    else
    {
        scanf("%d", &maxRes);
    }

    while (n - 1)
    {
        n--;
        scanf("%d", &tmp);
        if (tmp < maxRes)
        {
            continue;
        }
        if (tmp > maxRes)
        {
            maxRes = tmp;
            counter = 1;
        }
        else
        {
            // printf("maxRes ====>%d, counter ====>%d\n", maxRes, counter);
            counter++;
        }
    }
    printf("%d\n", counter);

    return 0;
}