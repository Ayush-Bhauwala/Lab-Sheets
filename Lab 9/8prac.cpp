#include <iostream>

using namespace std;

int isPossible(int a[], int n, int m, int mid)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > mid)
        {
            count++;
            sum = a[i];
            if (sum > mid)
                return 0;
        }
        else
        {
            sum += a[i];
        }
    }
    if (count < m)
        return 1;
    return 0;
}

int fn(int a[], int m, int n)
{
    int low = a[0];
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        high += a[i];
        low = min(low, a[i]);
    }
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(a, n, m, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << fn(a, m, n);
    return 0;
}