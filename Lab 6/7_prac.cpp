#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);
    int *ans = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> stk;
    stk.push(0);
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        while (!stk.empty() && a[i] > a[stk.top()])
        {
            stk.pop();
        }
        ans[i] = stk.empty() ? i + 1 : i - stk.top();
        stk.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}