#include <iostream>

using namespace std;

int search(int **arr, int i, int j, int x, int m, int n)
{
    if (i >= m)
    {
        return 0;
    }
    if (j >= n)
    {
        return 0;
    }
    if (x > arr[i][j])
    {
        return search(arr, i + 1, j, x, m, n) || search(arr, i, j + 1, x, m, n);
    }
    else if (x == arr[i][j])
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

    int ans = search(mat, 0, 0, x, m, n);
    if (ans)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}