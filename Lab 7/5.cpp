#include <iostream>
using namespace std;

#define ll long long

void inOrder(ll *tree, ll index, ll length, ll *count, ll k)
{
    ll left = (2 * index) + 1;
    ll right = (2 * index) + 2;

    if (left < length && tree[left] != -1)
    {
        inOrder(tree, left, length, count, k);
    }

    (*count)++;

    if (*count == k)
    {
        cout << tree[index];
        exit(0);
    }

    if (right < length && tree[right] != -1)
    {
        inOrder(tree, right, length, count, k);
    }
}

int main()
{
    ll n, k;
    cin >> n;
    ll a[n];
    int nonNull = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            nonNull++;
        }
    }
    cin >> k;
    ll ctr = 0;
    cout << "\n";

    inOrder(a, 0, n, &ctr, nonNull + 1 - k);
    return 0;
}