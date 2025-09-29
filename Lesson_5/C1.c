#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 1000

int PrefSuf(char *s1, char *s2)
{
    int num = 0;
    int lenS1 = strlen(s1);
    int lenS2 = strlen(s2);
    int minLen = lenS1 < lenS2 ? lenS1 : lenS2;

    for (size_t i = 1; i <= minLen; i++)
    {
        if (strncmp(s1, s2 + lenS2 - i, i) == 0)
        {
            num = i;
        }
    }
    return num;
}

int main()
{
    char s1[SIZE], s2[SIZE];
    scanf("%1000s\n%1000s", s1, s2);
    printf("%d %d\n", PrefSuf(s1, s2), PrefSuf(s2, s1));

    return 0;
}
