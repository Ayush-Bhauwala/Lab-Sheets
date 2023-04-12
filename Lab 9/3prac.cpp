#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int fn(int a[], int n)
{
    int ans = 0;
    stack<int> s;
    vector<int> minPrev(n, -1), minNext(n, n), maxPrev(n, -1), maxNext(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            minPrev[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] > a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            minNext[i] = s.top();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] <= a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            maxPrev[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            maxNext[i] = s.top();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int minLeft = i - minPrev[i];
        int minRight = minNext[i] - i;
        int maxLeft = i - maxPrev[i];
        int maxRight = maxNext[i] - i;
        ans += (maxRight * maxLeft - minRight * minLeft) * a[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << fn(arr, n);
    return 0;
}