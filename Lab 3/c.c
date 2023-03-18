#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int num;
    struct Node_t *prev;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->num = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *addNode(Node *head, int num)
{
    Node *new = createNode(num);

    if (head == NULL)
    {
        head = new;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new;
        new->prev = curr;
    }
    return head;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        head = addNode(head, num);
    }
    Node *curr = head;
    Node *left = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    Node *right = curr;
    int possible = 0;
    while (left->num < right->num)
    {
        if (left->num + right->num < k)
        {
            left = left->next;
        }
        else if (left->num + right->num > k)
        {
            right = right->prev;
        }
        else
        {
            possible = 1;
            break;
        }
    }
    printf("%d", possible);
    return 0;
}