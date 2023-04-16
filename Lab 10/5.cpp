#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> dolls(n);
    for (int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h;
        dolls.push_back({w, h});
    }
    return 0;
}