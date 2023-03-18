#include <stdio.h>
#include <stdlib.h>

struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = val;
    return node;
}

Node *addToList(Node *head, int val)
{
    Node *node = createNode(val);
    if (head == NULL)
    {
        return node;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
    return node;
}

Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        if (head == NULL)
        {
            head = addToList(head, val);
        }
        else
        {
            addToList(head, val);
        }
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *cur = head;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

int size(Node *head)
{
    int n = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        n++;
    }
    return n;
}

Node *sortList(Node *head)
{
    int length = size(head);
    for (int i = 0; i < length; i++)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != NULL)
        {
            if (temp->data > temp->next->data)
            {
                Node *temp3 = temp->next->next;
                if (prev != NULL)
                {
                    prev->next = temp->next;
                    temp->next->next = temp;
                    temp->next = temp3;
                    prev = prev->next;
                }
                else
                {
                    head = temp->next;
                    temp->next->next = temp;
                    temp->next = temp3;
                    prev = head;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
    }
    return head;
}

int main()
{
    Node *head = readList();
    head = sortList(head);
    printList(head);
    freeList(head);
}