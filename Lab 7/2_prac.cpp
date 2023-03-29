#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int x)
{
    Node *node = new Node();
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int *arr, int l, int r, int x)
{
    for (int i = l; i <= r; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int calcHeight(Node *node)
{
    if (node == NULL)
        return 0;
    int lh = calcHeight(node->left);
    int rh = calcHeight(node->right);
    return lh > rh ? lh + 1 : rh + 1;
}

void printLevel(Node *node, int level)
{
    if (node == NULL)
    {
        for (int i = 0; i < pow(2, level - 1); i++)
        {
            cout << "-1 ";
        }
        return;
    }
    if (level == 1)
    {
        cout << node->data << " ";
    }
    else
    {
        printLevel(node->left, level - 1);
        printLevel(node->right, level - 1);
    }
}

void printTree(Node *root)
{
    int h = calcHeight(root);
    for (int i = 1; i <= h; i++)
    {
        printLevel(root, i);
    }
}

Node *buildTree(int *in, int *pre, int inStart, int inEnd)
{
    static int x = 0;

    Node *node = createNode(pre[x++]);

    if (inStart > inEnd)
        return NULL;
    if (inStart == inEnd)
        return node;

    int index = search(in, inStart, inEnd, node->data);

    node->left = buildTree(in, pre, inStart, index - 1);
    node->right = buildTree(in, pre, index + 1, inEnd);
    return node;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    Node *root = buildTree(b, a, 0, n - 1);
    printTree(root);
    return 0;
}