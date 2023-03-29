#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int x;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int ele = q.top();
        int given = (ele + 1) / 2;
        count += given;
        ele -= given;
        q.pop();
        q.push(ele);
    }
    cout << count;
    return 0;
}