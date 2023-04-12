#include <iostream>
#include <unordered_map>

using namespace std;

int fn(int a[], int n, int k)
{
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] - k;
        if (sum == 0)
            ans++;
        if (mp.find(sum) != mp.end())
        {
            ans += mp[sum];
        }
        mp[sum]++;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fn(arr, n, k);
    return 0;
}