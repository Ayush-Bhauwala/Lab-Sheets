#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = (int *)malloc(sizeof(int) * 2 * n);
    int *ans = (int *)malloc(sizeof(int) * 2 * n);
    int maxIndex = -1;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans[i] = 0;
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        arr[i] = arr[i - n];
        ans[i] = 0;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < 2 * n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    stack<int> stk;
    for (int i = 0; i < 2 * n; i++)
    {
        int num = arr[i];
        while (!stk.empty() && num > arr[stk.top()])
        {
            ans[stk.top()] = i - stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (max == arr[i])
        {
            ans[i] = -1;
        }
        cout << ans[i] << ' ';
    }
    return 0;
}