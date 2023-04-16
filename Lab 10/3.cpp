#include <iostream>

using namespace std;

float findMedian(int a[], int low, int high)
{
    if ((high - low) % 2)
    {
        return (a[low + ((high - low) / 2)] + a[(low + ((high - low) / 2)) + 1]) / 2;
    }
    else
    {
        return a[low + ((high - low) / 2)];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int low_a = 0;
    int high_a = n - 1;

    int low_b = 0;
    int high_b = m - 1;

    return 0;
}