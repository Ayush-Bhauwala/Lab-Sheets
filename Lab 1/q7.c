#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int *arr, int len)
{
    int min = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int maximum(int *arr, int len)
{
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

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

int indexOf(char ch, char *str, int *used, int len, int start_index)
{
    for (int i = start_index; i < strlen(str); i++)
    {
        if (ch == str[i] && !isIn(i, used, len))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char sent[1000];
    scanf("%[^\n]s", sent);
    char word[100];
    scanf("%s", &word);
    int **indexChars = (int **)malloc(sizeof(int *)); // array of all windows
    int len = 0;
    int complete = 0;
    for (int j = 0; j < strlen(sent); j++)
    {
        int *indexUsed = (int *)malloc(sizeof(int) * strlen(word));
        for (int i = 0; i < strlen(word); i++)
        {
            char ch = word[i];
            int index = indexOf(ch, sent, indexUsed, strlen(word), j);
            if (index == -1)
            {
                complete = 1;
                break;
            }
            else
            {
                indexUsed[i] = index;
            }
        }
        if (complete == 1)
        {
            break;
        }
        len++;
        indexChars = (int **)realloc(indexChars, sizeof(int *) * len);
        indexChars[len - 1] = indexUsed;
    }
    if (len == 0)
    {
        printf("NO WINDOW");
        exit(0);
    }

    int *windowSize = (int *)malloc(sizeof(int) * len); // array of window sizes
    for (int i = 0; i < len; i++)
    {
        int *indexUsed = indexChars[i];
        int min = minimum(indexUsed, strlen(word));
        int max = maximum(indexUsed, strlen(word));
        int window_size = max - min;
        windowSize[i] = window_size;
    }
    int min_index = 0;
    int min = windowSize[0];
    for (int i = 0; i < len; i++)
    {
        if (min > windowSize[i])
        {
            min = windowSize[i];
            min_index = i;
        }
    }

    int first_index, last_index = indexChars[min_index][0];
    for (int i = 0; i < strlen(word); i++)
    {
        int index = indexChars[min_index][i];
        if (index < first_index)
        {
            first_index = index;
        }
        if (index > last_index)
        {
            last_index = index;
        }
    }
    printf("%d %d\n", first_index, last_index);
    for (int i = first_index; i < last_index + 1; i++)
    {
        printf("%c", sent[i]);
    }
    return 0;
}