#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 1001

int main()
{
    char inputStr[SIZE] = {
        0,
    };
    scanf("%s", inputStr);
    int strLen = strlen(inputStr);
    uint32_t a, b, c;
    int32_t threeNum[SIZE] = {
        0,
    };
    int32_t num;
    int counter = 0;

    if (strLen < 3)
    {
        printf("0\n");
        return 0;
    }

    for (size_t i = 0; i < strLen; i++)
    {
        for (size_t j = i + 1; j < strLen; j++)
        {
            for (size_t z = j + 1; z < strLen; z++)
            {
                a = inputStr[i] - '0';
                b = inputStr[j] - '0';
                c = inputStr[z] - '0';
                if (a == 0)
                {
                    continue;
                }
                num = a * 100 + b * 10 + c;
                threeNum[num] = 1;
            }
        }
    }

    for (size_t i = 0; i < SIZE - 1; i++)
    {
        if (threeNum[i])
        {
            counter++;
        }
    }

    printf("%d\n", counter);

    return 0;
}
