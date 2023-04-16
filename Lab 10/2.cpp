#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int mat[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int x;
    cin >> x;

    return 0;
}