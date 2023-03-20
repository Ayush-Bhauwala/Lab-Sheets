#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = (int *)malloc(sizeof(int) * n);
    int *S = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> stk;
    S[0] = 1;
    stk.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!stk.empty() && a[stk.top()] < a[i])
        {
            stk.pop();
        }
        S[i] = (stk.empty()) ? (i + 1) : (i - stk.top());
        stk.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << S[i] << " ";
    }
    return 0;
}