#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct pack_array
{
    uint32_t array;      // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int[], struct pack_array *);

int main()
{
    int bitArr[32] = {};
    struct pack_array packArray;
    packArray.array = 0;
    packArray.count0 = 0;
    packArray.count1 = 0;

    for (int i = 0; i < 32; i++)
    {
        scanf("%d", &bitArr[i]);
    }

    array2struct(bitArr, &packArray);
    printf("%u %u %u", packArray.array, packArray.count0, packArray.count1);

    return 0;
}

void array2struct(int arr[], struct pack_array *packArray)
{
    for (int i = 0; i < 32; i++)
    {
        if (*(arr + i) & 0x1)
        {
            packArray->count1++;
            packArray->array |= (1 << (31 - i));
        }
        else
        {
            packArray->count0++;
        }
    }
}