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

int currSong(Node *node)
{
    return node->num;
}

Node *prevSong(Node *node)
{
    if (node->prev == NULL)
    {
        return node;
    }
    return node->prev;
}

Node *nextSong(Node *node)
{
    if (node->next == NULL)
    {
        return node;
    }
    return node->next;
}

Node *isIn(int num, Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->num == num)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void playNext(Node *head, int num, Node *curr)
{
    if (num == curr->num)
        return;

    Node *nxtSong = isIn(num, head);

    if (nxtSong != NULL)
    {
        if (curr->next != NULL)
            curr->next->prev = nxtSong;
        if (nxtSong->next != NULL)
            nxtSong->next->prev = nxtSong->prev;
        if (nxtSong->prev != NULL)
            nxtSong->prev->next = nxtSong->next;
        nxtSong->next = curr->next;
        nxtSong->prev = curr;
        curr->next = nxtSong;
    }
    else
    {
        Node *new = createNode(num);
        Node *temp = curr->next;
        curr->next = new;
        new->prev = curr;
        new->next = temp;
        if (temp != NULL)
            temp->prev = new;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        head = addSong(head, num);
    }
    int op = 0;
    Node *curr = head;
    while (op != 5)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            int num;
            scanf("%d", &num);
            head = addSong(head, num);
            break;
        case 2:
            printf("--%d--\n", currSong(curr));
            break;
        case 3:
            curr = nextSong(curr);
            break;
        case 4:
            curr = prevSong(curr);
            break;
        case 5:
            break;
        case 6:
            int n;
            scanf("%d", &n);
            playNext(head, n, curr);
        default:
            break;
        }
    }
    return 0;
}