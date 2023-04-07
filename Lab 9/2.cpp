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
    for (int i = 0; i < q; i++)
    {
    }
    return 0;
}