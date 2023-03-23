#include <iostream>
using namespace std;

#define ll long long

void checkFreedomNode(ll *arr, ll currIndex, ll currSum, ll x, ll *count, ll length)
{
    currSum += arr[currIndex];
    int leftIndex = (2 * currIndex) + 1;
    int rightIndex = (2 * currIndex) + 2;
    if (leftIndex < length && arr[leftIndex] != -1)
    {
        checkFreedomNode(arr, leftIndex, currSum, x, count, length);
    }
    if (rightIndex < length && arr[rightIndex] != -1)
    {
        checkFreedomNode(arr, rightIndex, currSum, x, count, length);
    }
    if ((leftIndex > length || arr[leftIndex] == -1) && (rightIndex > length || arr[rightIndex] == 1))
    {
        if (currSum == x)
        {
            *count += 1;
        }
    }
}

int main()
{
    ll n, x;
    cin >> n;
    cin >> x;
    ll *a = (ll *)malloc(sizeof(ll) * n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll count = 0;
    checkFreedomNode(a, 0, 0, x, &count, n);
    cout << count;
    return 0;
}