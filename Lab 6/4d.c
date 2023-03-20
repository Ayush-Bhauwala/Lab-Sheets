#include <stdio.h>
#include <stdlib.h>

void enQueue(int *rear, int *q, int val)
{
    q[*rear] = val;
    (*rear)++;
}

int deQueue(int *front, int *rear, int *q, int *freq)
{
    while (q[*front] != -1 && freq[q[*front]] > 1 && (*rear >= *front))
    {
        (*front)++;
    }
    return (*rear > *front) ? q[*front] : -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int freq[n];
    int *q = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
        q[i] = -1;
    }
    int x;
    int front = 0;
    int rear = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (freq[x] == 0)
        {
            enQueue(&rear, q, x);
        }
        freq[x]++;
        ans = deQueue(&front, &rear, q, freq);
        printf("%d ", ans);
    }
    return 0;
}