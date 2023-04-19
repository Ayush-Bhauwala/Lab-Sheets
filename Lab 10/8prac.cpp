#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int A[n], B[m];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mp[A[i]]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        mp[B[i]] *= -1;
    }
    int A_sorted[n];
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(A[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        A_sorted[i] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < mp[B[i]]; j++)
        {
            cout << B[i] << " ";
        }
        mp[B[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = mp[A_sorted[i]]; j < 0; j++)
        {
            cout << A_sorted[i] << " ";
        }
        mp[A_sorted[i]] = 0;
    }
    return 0;
}