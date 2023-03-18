#include <stdio.h>
#include <stdlib.h>
#define int long long

int check(int freq[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (freq[i] < 1)
            return 0;
    }
    return 1;
}

int fn(char *str, int *freq, int n, int k)
{
    int ctr = 0;
    int L = 0;
    int r = 0;
    while (r < n)
    {
        while (check(freq, k) == 0 && r < n)
        {
            freq[str[r] - 97]++;
            r++;
        }
        if (check(freq, k))
            ctr += n - r + 1;
        while (check(freq, k) == 1 && L <= r)
        {
            freq[str[L] - 97]--;
            L++;
            if (check(freq, k) == 1)
                ctr += n - r + 1;
        }
    }
    return ctr;
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    char str[100000];
    scanf("%s", &str);
    int *freq = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        freq[i] = 0;
    }
    int x = fn(str, freq, n, k);
    printf("%lld", x);

    return 0;
}