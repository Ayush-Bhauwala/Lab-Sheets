#include <stdio.h>
#include <stdlib.h>
#define int long long

struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *addToListFront(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head = newNode;
    return head;
}
Node *addToListEnd(Node *tail, int val)
{
    Node *newNode = createNode(val);
    if (tail == NULL)
    {
        return newNode;
    }
    tail->next = newNode;
    tail = tail->next;
    return tail;
}
int main()
{
    int n;
    scanf("%lld", &n);
    Node *head = NULL;
    Node *tail = NULL;
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        if (head == NULL)
        {
            head = addToListFront(head, a[i]);
            tail = head;
        }
        else
        {
            if (a[i] <= head->data)
                head = addToListFront(head, a[i]);
            else
                tail = addToListEnd(tail, a[i]);
        }
    }
    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", temp->data);
        temp = temp->next;
    }
    return 0;
}