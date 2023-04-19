#include <iostream>

using namespace std;

int maxSum(int arr[], int n)
{
    int max = INT_MIN;
    int max_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_here += arr[i];
        if (max_here > max)
            max = max_here;

        if (max_here < 0)
            max_here = 0;
    }
    return max;
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
    cout << maxSum(arr, n);
    return 0;
}