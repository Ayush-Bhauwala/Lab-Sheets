#include <iostream>

using namespace std;

void freedomNodes(int *a, int length, int *ctr, int index, int x, int currSum)
{
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    if ((a[left] == -1 || !(left < length)) && (a[right] == -1 || !(right < length)))
    {
        // leaf node
        if (currSum == x)
            (*ctr)++;
    }
    else
    {
        if ((a[left] != -1 && (left < length)))
        {
            freedomNodes(a, length, ctr, left, x, currSum + a[left]);
        }
        if (!(a[right] == -1 || !(right < length)))
        {
            freedomNodes(a, length, ctr, right, x, currSum + a[right]);
        }
    }
}

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    freedomNodes(a, n, &count, 0, x, a[0]);
    cout << count;
    return 0;
}