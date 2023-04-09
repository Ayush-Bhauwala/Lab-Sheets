#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum_b += b[i];
    }
    if (sum_a >= sum_b)
    {
        int avail = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            avail += a[i] - b[i];
            if (avail < 0)
            {
                start = i + 1;
                avail = 0;
            }
        }
        cout << start;
    }
    else
        cout << "-1";

    return 0;
}