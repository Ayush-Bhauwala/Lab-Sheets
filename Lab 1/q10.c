#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isIn(int n, int *arr, int len)
{
    if (len == 0)
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

int indexOf(char ch, char *str, int *used, int len)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (ch == str[i] && !isIn(i, used, len))
        {
            return i;
        }
    }
    return -1;
}

void sort(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < (strlen(str) - 1); j++)
        {
            if (str[j] > str[j + 1])
            {
                char chTemp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = chTemp;
            }
        }
    }
}
int main()
{
    char s[1000];
    char a[1000];
    scanf("%s", &s);
    scanf("%s", &a);
    int chrMatches = 1;
    int *indexUsed = (int *)malloc(sizeof(int));
    char s_copy[1000], a_copy[1000];
    strcpy(s_copy, s);
    strcpy(a_copy, a);
    sort(s_copy);
    sort(a_copy);
    int len = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (s_copy[i] != a_copy[i])
        {
            chrMatches = 0;
        }
    }
    if (chrMatches)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            char ch_a = a[i];
            int index = indexOf(ch_a, s, indexUsed, len);
            len++;
            indexUsed = (int *)realloc(indexUsed, sizeof(int) * len);
            indexUsed[i] = index;
            printf("%d ", index + 1);
        }
    }
    else
    {
        printf("NOT POSSIBLE");
    }
    return 0;
}