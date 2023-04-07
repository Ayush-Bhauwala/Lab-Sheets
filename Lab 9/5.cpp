#include <iostream>

using namespace std;

int main()
{
    int n, m, k, p, q;

    cin >> m >> k >> n;
    int **mat1 = new int *[3];
    int **mat2 = new int *[3];

    cin >> p;
    for (int i = 0; i < 3; i++)
    {
        mat1[i] = new int[p];
    }
    for (int l = 0; l < p; l++)
    {
        int i, j, val;
        cin >> i >> j >> val;
        mat1[0][l] = i;
        mat1[1][l] = j;
        mat1[2][l] = val;
    }

    cin >> q;
    for (int i = 0; i < 3; i++)
    {
        mat2[i] = new int[q];
    }
    for (int l = 0; l < q; l++)
    {
        int i, j, val;
        cin >> i >> j >> val;
        mat2[0][l] = i;
        mat2[1][l] = j;
        mat2[2][l] = val;
    }

    return 0;
}