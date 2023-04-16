#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void sort(int arr[], int n)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = pq.top();
        pq.pop();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    int sum1 = 0;
    int sum2 = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        sum1 += arr1[i];
        mp[arr1[i]] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        sum2 += arr2[i];
    }
    int diff = sum2 - sum1;
    string ans = "No";
    if (diff % 2 == 0)
    {
        sort(arr1, n);
        sort(arr2, m);
        int d = diff / 2;
        for (int i = 0; i < m; i++)
        {
            if (mp[arr2[i] - d])
                ans = "Yes";
        }
    }
    cout << ans;
    return 0;
}