#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int findMin(int arr[], int start, int end)
{
    int min = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void reverseArray(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    for (int i = start; i <= mid; i++)
    {
        int temp = arr[i];
        arr[i] = arr[end - i];
        arr[end - i] = temp;
    }
    // cout << "\n";
    // for (int i = 0; i <= end; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    int k = 0;
    vector<int> ks;
    for (int i = n - 1; i >= 0; i--)
    {
        int num = i + 1;
        if (arr[num - 1] != num)
        {
            if (index != 0)
            {
                reverseArray(arr, 0, index);
                ks.push_back(index + 1);
            }
            if (num != 1)
            {
                reverseArray(arr, 0, num - 1);
                ks.push_back(num);
            }
        }
    }
    cout << ks.size() << "\n";
    for (int i = 0; i < ks.size(); i++)
    {
        cout << ks[i] << " ";
    }
    return 0;
}
