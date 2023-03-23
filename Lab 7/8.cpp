#include <iostream>
using namespace std;

#define ll long long

void postOrder(ll *tree, ll index, ll length)
{
    ll left = (2 * index) + 1;
    ll right = (2 * index) + 2;
    if (left < length)
    {
        postOrder(tree, left, length);
    }
    if (right < length)
    {
        postOrder(tree, right, length);
    }
    if (tree[index] != -1)
    {
        cout << tree[index];
        cout << " ";
    }
}

int main()
{
    ll n, l, r;
    cin >> n;
    cin >> l;
    cin >> r;
    ll *a = (ll *)malloc(sizeof(ll) * n);
    for (ll i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        if (val < l || val > r)
        {
            val = -1;
        }
        a[i] = val;
    }
    cout << "\n";
    postOrder(a, 0, n);
    return 0;
}