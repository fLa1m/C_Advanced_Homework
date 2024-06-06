#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint32_t n, res;
    scanf("%u", &n);
    res = n ^ 0xFF000000;
    printf("%u\n", res);
    return 0;
}

