#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int **queries = new int *[q];
    for (int i = 0; i < q; i++)
    {
        int left, right;
        cin >> left >> right;
        queries[i] = new int[2];
        queries[i][0] = left;
        queries[i][1] = right;
    }

    // printing queries
    // cout << "queries:\n";
    // for (int i = 0; i < q; i++)
    // {
    //     cout << queries[i][0] << " " << queries[i][1];
    // }
    // cout << "\n";
    int platesToLeft[n];
    int platesToRight[n];
    int count = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '|')
            count = total;
        else
            total++;
        platesToLeft[i] = count;
    }

    count = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '|')
            count = total;
        else
            total++;
        platesToRight[i] = count;
    }
    cout << "\n---\n";
    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        int ans = platesToRight[l] + platesToLeft[r] - total;
        if (ans < 0)
            ans = 0;
        cout << ans << "\n";
    }
    return 0;
}