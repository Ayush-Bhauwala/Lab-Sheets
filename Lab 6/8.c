#include <stdio.h>
#include <stdlib.h>

void enQueue(int *queue, int *rear, int val, int *front, int n)
{
    if ((*rear) + 1 % n == *front)
    {
        printf("Full");
        return;
    }
    if (*front == -1)
        *front = 0;
    *rear = (*rear + 1) % n;
    queue[*rear] = val;
}

int deQueue(int *queue, int *rear, int *front, int n)
{
    int val;
    if (*front == -1)
        return -1;
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        val = queue[*front];
        *front = (*front + 1) % n;
    }
    return val;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int queue[n + 1];
    int front = -1;
    int rear = -1;
    for (int i = 1; i <= n; i++)
    {
        if (i % k != 0)
            enQueue(queue, &rear, i, &front, n);
    }
    int count = n + 1;
    while (front != rear)
    {
        int val = deQueue(queue, &rear, &front, n);
        if (count++ % k != 0)
        {
            enQueue(queue, &rear, val, &front, n);
        }
    }
    printf("%d ", queue[front]);
    return 0;
}