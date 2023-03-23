#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int n, k;
    cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;

    return 0;
}