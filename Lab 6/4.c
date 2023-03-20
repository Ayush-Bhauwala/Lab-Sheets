#include <stdio.h>
#include <stdlib.h>

#define int long long

int isFull(int *q, int front, int rear, int length)
{
    return (front == 0 && rear == length - 1 || (front == rear - 1));
}

int isEmpty(int front)
{
    return (front == -1);
}

void enqueue(int *q, int *front, int *rear, int length, int val)
{
    if (!isFull(q, *front, *rear, length))
    {
        if (*front == -1)
        {
            *front = 0;
            *rear = 0;
        }
        else if (*rear == length - 1 && *front != 0)
        {
            *rear = 0;
        }
        else
        {
            *rear += 1;
        }
        q[*rear] = val;
    }
}

void dequeue(int *q, int *front, int *rear, int length)
{
    if (!isEmpty(*front))
    {
        int x = q[*front];
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        *front += 1;
        if (*front == length)
        {
            *front = 0;
        }
        // return x;
    }
    // return -1;
}

void main()
{
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int *q = (int *)malloc(sizeof(int) * n);
    int *freq = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
        q[i] = -1;
    }
    int front = -1;
    int rear = -1;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
        if (freq[a[i]] == 1)
        {
            enqueue(q, &front, &rear, n, a[i]);
        }
        else
        {
            dequeue(q, &front, &rear, n);
        }
        printf("%lld ", front == -1 ? -1 : q[front]);
    }
}