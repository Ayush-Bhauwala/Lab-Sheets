#include <stdio.h>
#include <stdlib.h>

void enqueue(int *q, int x, int *front, int *rear)
{
    q[(*rear)] = x;
    (*rear)++;
}

void dequeue(int *q, int *freq, int *front, int *rear, int *u)
{
    while (freq[q[*front]] > 1)
    {
        (*front)++;
    }
    *u = *front < *rear ? q[*front] : -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int *freq = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    int *q = (int *)malloc(sizeof(int) * n);
    int front = 0;
    int rear = 0;
    int u = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (freq[x] == 0)
        {
            enqueue(q, x, &front, &rear);
            freq[x]++;
            if (u == -1)
            {
                u = x;
            }
        }
        else
        {
            freq[x]++;
        }
        dequeue(q, freq, &front, &rear, &u);
        printf("%d ", u);
    }
    return 0;
}