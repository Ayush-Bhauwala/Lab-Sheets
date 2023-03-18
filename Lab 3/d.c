#include <stdio.h>
#include <stdlib.h>
#define int long

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
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        head = addNode(head, num);
    }
    Node *left = head;
    Node *curr = head;
    int indexLeft = 0;
    int indexRight = 0;
    while (curr->next != NULL)
    {
        indexRight++;
        curr = curr->next;
    }
    Node *right = curr;
    int countA = 1;
    int countB = 1;
    int sumA = left->num;
    int sumB = right->num;
    int countMaxA = 0;
    int countMaxB = 0;
    while (indexLeft < indexRight)
    {
        if (sumA < sumB)
        {
            left = left->next;
            countA++;
            indexLeft++;
            sumA += left->num;
        }
        else if (sumA > sumB)
        {
            right = right->prev;
            countB++;
            indexRight--;
            sumB += right->num;
        }
        else
        {
            countMaxA = countA;
            countMaxB = countB;
            left = left->next;
            countA++;
            indexLeft++;
            sumA += left->num;
            right = right->prev;
            countB++;
            indexRight--;
            sumB += right->num;
        }
    }
    printf("%d %d", countMaxA, countMaxB);
    return 0;
}