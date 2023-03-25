#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<ll> index;
    ll maxArea = -1;
    for (ll i = 0; i <= n; i++)
    {
        ll curHeight = i == n ? 0 : arr[i];
        while (!index.empty() && curHeight < arr[index.top()])
        {
            ll top = index.top();
            index.pop();
            ll width = index.empty() ? i : i - index.top() - 1;
            ll area = arr[top] * width;
            maxArea = maxArea > area ? maxArea : area;
        }
        index.push(i);
    }
    cout << maxArea;
    return 0;
}