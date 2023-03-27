#include <iostream>

using namespace std;

void commonParent(int *a, int index_left, int index_right, int *index_ans)
{
    if (index_left == index_right)
    {
        *index_ans = index_left;
        return;
    }
    else if (index_left > index_right)
        commonParent(a, (index_left - 1) / 2, index_right, index_ans);
    else
        commonParent(a, index_left, (index_right - 1) / 2, index_ans);
}

int main()
{
    int n, x, y;
    cin >> n;
    cin >> x;
    cin >> y;
    int index_left = -1;
    int index_right = -1;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == x)
        {
            index_left = i;
        }
        if (a[i] == y)
        {
            index_right = i;
        }
    }
    int index_ans = -1;
    commonParent(a, index_left, index_right, &index_ans);
    cout << "\n";
    cout << a[index_ans];
    return 0;
}