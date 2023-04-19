#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pancake(vector<int> a, int n)
{
    vector<int> res;
    int index, num;
    for (num = n; num > 0; num--)
    {
        for (index = 0; a[index] != num; index++)
            ;
        reverse(a.begin(), a.begin() + index + 1);
        res.push_back(index + 1);
        reverse(a.begin(), a.begin() + num);
        res.push_back(num);
    }
    vector<int> ans;
    for (int i = 0; i < res.size() / 2; i++)
    {
        if (res[2 * i] == res[2 * i + 1])
            continue;
        else
        {
            if (res[2 * i] != 1)
                ans.push_back(res[2 * i]);
            if (res[2 * i + 1] != 1)
                ans.push_back(res[2 * i + 1]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans = pancake(arr, n);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}