/**
 * @file A2.c
 * @author Zelenev.R
 * @date 2025-09-15
 * @brief Description
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #define SIZE_MES 1000

char cesarVelik(char c, int k)
{
    if (c >= 'a' && c <= 'z')
    {
        return 'a' + (((c - 'a' + k) % 26) + 26) % 26;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (((c - 'A' + k) % 26) + 26) % 26;
    }
    else
    {
        return c;
    }
}

int main(int argc, char const *argv[])
{
    uint32_t N;
    //    char outMes[SIZE_MES] = {};
    char C;

    scanf("%d", &N);

    while ((scanf("%c", &C)) == 1)
    {
        if (C == '.')
        {
            printf("%c", cesarVelik(C, N));
            break;
        }
        printf("%c", cesarVelik(C, N));
    }
    return 0;
}
