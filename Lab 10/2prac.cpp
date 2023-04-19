#include <iostream>

using namespace std;

int search(int **mat, int m, int n, int i, int j, int x)
{
    if (i >= m || j >= n)
        return 0;

    if (mat[i][j] < x)
        return search(mat, m, n, i + 1, j, x) || search(mat, m, n, i, j + 1, x);
    else if (mat[i][j] == x)
        return 1;
    else
        return 0;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **mat = new int *[m];
    for (int i = 0; i < m; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int x;
    cin >> x;
    int ans = search(mat, m, n, 0, 0, x);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}