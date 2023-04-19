#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int A[n];
    int B[m];
    int sum_a = 0, sum_b = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum_a += A[i];
        mp[A[i]] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
        sum_b += B[i];
    }
    string ans = "No";
    int diff = sum_b - sum_a;
    if (diff % 2 == 0)
    {
        int d = diff / 2;
        for (int i = 0; i < m; i++)
        {
            if (mp[B[i] - d])
                ans = "Yes";
        }
    }
    cout << ans;
    return 0;
}