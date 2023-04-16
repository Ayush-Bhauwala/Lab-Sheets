#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int binarySearch(int x, int l, int r, int arr[])
{
    if (l < r)
        return -1;

    int mid = (l + r) / 2;
    if (x < arr[mid])
    {
        r = mid - 1;
    }
    else if (x > arr[mid])
    {
        l = mid + 1;
    }
    else
    {
        return mid - 1;
    }
    return binarySearch(x, l, r, arr);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int count = 0;
    int sorted[n];
    for (int i = 0; i < n; i++)
    {
        sorted[i] = pq.top();
        pq.pop();
    }
    int currLength = n;
    for (int i = 0; i < n - 1; i++)
    {
        int index = binarySearch(arr[i], 0, n - 1, arr);
        currLength--;
    }
    cout << count;
    return 0;
}