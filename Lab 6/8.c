#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define int long long

struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList(int n)
{
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x = i + 1;
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    Node *head = readList(n);
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head;
    curr = head;
    while (n > 1)
    {
        for (int i = 0; i < k - 2; i++)
        {
            curr = curr->next;
        }
        Node *toDelete = curr->next;
        curr->next = curr->next->next;
        free(toDelete);
        n--;
        curr = curr->next;
    }
    printf("%lld", curr->data);
    return 0;
}