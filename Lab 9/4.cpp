#include <iostream>
#include <unordered_map>

using namespace std;

int countKAverageSubarrays(int arr[], int n, int k)
{
    int result = 0, curSum = 0;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        curSum += (arr[i] - k);

        if (curSum == 0)
            result++;

        if (mp.find(curSum) != mp.end())
            result += mp[curSum];

        mp[curSum]++;
    }

    return result;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << countKAverageSubarrays(arr, N, K);
}
