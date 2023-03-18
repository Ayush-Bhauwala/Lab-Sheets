#include <stdio.h>
#include <stdlib.h>
int isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int *digit_freq = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        digit_freq[i] = 0;
    }
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            int num = i;
            while (num > 0)
            {
                int dig = num % 10;
                digit_freq[dig]++;
                num /= 10;
            }
        }
    }
    int max = 0, dig = 0;
    for (int i = 0; i < 10; i++)
    {
        if (digit_freq[i] > max)
        {
            max = digit_freq[i];
            dig = i;
        }
    }
    printf("%d %d", dig, max);
    return 0;
}