#include <iostream>
#include <stack>

using namespace std;

typedef struct
{
    int val;
    int index;
} node;

int main()
{
    int n;
    cin >> n;
    stack<node> st;
    int ans[2 * n];
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    node arr[2 * n];
    node max;
    max.val = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].val;
        arr[i].index = i;
        if (arr[i].val > max.val)
            max = arr[i];
    }
    for (int i = n; i < 2 * n; i++)
    {
        arr[i] = arr[i - n];
        arr[i].index = i;
    }
    for (int i = 0; i < 2 * n; i++)
    {
        node a = arr[i];
        while (!st.empty() && a.val > st.top().val)
        {
            ans[st.top().index] = i - st.top().index;
            st.pop();
        }
        st.push(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i].val == max.val)
            ans[i] = -1;
        cout << ans[i] << " ";
    }
    return 0;
}