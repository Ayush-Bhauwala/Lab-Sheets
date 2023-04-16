#include <iostream>
#include <deque>
using namespace std;

#define ll long long

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int *a = (int *)malloc(sizeof(int) * n);
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k) // removing element that should not be part of subarray
        {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] < a[i]) // removing all elements from queue that are less than current
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
        {
            cout << a[dq.front()] << " ";
        }
    }
    return 0;
}