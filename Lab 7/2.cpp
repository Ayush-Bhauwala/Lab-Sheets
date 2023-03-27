#include <iostream>
#include <math.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int search(int arr[], int l, int r, int a)
{

    for (int i = l; i <= r; i++)
    {
        if (arr[i] == a)
            return i;
    }
    return -1;
}

node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{

    static int x = 0;

    if (inStrt > inEnd)
        return NULL;

    node *tNode = newNode(pre[x++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

int height(node *node)
{

    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void printCurrentLevel(node *root, int level)
{
    if (root == NULL)
    {
        for (int i = 0; i < (pow(2, level - 1)); i++)
            cout << -1 << " ";
        return;
    }
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{
    int n;
    cin >> n;
    int pre[n];
    int in[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    node *root = buildTree(in, pre, 0, n - 1);
    printLevelOrder(root);
}