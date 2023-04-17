#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pancakeSort(vector<int> A)
{
    vector<int> res;
    int x, i;
    for (x = A.size(); x > 0; --x)
    {
        for (i = 0; A[i] != x; ++i)
            ;
        reverse(A.begin(), A.begin() + i + 1);
        res.push_back(i + 1);
        reverse(A.begin(), A.begin() + x);
        res.push_back(x);
    }
    vector<int> ans;
    for (int i = 0; i < res.size() / 2; i++)
    {
        if (res[2 * i] == res[2 * i + 1])
        {
            continue;
        }
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
    vector<int> ans = pancakeSort(arr);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
