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
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && a[dq.back()] < a[i])
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