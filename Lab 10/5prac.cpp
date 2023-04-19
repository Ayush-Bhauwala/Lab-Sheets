#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(vector<pair<int, int>> &E)
{
    sort(E.begin(), E.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first == b.first ? b.second < a.second : a.first < b.first; });
    vector<int> dp;
    for (auto &env : E)
    {
        int height = env.second;
        int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
        if (left == dp.size())
            dp.push_back(height);
        dp[left] = height;
    }
    return dp.size();
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> dolls;
    for (int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h;
        dolls.push_back({w, h});
    }
    cout << count(dolls);
    return 0;
}