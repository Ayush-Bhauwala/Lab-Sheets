#include <stdio.h>
#include <stdlib.h>

void enqueue(int x, int *freq, int *q, int *rear)
{
    freq[x]++;
    q[(*rear)] = x;
    (*rear)++;
}

void dequeue(int *u, int *freq, int *q, int *rear, int *front)
{
    while (freq[q[*front]] > 1)
    {
        freq[q[*front]]--;
        (*front)++;
    }
    *u = (*rear > *front) ? q[*front] : -1;
}

int main()
{
    int n = 0;
    int front = 0;
    int rear = 0;
    int u = 0;
    scanf("%d", &n);
    int *freq = calloc((n + 1), sizeof(int));
    int *q = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (freq[x] == 0)
        {
            enqueue(x, freq, q, &rear);
            if (u == -1)
            {
                u = x;
            }
        }
        else
        {
            freq[x]++;
        }
        dequeue(&u, freq, q, &rear, &front);
        printf("%d ", u);
    }
    return 0;
}