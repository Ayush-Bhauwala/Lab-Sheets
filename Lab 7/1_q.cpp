#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int ele = q.top();
        q.pop();
        q.push(ele / 2);
    }
    int sum = 0;
    while (!q.empty())
    {
        sum += q.top();
        q.pop();
    }
    cout << sum;
    return 0;
}