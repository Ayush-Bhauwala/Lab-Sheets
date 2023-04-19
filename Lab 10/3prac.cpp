#include <iostream>

using namespace std;

float median(int a[], int n, int b[], int m)
{
    int low = 0, high = m, medianPos = (m + n + 1) / 2;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = medianPos - cut1;

        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : a[cut1];
        int r2 = cut2 == n ? INT_MAX : b[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 == 0)
                return ((max(l1, l2) + min(r1, r2)) / 2.0);
            else
                return (max(l1, l2));
        }
        else if (l1 < r2)
            low = cut1 + 1;
        else
            high = cut1 - 1;
    }
    return 0;
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

    cout << median(a, n, b, m);
    return 0;
}