#include <stdio.h>
#include <stdlib.h>

void enqueue(int *q, int *front, int *rear, int l, int val)
{
    if (((*rear) + 1) % l == *front)
    {
        return;
    }
    if (*front == -1)
    {
        *front = 0;
    }
    *rear = ((*rear) + 1) % l;
    q[*rear] = val;
}

int dequeue(int *q, int *front, int *rear, int l)
{
    int val;
    if (*front == -1)
    {
        return -1;
    }
    val = q[*front];
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = ((*front) + 1) % l;
    }
    return val;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *q = (int *)malloc(sizeof(int) * (n + 1));
    int front = -1;
    int rear = -1;

    for (int i = 1; i <= n; i++)
    {
        enqueue(q, &front, &rear, n, i);
    }

    int count = 1;
    while (front != rear)
    {
        int x = dequeue(q, &front, &rear, n);

        if (count++ % k != 0)
        {
            enqueue(q, &front, &rear, n, x);
        }
    }
    printf("%d", q[front]);
    return 0;
}