// Реализовать программу 1-го практического задания с помощью биномиального коэффициента.

#include <stdio.h>

int cnk(int n, int k)
{
    int res = 1;
    for (int i = n - k + 1; i <= n; i++)
    {
        res *= i;
    }
    for (int i = 2; i <= k; i++)
    {
        res /= i;
    }
    return res; 
}

int cnk2(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; i++)
    {
        res = res * (n - k + i) / i;
    }
    return (int) (res + 0.01);
}

int binom(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= (n - k); i++)
    {
        res *= (n - i + 1);
        res /= i;
    }
    return (int) res;
}


int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("binom = %d, cnk = %d, cnk2 = %d", binom(n, k), cnk(n, k), cnk2(n, k));
    return 0;
}