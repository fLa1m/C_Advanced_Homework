#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int n;
    int max;
    int count_max = 1;
    scanf("%u", &n);
    scanf("%d", &max);
    n--;
    while (n != 0)
    {
        int temp;
        scanf("%d", &temp);
        if (temp > max)
        {
            max = temp;
            count_max = 1;
        }
        else if (temp == max)
        {
            count_max++;
        }
        n--;
    }

    printf("%d\n", count_max);
    return 0;
}
