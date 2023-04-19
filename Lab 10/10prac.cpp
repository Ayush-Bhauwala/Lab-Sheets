#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ksmallest(int **mat, int n, int k)
{
    auto cmp = [&](pair<int, int> a, pair<int, int> b)
    {
        return mat[a.first][a.second] > mat[b.first][b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        pq(cmp);

    for (int i = 0; i < n; i++)
    {
        pq.push({i, 0});
    }

    for (int i = 1; i < k; i++)
    {
        auto p = pq.top();
        pq.pop();
        if (p.second + 1 < n)
            pq.push({p.first, p.second + 1});
    }
    return mat[pq.top().first][pq.top().second];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << ksmallest(mat, n, k);
    return 0;
}