#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    return 0;
}