#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint32_t rightRotate(uint32_t n, uint8_t k)
{
    return ((n >> k)) | (n << (32 - k));
}

int main(int argc, char const *argv[])
{
    uint32_t N;
    uint8_t K;
    scanf("%d%hhd", &N, &K);
    printf("%u", rightRotate(N, K));
    return 0;
}
