#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int m, k, n;
    cin >> m >> k >> n;

    int p;
    cin >> p;
    unordered_map<int, unordered_map<int, int>> mat1;
    for (int i = 0; i < p; i++)
    {
        int row, col, ele;
        cin >> row >> col >> ele;
        mat1[row][col] = ele;
    }

    int q;
    cin >> q;
    unordered_map<int, unordered_map<int, int>> mat2;
    for (int i = 0; i < q; i++)
    {
        int row, col, ele;
        cin >> row >> col >> ele;
        mat2[row][col] = ele;
    }

    unordered_map<int, unordered_map<int, int>> mat3;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sum = 0;
            for (int l = 1; l <= k; l++)
            {
                if (mat1[i][l] && mat2[l][j])
                {
                    sum += mat1[i][l] * mat2[l][j];
                }
                if (sum != 0)
                {
                    mat3[i][j] = sum;
                }
            }
        }
    }

    int r = 0;
    for (auto row : mat3)
    {
        r += row.second.size();
    }
    cout << r << "\n";

    vector<pair<pair<int, int>, int>> non_zero;
    for (auto row : mat3)
    {
        for (auto ele : row.second)
        {
            if (ele.second != 0)
                non_zero.push_back({{row.first, ele.first}, ele.second});
        }
    }

    for (auto ele : non_zero)
    {
        cout << ele.first.first << ele.first.second << ele.second << "\n";
    }
}