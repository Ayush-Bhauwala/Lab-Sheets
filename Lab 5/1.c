#include <stdio.h>
#include <stdlib.h>
#define int long long
void brackets(int index, int open, int close, int length, char *str, char **sequences, int *count)
{
    if (close == length / 2)
    {
        (*count)++;
        sequences[*count - 1] = (char *)malloc(sizeof(char) * (length + 1));
        for (int j = 0; j < length; j++)
        {
            sequences[*count - 1][j] = str[j];
        }
        sequences[*count - 1][length] = '\0';
    }
    else
    {
        if (close < open)
        {
            str[index] = ')';
            brackets(index + 1, open, close + 1, length, str, sequences, count);
        }
        if (open < length / 2)
        {
            str[index] = '(';
            brackets(index + 1, open + 1, close, length, str, sequences, count);
        }
    }
}
int main()
{
    int n;
    scanf("%lld", &n);
    char *str = (char *)malloc(sizeof(char) * n);
    char **sequences = (char **)malloc(sizeof(char *) * 500);
    int count = 0;
    brackets(0, 0, 0, n, str, sequences, &count);

    printf("%lld\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", sequences[i]);
    }
    return 0;
}