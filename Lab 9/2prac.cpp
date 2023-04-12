#include <iostream>

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
        queries[i] = new int[2];
        cin >> queries[i][0] >> queries[i][1];
    }
    int count = 0;
    int total = 0;
    int toLeft[n];
    int toRight[n];
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '|')
            count = total;
        else
            total++;
        toLeft[i] = count;
    }
    count = 0;
    total = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '|')
            count = total;
        else
            total++;
        toRight[i] = count;
    }
    for (int i = 0; i < q; i++)
    {
        int left = queries[i][0];
        int right = queries[i][1];
        int ans = toRight[left] + toLeft[right] - total;
        cout << ans << " ";
    }
    return 0;
}