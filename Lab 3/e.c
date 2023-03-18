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

Node *addSong(Node *head, int num)
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

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        head = addSong(head, num);
    }
    for (int i = 0; i < k; i++)
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = head;
        head->prev = last;
        last->prev->next = NULL;
        last->prev = NULL;
        head = last;
    }
    printList(head);
    return 0;
}