#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    priority_queue<int> q1;
    priority_queue<int> q2;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q1.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q2.push(x);
    }

    int max1 = q1.top();
    int max2 = q2.top();
    q1.pop();
    q2.pop();

    cout << max1 + max2 << " ";

    for (int i = 0; i < k - 1; i++)
    {
        if (q1.top() + max2 > q2.top() + max1)
        {
            cout << q1.top() + max2 << " ";
            q1.pop();
        }
        else
        {
            cout << q2.top() + max1 << " ";
            q2.pop();
        }
    }

    return 0;
}